/*

Dear students,



I have been approached by some of you seeking to clarify if there is a need to IMPLEMENT your system.



As explained during my intro to Assn 1 & 2,



Assn 1 - Design your system



Assn 2 - Design your system + Implement !!



==================================



Your final implemented system should have the following :




Key functionalities of CCFBS ...
================================



1) Support CREATE, SEARCH, UPDATE, DELETE of:

 a) Club Members (with editing of membership type/ranking)
 b) Club Facilities


2) Support BOOKING of Club Facilities



3) Generate REPORTS:

 a) monthly usage (bookings) of facilities
 b) rental behavoir (which members book which facilities frequently?)
 c) discount rates given to each member



4) Basic Error Checking (e.g. prevent members from booking facilities which has already been booked, etc)



-----------------------------------------------------

Team Leaders :



If your team is still unsure, please approach me during Lecture tomorrow. You can clarify your doubts on the spot.





Rdgs,

Mr Tian

*/

#include "ClubFacilitiesBookingSystem.h"

ClubFacilitiesBookingSystem::ClubFacilitiesBookingSystem()
{
	memberHandler.setFilename("memberDatabase.txt");
	memberHandler.readData();
	membershipBuilder.setFilename("membershipDatabase.txt");
	membershipBuilder.readFile();
	facilityHandler.readData();
	serviceHandler.readData();
}

ClubFacilitiesBookingSystem::~ClubFacilitiesBookingSystem()
{

}

void ClubFacilitiesBookingSystem::run()
{
	cout << "Welcome to the Club Facility Booking System" << endl
		 << "=============================================" << endl;

	displayManagerMenu();


}

void ClubFacilitiesBookingSystem::displayMemberMenu()
{
	char choice = 'g';

	do
	{
		cout << "a. Book Club Facilities" << endl
			 << "b. Book Club Services" << endl
			 << "c. View Booking History" << endl
			 << "d. Your Profile" << endl
			 << "e. Membership" << endl
			 << "f. View Notifications" << endl
			 << "g. Exit" << endl << endl;

		cout << "Your choice: ";

		cin >> choice;

		switch(choice)
		{
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g': exit(-1);
			default: cout << "Invalid input!" << endl << endl; break;
		}
	}
	while(choice != 'g');
}

void ClubFacilitiesBookingSystem::displayManagerMenu()
{
	char choice = 'g';

	do
	{
		cout << "a. Create Club Facilities" << endl
			 << "b. Create Club Member" << endl
			 << "c. Create Membership" << endl
			 << "d. Create Club Services" << endl
			 << "e. Search Club Facilities" << endl
			 << "f. Search Club Member" << endl
			 << "g. Update Club Facilities" << endl
			 << "h. Update Club Member" << endl
			 << "i. Update Membership" << endl
			 << "j. Delete Club Facilities" << endl
			 << "k. Delete Club Member" << endl
			 << "l. Delete Membership" << endl
			 << "m. Generate Report" << endl
			 << "n. Send Notification" << endl
			 << "o. Exit" << endl;

		cout << "Your choice: ";

		cin >> choice;

		switch(choice)
		{
			case 'a': createClubFacility(); break;
			case 'b': createClubMember(); break;
			case 'c': createClubMembership(); break;
			case 'd': createClubService(); break;
			case 'e': searchClubFacilities(); break;
			case 'f': searchClubMember(); break;
			case 'g': updateClubFacilities(); break;
			case 'h': updateClubMember(); break;
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o': exit(-1);
			default: cout << "Invalid input!" << endl << endl; break;
		}
	}
	while(choice != 'n');
}

void ClubFacilitiesBookingSystem::createClubMember()
{
	string name;
	string address;
	string memberID;
	string tempPw;
	string password;
	string email;
	string contact;
	string creditCardNo;
	string dob;
	string membershipID;
	int month = 0;
	int year = 0;
	int day = 0;
	ostringstream daySS, monthSS, yearSS;

	cout << "Create Club Member" << endl
		 << "===================" << endl
		 << endl;

	cout << "Enter Name: ";
	cin.ignore();

	getline(cin, name);

	cout << "Enter Identification Number: ";

	getline(cin, memberID);

	cout << "Enter Day of Birth: ";
	cin >> day;

	cout << "Enter Month of Birth: ";

	cin >> month;

	cout << "Enter Year of Birth: ";

	cin >> year;

	cout << "Enter Address: ";
	cin.ignore();

	getline(cin, address);

	cout << "Enter Email: ";

	getline(cin, email);

	cout << "Enter Contact Number: ";

	getline(cin, contact);

	cout << "Enter Credit Card Number: ";
	getline(cin, creditCardNo);

	daySS << day;

	if(daySS.str().length() < 2)
	{
		dob = "0" + daySS.str();
	}
	else
	{
		dob = daySS.str();
	}

	monthSS << month;

	if(monthSS.str().length() < 2)
	{
		dob.append("0" + monthSS.str());
	}
	else
	{
		dob.append(monthSS.str());
	}

	yearSS << year;

	dob.append(yearSS.str());

	membershipBuilder.printAllMemberships();

	Membership membership;

	do
	{
		cout << "Please enter the membership ID of the membership you desired: ";
		getline(cin, membershipID);
		cout << membershipID;
	}
	while(!membershipBuilder.getMembership(membershipID, membership));

	do
	{
		cout << "Enter Password: ";
		getline(cin, tempPw);

		cout << "Enter password again: ";
		getline(cin, password);

		if(password.compare(tempPw) != 0)
		{
			cout << "Password does not match! Please enter again!" << endl << endl;
		}
	}
	while(password.compare(tempPw) != 0);

	memberHandler.addMember(name, address, password, email, contact, dob, creditCardNo, membership);

	if(memberHandler.writeData())
	{
		cout << name << " added successfully!" << endl << endl;
	}
	else
	{
		cout << name << " add fail!" << endl << endl;
	}

	return;

}

