/*
 * Member.h
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

#include "Notification.h"
#include "Membership.h"
//#include "MembershipBuilder.h"


using namespace std;

class Member{
	public:
		Member();
		Member(string, string, string, string, string, string, string, Membership);
		~Member();
		
		//accessor
		string getName();
		string getAddress();
		string getMemberID();
		string getPassword();
		string getEmail();
		string getContact();
		string getDOB();
		string getCreditCardNo();
		Membership getMembership();
		vector<Notification> getNotification();

		//mutator
		void setName(string);
		void setAddress(string);
		void setMemberID(string);
		void setPassword(string);
		void setEmail(string);
		void setContact(string);
		void setDOB(string);
		void setCreditCardNo(string);
		void setNotification(vector<Notification>);
		void setMembership(Membership);


	private:
		string name;
		string address;
		string memberID;
		string password;
		string email;
		string contact;
		string dob;
		string creditCardNo;
		Membership membership;
		vector<Notification> vectorOfNotification;

};
#endif 
