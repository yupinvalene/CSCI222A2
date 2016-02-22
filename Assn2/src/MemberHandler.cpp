/*
 * MemberHandler.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#include "MemberHandler.h"

MemberHandler::MemberHandler() {
	mb.setFilename("membershipDatabase.txt");
	mb.readFile();
}

MemberHandler::MemberHandler(vector<Member> vectorOfMember) {
	this -> vectorOfMember = vectorOfMember;
}

MemberHandler::~MemberHandler() {
}

vector<Member> MemberHandler::getVectorOfMember() {
	return vectorOfMember;
}


void MemberHandler::setVectorOfMember(vector<Member> vectorOfMember) {
	this -> vectorOfMember = vectorOfMember;
}

void MemberHandler::setFilename(char* fileName)
{
	this -> fileName = fileName;
}

bool MemberHandler::readData() {
	string data;
	ifstream datafile;
	datafile.open(fileName, ifstream::in);

	if(!datafile)
	{
		cout << fileName
			 << " opened failed!!"
			 << endl;

		exit(-1);
	}

	getline(datafile, data, '\0'); // read the whole text file as string

	string delimiter = "\n";
	char delim = ',';
	size_t pos = 0;
	size_t pos2 = 0;
	string line;

	string id;
	string name;
	string add;
	string pw;
	string email;
	string contact;
	string dob;
	string creditCardNo;
	string membershipID;
	vector<string> linesplit;

	while ((pos = data.find(delimiter)) != string::npos) // split the data string by \n delimiter
	{
		line = data.substr(0, pos);
		split(line, delim, linesplit);
		data.erase(0, pos + delimiter.length());
	}
	int n = 0;
	for(int i = 0; i < linesplit.size(); i++)
	{
		if(n == 7)
		{
			n = 0;
		}
	   switch(n)
	   {
		   case 0: id = linesplit[i]; break;
		   case 1: name = linesplit[i]; break;
		   case 2: add = linesplit[i]; break;
		   case 3: pw = linesplit[i]; break;
		   case 4: email = linesplit[i]; break;
		   case 5: contact = linesplit[i]; break;
		   case 6: dob = linesplit[i]; break;
		   case 7: creditCardNo = linesplit[i]; break;
		   case 8: membershipID = linesplit[i]; break;
	   }
	   if(n == 8)
	   {
		   Membership m;
		   if(mb.getMembership(id, m))
		   {
			   Member member(name, add, id, pw, email, contact, dob, creditCardNo, m);
			   vectorOfMember.push_back(member);
		   }
		   else {
			   cout << "Membership ID not found!" << endl;
		   }
	   }
	   n++;
	}
	datafile.close();
	return true;
}

bool MemberHandler::writeData() {

	ostringstream oss;

	for(int i = 0; i < vectorOfMember.size(); i++)
	{
		string id = vectorOfMember[i].getMemberID();
		string name = vectorOfMember[i].getName();
		string add = vectorOfMember[i].getAddress();
		string pw = vectorOfMember[i].getPassword();
		string email = vectorOfMember[i].getEmail();
		string contact = vectorOfMember[i].getContact();
		string dob = vectorOfMember[i].getDOB();
		string creditCardNo = vectorOfMember[i].getCreditCardNo();
		string membershipID = vectorOfMember[i].getMembership().getMembershipID();

		oss << id << "," << name << "," << add << "," << pw << "," << email << "," << contact << "," << dob << "," << creditCardNo << "," << membershipID << "\n";
	}

	string info = oss.str();

	ofstream outfile;
	outfile.open(fileName, ios::out | ios::trunc);

	if(!outfile)
	{
		cout << fileName
			 << " opened for writing failed!!"
			 << endl;

		exit(-1);
	}

	outfile << info;
	outfile.close();

	return true;
}

void MemberHandler::addMember(string name, string address,
		string password, string email, string contact,
		string dob, string ccNo, Membership membership) {

	Member member;
	string uid = UIDGenerator::generate();
	member.setMemberID(uid);
	member.setName(name);
	member.setAddress(address);
	member.setPassword(password);
	member.setEmail(email);
	member.setContact(contact);
	member.setDOB(dob);
	member.setMembership(membership);
	member.setCreditCardNo(ccNo);

	vectorOfMember.push_back(member);
}

void MemberHandler::deleteMember(string memberID) {
	bool found = false;
	for(int i = 0; i < vectorOfMember.size(); i++){
		if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
			vectorOfMember.erase(vectorOfMember.begin()+i);
			cout << memberID << " is being removed.";
			found = true;
		}
	}
	if(found == false){
		cout << memberID << " doesnt exist";
	}

}

Member MemberHandler::findMember(string memberID) {
	for(int i = 0; i < vectorOfMember.size(); i++){
			if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
				return vectorOfMember[i];
			}
	}
}

void MemberHandler::updateMember(string memberID,
		string name, string address, string password,
		string email, string contact, string dob, string creditCardNo) {
//	for(int i = 0; i < vectorOfMember.size(); i++){
//
//			if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
//				if(name.compare(vectorOfMember[i].getName() == 0){
//					vectorOfMember[i].setName(name);
//				}
//				else if(address.compare(vectorOfMember[i].getAddress() == 0){
//					vectorOfMember[i].setAddress(address);
//				}
//				else if(password.compare(vectorOfMember[i].getPassword() == 0){
//					vectorOfMember[i].setPassword(password);
//				}
//				else if(email.compare(vectorOfMember[i].getEmail() == 0){
//					vectorOfMember[i].setEmail(email);
//				}
//				else if(contact.compare(vectorOfMember[i].getContact() == 0){
//					vectorOfMember[i].setContact(contact);
//				}
//				else if(dob.compare(vectorOfMember[i].getDOB() == 0){
//					vectorOfMember[i].setDOB(dob);
//				}
//				else if(creditCardNo.compare(vectorOfMember[i].getCreditCardNo() == 0){
//					vectorOfMember[i].setCreditCardNo(creditCardNo);
//				}
//			}
//
//	}

}

vector<Notification> MemberHandler::getMemberNotification(string memberID) {
	for(int i = 0; i < vectorOfMember.size(); i++){
		if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
			return vectorOfMember[i].getNotification();
		}
	}
}

void MemberHandler::updateMembership(string memberID, float fee, string rank, vector<string> accessRight, Membership membership) {
	for(int i = 0; i < vectorOfMember.size(); i++){
		if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
			membership.setRank(rank);
			membership.setAccessRight(accessRight);
			membership.setMembershipFee(fee);
		}
	}

}

void MemberHandler::pushNotification(string memberID, Notification vectorOfNotification) {

}

vector<string> MemberHandler::split(const string &s, char delim, vector<string> &linesplit)
{
	stringstream ss(s);
	string item;
	while(getline(ss, item, delim))
	{
		linesplit.push_back(item);
	}
	return linesplit;
}


