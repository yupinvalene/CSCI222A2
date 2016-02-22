/*
 * MembershipBuilder.cpp
 *
 *  Created on: 18 Feb 2016
 *      Author: yupin
 */

#include "MembershipBuilder.h"

MembershipBuilder::MembershipBuilder() {
}

MembershipBuilder::MembershipBuilder(vector<Membership> vectorOfMembership) {
	this -> vectorOfMembership = vectorOfMembership;
}

MembershipBuilder::~MembershipBuilder() {
}

vector<Membership> MembershipBuilder::getVectorOfMembership() {
	return vectorOfMembership;
}

void MembershipBuilder::setVectorOfMembership(vector<Membership> vectorOfMembership) {
	this -> vectorOfMembership = vectorOfMembership;
}

void MembershipBuilder::buildMembership(string membershipID,
		string rank, double membershipFee, vector<string> vectorOfAccessRight) {
	Membership membership;
	membership.setMembershipID(membershipID);
	membership.setRank(rank);
	membership.setMembershipFee(membershipFee);
	membership.setAccessRight(vectorOfAccessRight);
	vectorOfMembership.push_back(membership);
}

bool MembershipBuilder::readFile() {
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

	string id, rank;
	double fee;
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
		vector<string> accessRight;

		if(n == 4)
		{
			n = 0;
		}
	   switch(n)
	   {
		   case 0: id = linesplit[i]; break;
		   case 1: rank = linesplit[i]; break;
		   case 2: fee = atof(linesplit[i].c_str()); break;
		   case 3:
			   while ((pos = linesplit[i].find(delimiter)) != string::npos) // split the data string by \n delimiter
			   	{
			   		line = linesplit[i].substr(0, pos2);
			   		split(line, ':', accessRight);
			   		linesplit[i].erase(0, pos2 + delimiter.length());
			   	}

			   	   break;
	   }
	   if(n == 3)
	   {
		   Membership membership(id, rank, fee, accessRight);
		   vectorOfMembership.push_back(membership);

	   }
	   n++;
	}
	datafile.close();
	return true;
}

bool MembershipBuilder::writeFile() {
	ostringstream oss;

		for(int i = 0; i < vectorOfMembership.size(); i++)
		{
			string rank = vectorOfMembership[i].getRank();
			string membershipID = vectorOfMembership[i].getMembershipID();
			double fee = vectorOfMembership[i].getMembershipFee();
			vector<string> accessRight = vectorOfMembership[i].getAccessRight();

			oss << membershipID << "," << rank << "," << fee << ",";

			for(int n = 0; n < accessRight.size(); n++)
			{
				if(n + 1 == accessRight.size())
				{
					oss << accessRight[n];

				}
				else
				{
					oss << accessRight[n] << ":";


				}
			}

			oss << "\n";
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

void MembershipBuilder::setFilename(char* fileName)
{
	this -> fileName = fileName;
}


void MembershipBuilder::printMembership(string membershipID) {
	for(int i = 0; i < vectorOfMembership.size(); i++){
		if(membershipID.compare(vectorOfMembership[i].getMembershipID()) == 0){
			cout << "MemberID: " << vectorOfMembership[i].getMembershipID()
				 << "Rank: " << vectorOfMembership[i].getRank()
				 << "Fee: $" << vectorOfMembership[i].getMembershipFee();
		}
	}
}

void MembershipBuilder::printAllMemberships()
{
	cout << endl;

	for(int i = 0; i < vectorOfMembership.size(); i++){

		cout << "MemberID: " << vectorOfMembership[i].getMembershipID() << endl
			 << "Rank: " << vectorOfMembership[i].getRank() << endl
			 << "Fee: $" << vectorOfMembership[i].getMembershipFee()
			 << endl << endl;
	}

	cout << endl;
}

bool MembershipBuilder::getMembership(string membershipID, Membership &membership)
{
	for(int i = 0; i < vectorOfMembership.size(); i++){
		if(membershipID.compare(vectorOfMembership[i].getMembershipID()) == 0){
			membership = vectorOfMembership[i];
			return true;
		}
	}

	return false;

}


void MembershipBuilder::amendMembership(string membershipID, string rank,double fee, vector<string> accessRight) {

	for(int i = 0; i < vectorOfMembership.size(); i++){
		if(membershipID.compare(vectorOfMembership[i].getMembershipID()) == 0){
			if(rank.compare(vectorOfMembership[i].getRank()) == 0){
				vectorOfMembership[i].setRank(rank);
			}
			else if(fee == vectorOfMembership[i].getMembershipFee()){
				vectorOfMembership[i].setMembershipFee(fee);
				vectorOfMembership[i].setAccessRight(accessRight);
			}

		}

	}
}

vector<string> MembershipBuilder::split(const string &s, char delim, vector<string> &linesplit)
{
	stringstream ss(s);
	string item;
	while(getline(ss, item, delim))
	{
		linesplit.push_back(item);
	}
	return linesplit;
}