void ClubFacilitiesBookingSystem::createClubFacility()
{
	string name;
	string address;
	long operationStartTime;
	long operentaionEndTime;
	char available;
	bool isAvailable;

	cout << "Create Club Facility" << endl
		 << "====================" << endl
		 << endl;

	cin.get();

	cout << "Enter Facility Name: ";
	getline(cin, name);

	cout << "Enter Facility Address: ";
	getline(cin, address);

	cout << "Enter Start Time: ";
	cin >> operationStartTime;
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Enter End Time: ";
	cin >> operentaionEndTime;
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Is it available for booking?(y/n): ";
	cin >> available;
	cin.clear();
	cin.ignore(100, '\n');

	if(available == 'y')
	{
		isAvailable = true;
	}
	else
	{
		isAvailable = false;
	}

	facilityHandler.addFacility(name, address, operationStartTime, operentaionEndTime, isAvailable);

	if(facilityHandler.writeData())
	{
		cout << "Facility added successfully!" << endl << endl;
	}
	else
	{
		cout << "Facility add fail!" << endl << endl;
	}

	return;
}

void ClubFacilitiesBookingSystem::createClubMembership()
{
	string membershipID;
	string rank;
	double membershipFee;
	string temp;
	vector<string> accessRight;
	char delim = ',';

	cout << "Create Club Membership" << endl
		 << "======================" << endl
		 << endl;

	cout << "Enter Membership ID: ";
	cin.ignore();
	getline(cin, membershipID);

	cout << "Enter rank: ";

	getline(cin, rank);


	cout << "Enter Membership Fee: ";

	cin >> membershipFee;

	facilityHandler.viewAllFacility();

	cout << endl
		 << "Specify the access right of membership by inputting the facility id." << endl
		 << "Multiple id can be entered and delimited by ',', for e.g., 12532456,75335632,24563224"
		 << endl
		 << endl;

	cout << "Enter Facilities ID: ";
	cin.ignore();

	getline(cin, temp);

	split(temp, delim, accessRight);

	membershipBuilder.buildMembership(membershipID, rank, membershipFee, accessRight);

	if(membershipBuilder.writeFile())
	{
		cout << rank << " added successfully!" << endl << endl;
	}
	else
	{
		cout << rank << " add fail!" << endl << endl;
	}

	return;
}

void ClubFacilitiesBookingSystem::createClubService()
{
	string name;
	float fee;
	long operationStartTime;
	long operentaionEndTime;
	char available;
	bool isAvailable;

	cout << "Create Club Service" << endl
		 << "======================" << endl
	 	 << endl;
	cin.ignore();

	cout << "Enter Service Name: ";
	getline(cin, name);

	cout << "Enter Hourly Rate: ";
	cin >> fee;

	cout << "Enter Start Time: ";

	cin >> operationStartTime;

	cout << "Enter End Time: ";

	cin >> operentaionEndTime;

	cout << "Is it available for booking?(y/n): ";

	cin >> available;

	if(available == 'y')
	{
		isAvailable = true;
	}
	else
	{
		isAvailable = false;
	}

	serviceHandler.addService(name, fee, operationStartTime, operentaionEndTime, isAvailable);

	if(serviceHandler.writeData())
	{
		cout << name << " added successfully!" << endl << endl;
	}
	else
	{
		cout << name << " add fail!" << endl << endl;
	}

	return;
}

