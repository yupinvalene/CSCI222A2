/*
 * MemberHandler.h
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#ifndef MEMBERHANDLER_H_
#define MEMBERHANDLER_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "Member.h"
#include "MembershipBuilder.h"
#include "UIDGenerator.h"

using namespace std;

class MemberHandler{

	public:
	MemberHandler();
	MemberHandler(vector<Member>);
	~MemberHandler();

	//accessor
	vector<Member> getVectorOfMember();
	
	//mutator
	void setVectorOfMember(vector<Member>);
	
	//function
	void setFilename(char*);
	bool readData();
	bool writeData();
	void addMember(string, string, string, string, string, string,string, Membership);
	void deleteMember(string);
	Member findMember(string);
	void updateMember(string, string, string, string, string, string, string, string);
	vector<Notification> getMemberNotification(string);
	void updateMembership(string, float, string, vector<string>, Membership);
	void pushNotification(string, Notification);
	
	
	private:
	vector<Member> vectorOfMember;
	char* fileName;
	vector<string> split(const string &s, char delim, vector<string> &linesplit);

	MembershipBuilder mb;

};



#endif /* MEMBERHANDLER_H_ */
