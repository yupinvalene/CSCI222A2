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
	memberHandler.setFilename("memberDatabase");
	membershipBuilder.setFilename("membershipDatabase");
}

ClubFacilitiesBookingSystem::~ClubFacilitiesBookingSystem()
{

}

void ClubFacilitiesBookingSystem::run()
{
	cout << "Welcome to the Club Facility Booking System" << endl
		 << "=============================================" << endl;

	displayManagerMenu();

	cout << "pass";

	facilityHandler.readData();


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
			case 'e':
			case 'f':
			case 'g':
			case 'h':
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
	ostringstream ss;

	cout << "Create Club Member" << endl
		 << "===================" << endl
		 << endl;

	cout << "Enter Name: ";
	cin.ignore();

	getline(cin, name);

	cout << "Enter Identification Number: ";
	cin.ignore();

	getline(cin, memberID);

	cout << "Enter Day of Birth: ";
	cin.ignore();

	cin >> day;

	cout << "Enter Month of Birth: ";
	cin.ignore();

	cin >> month;

	cout << "Enter Year of Birth: ";
	cin.ignore();

	cin >> year;

	cout << "Enter Address: ";
	cin.ignore();

	getline(cin, address);

	cout << "Enter Email: ";
	cin.ignore();

	getline(cin, email);

	cout << "Enter Contact Number: ";
	cin.ignore();

	getline(cin, contact);

	cout << "Enter Credit Card Number: ";
	cin.ignore();
	getline(cin, creditCardNo);

	ss << day;

	if(ss.str().length() < 2)
	{
		dob = "0" + ss.str();
	}
	else
	{
		dob = ss.str();
	}

	ss.clear();

	ss << month;

	if(ss.str().length() < 2)
	{
		dob = "0" + ss.str();
	}
	else
	{
		dob.append(ss.str());
	}

	ss.clear();

	ss << year;

	dob.append(ss.str());

	membershipBuilder.printAllMemberships();

	Membership membership;

	do
	{
		cout << "Please enter the membership ID of the membership you desired: ";

		getline(cin, membershipID);
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

	memberHandler.addMember(name, address, password, email, contact, dob, membership);

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

	cout << "Enter Facility Name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Enter Facility Address: ";
	cin.ignore();
	getline(cin, address);

	cout << "Enter Start Time: ";
	cin.ignore();
	cin >> operationStartTime;

	cout << "Enter End Time: ";
	cin.ignore();
	cin >> operentaionEndTime;

	cout << "Is it available for booking?(y/n): ";
	cin.ignore();
	cin >> available;

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
		cout << name << " added successfully!" << endl << endl;
	}
	else
	{
		cout << name << " add fail!" << endl << endl;
	}

	return;
}

void ClubFacilitiesBookingSystem::createClubMembership()
{
	string membershipID;
	string rank;
	float membershipFee;
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
	cin.ignore();

	getline(cin, membershipID);


	cout << "Enter Membership Fee: ";
	cin.ignore();

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

	if(facilityHandler.writeData())
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

	cout << "Enter Service Name: ";
	cin.ignore();

	getline(cin, name);

	cout << "Enter Service Name: ";
	cin.ignore();

	getline(cin, name);

	cout << "Enter Hourly Rate: ";
	cin.ignore();

	cin >> fee;

	cout << "Enter Start Time: ";
	cin.ignore();

	cin >> operationStartTime;

	cout << "Enter End Time: ";
	cin.ignore();

	cin >> operentaionEndTime;

	cout << "Is it available for booking?(y/n): ";
	cin.ignore();

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
