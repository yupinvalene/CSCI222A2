/*
 * Membership.h
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#ifndef MEMBERSHIP_H_
#define MEMBERSHIP_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Membership{
	public:

	Membership();
	Membership(string, string, double, vector<string>);
	~Membership();

	string getRank();
	double getMembershipFee();
	vector<string> getAccessRight();
	string getMembershipID();

	void setRank(string);
	void setMembershipFee(double);
	void setAccessRight(vector<string>);
	void setMembershipID(string);

	void toString();

	private:
	string rank;
	double membershipFee;
	vector<string> accessRight;
	string membershipID;
};




#endif /* MEMBERSHIP_H_ */