void ClubFacilitiesBookingSystem::searchClubFacilities(){

	string faciName;
	string faciID;
	vector<Facility> vectorOfFacilities;

	cout << "Search Club Facility" << endl
		 << "======================" << endl
	 	 << endl;

	cout << "Enter Facility Name: ";
	cin.ignore();
	getline(cin, faciName);


//	cout << "Search Club Facilities" << endl
//		 << "======================" << endl
//	 	 << endl;
//
////	cout << "Please enter name of facility: ";
////	cin.ignore();
////	getline(cin, faciName);
//
//	cout << faciName;

//	if(facilityHandler.readData())
//	{
		vectorOfFacilities = facilityHandler.getVectorOfFacilities();
		for(int i = 0; i < vectorOfFacilities.size(); i++){
			if(vectorOfFacilities[i].getFacName() == faciName){
				cout << "Facility ID: " << vectorOfFacilities[i].getFacID() << endl
					 << "Facility name: " << faciName << endl
					 << "Facility address: " << vectorOfFacilities[i].getFacAddress() << endl
					 << "Facility start time: " << vectorOfFacilities[i].getFacOperationStartTime() << endl
					 << "Facility end time: " << vectorOfFacilities[i].getFacOperationEndTime() << endl << endl;
			}
		}
//	}
//	else
//	{
//		cout << "search failed." << endl << endl;
//	}
}

void ClubFacilitiesBookingSystem::searchClubMember()
{
    string memName;
    bool found = 0;
	vector<Member> vectMembers;

	cout << "Search Club Members" << endl
		 << "======================" << endl
	 	 << endl;

	cout << "Enter Member's Name: ";
	cin.ignore();
	getline(cin, memName);

	vectMembers = memberHandler.getVectorOfMember();

	for(int i = 0; i < vectMembers.size(); i++)
    {
        if(vectMembers[i].getName() == memName)
        {
            cout << "Member's ID: " << vectMembers[i].getMemberID() << endl
                 << "Member's name: " << memName << endl
                 << "Member's address: " << vectMembers[i].getAddress() << endl
                 << "Member's password: " << vectMembers[i].getPassword() << endl
                 << "Member's email: " << vectMembers[i].getEmail() << endl
                 << "Member's contact: " << vectMembers[i].getContact() << endl
                 << "Member's email: " << vectMembers[i].getEmail() << endl
                 << "Member's date of birth: " << vectMembers[i].getDOB() << endl
                 << "Member's credit card no.: " << vectMembers[i].getCreditCardNo() << endl;
                 Membership ms = vectMembers[i].getMembership();
                 ms.toString();
                 found = 1;
        }
    }
    if(found == 0)
    {
        cout << "Member not found" << endl;
    }
}

void ClubFacilitiesBookingSystem::updateClubFacilities()
{
    string facID;
    int choice;
    bool found = 0;
	vector<Facility> vectFac;

	cout << "Update Club Facilities" << endl
		 << "======================" << endl
	 	 << endl;

	cout << "Enter Facility ID: ";
	cin.ignore();
	getline(cin, facID);

	vectFac = facilityHandler.getVectorOfFacilities();
	//for testing purposes
	//long st = 1200;
	//long et = 1900;
	//Facility f("123", "Name", "#address", st, et, 1);
	//vectFac.push_back(f);
	//for testing purposes
    string input;
    long input2;
    int input3;

	for(int i = 0; i < vectFac.size(); i++)
    {
        if(vectFac[i].getFacID() == facID)
        {
            found = 1;
            cout << "Update Options" << endl
                 << "======================" << endl;
            cout << "1) Change name of facility" << endl
                 << "2) Change address of facility" << endl
                 << "3) Change operation start time of facility" << endl
                 << "4) Change operation end time of facility" << endl
                 << "5) Change availability of facility" << endl
                 << "6) exit" << endl
                 << "Your choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1: cout << "Enter new facility name: "; cin.ignore(); getline(cin, input);
                            vectFac[i].setFacName(input); cout << "Facility's name changed\n\n"; break;
                    case 2: cout << "Enter new address name: "; cin.ignore(); getline(cin, input);
                            vectFac[i].setFacAddress(input); cout << "Facility's address changed\n\n"; break;
                    case 3: cout << "Enter new Operation start time: "; cin >> input2;
                            vectFac[i].setFacOperationStartTime(input2); cout << "Facility's start time changed\n\n"; break;
                    case 4: cout << "Enter new Operation end time: "; cin >> input2;
                            vectFac[i].setFacOperationEndTime(input2); cout << "Facility's end time changed\n\n"; break;
                    case 5: cout << "Enter availability (1 or 0): "; cin >> input3;
                            vectFac[i].setAvailable(input3); cout << "Facility's availability changed\n\n"; break;
                    case 6: cout << "Going back to main menu\n" << endl; displayManagerMenu(); break;

                    default: cout << "Please enter choices 1 to 6\n" << endl; updateClubFacilities();
                }
                facilityHandler.setVectorOfFacilities(vectFac);
                facilityHandler.writeData();
        }
    }
    if(found == 0)
    {
        cout << "Facility not found\n" << endl;
    }
}

