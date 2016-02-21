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

#include "Member.h"

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
	void setFilename(string);
	bool readData();
	bool writeData();
	void addMember(string, string, string, string, string, string, Membership);
	void deleteMember(string);
	Member findMember(string);
	void updateMember(string, string, string, string, string, string, string, string);
	vector<Notification> getMemberNotification(string);
	void updateMembership(string, float, string, vector<string>, Membership);
	void pushNotification(string, Notification);
	
	
	private:
	vector<Member> vectorOfMember;
	string fileName;
};



#endif /* MEMBERHANDLER_H_ */