void ClubFacilitiesBookingSystem::updateClubMember()
{
    string memID;
    int choice, c2;
    bool found = 0;
    float mfee;
	vector<Member> vectMem;

	cout << "Update Club Member" << endl
		 << "======================" << endl
	 	 << endl;

	cout << "Enter Member's ID: ";
	cin.ignore();
	getline(cin, memID);

	vectMem = memberHandler.getVectorOfMember();
	//for testing purposes
	//float fee = 12.50;
	//vector<string> testvect;
	//Membership ms("mID", "rank", fee, testvect);
	//Member m("Louis", "#add", "pass", "123", "email", "932131", "12-12-12", "1231231", ms);
	//vectMem.push_back(m);
	//for testing purposes
    string input;

	for(int i = 0; i < vectMem.size(); i++)
    {
        if(vectMem[i].getMemberID() == memID)
        {
            found = 1;
            cout << "Update Options" << endl
                 << "======================" << endl;
            cout << "1) Change name of member" << endl
                 << "2) Change address of member" << endl
                 << "3) Change password of member" << endl
                 << "4) Change email of member" << endl
                 << "5) Change contact of member" << endl
                 << "6) Change Date of Birth of member" << endl
                 << "7) Change Credit Card No. of member" << endl
                 << "8) Change Membership info of member" << endl
                 << "9) exit" << endl
                 << "Your choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1: cout << "Enter new member's name: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setName(input); cout << "Member's name changed\n\n"; break;
                    case 2: cout << "Enter new address: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setAddress(input); cout << "Member's address changed\n\n"; break;
                    case 3: cout << "Enter new password: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setPassword(input); cout << "Member's password changed\n\n"; break;
                    case 4: cout << "Enter new email: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setEmail(input); cout << "Member's email changed\n\n"; break;
                    case 5: cout << "Enter new contact no.: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setContact(input); cout << "Member's contact changed\n\n"; break;
                    case 6: cout << "Enter new Date of birth: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setDOB(input); cout << "Member's Date of Birth changed\n\n"; break;
                    case 7: cout << "Enter new credit card no.: "; cin.ignore(); getline(cin, input);
                            vectMem[i].setCreditCardNo(input); cout << "Member's credit card no changed\n\n"; break;
                    case 8: cout << "Choose what information to change" << endl
                                 << "==================================" << endl
                                 << "1) Rank\n"
                                 << "2) Membership fees\n"
                                 << "3) Access Rights\n"
                                 << "Enter Choice: ";
                                    cin >> c2;
                                    if(c2 == 1)
                                    {
                                        Membership mbs = vectMem[i].getMembership();
                                        cout << "Enter new rank: "; cin.ignore(); getline(cin, input);
                                        mbs.setRank(input);
                                        cout << "Member's rank changed\n\n";
                                    }
                                    else if(c2 == 2)
                                    {
                                        Membership mbs = vectMem[i].getMembership();
                                        cout << "Enter new Fee: "; cin >> mfee;
                                        mbs.setMembershipFee(mfee);
                                        cout << "Member's Membership fee changed\n\n";
                                    }
                                    else if(c2 == 3)
                                    {
                                        Membership mbs = vectMem[i].getMembership();
                                        vector<string> ars;
                                        bool cont = 1;
                                        char yn;
                                        while(cont = 1)
                                        {
                                            cout << "Enter new access rights: "; cin.ignore(); getline(cin, input);
                                            ars.push_back(input);
                                            cout << "Add more access rights? (Y/N): "; cin >> yn;
                                            if(yn == 'Y' || yn == 'y')
                                            {
                                                cont = 1;
                                            }
                                            else if(yn == 'N' || yn == 'n')
                                            {
                                                cont = 0;
                                            }
                                        }
                                        mbs.setAccessRight(ars);
                                        cout << "Member's Access rights changed\n\n";
                                    }
                                    else
                                    {
                                        cout << "Please enter choices 1 to 3\n" << endl; updateClubMember();
                                    }
                            break;
                    case 9: cout << "Going back to main menu\n" << endl; displayManagerMenu(); break;

                    default: cout << "Please enter choices 1 to 9\n" << endl; updateClubMember();
                }
                // Have to write data. Need memberhandler's writeData codes
                memberHandler.setVectorOfMember(vectMem);
                memberHandler.writeData();
        }
    }
    if(found == 0)
    {
        cout << "Member not found\n" << endl;
    }
}

vector<string> ClubFacilitiesBookingSystem::split(const string &s, char delim, vector<string> &linesplit)
{
	stringstream ss(s);
	string item;
	while(getline(ss, item, delim))
	{
		linesplit.push_back(item);
	}
	return linesplit;
}

int main()
{
	ClubFacilitiesBookingSystem cfbs;
	cfbs.run();

	return 0;

}
