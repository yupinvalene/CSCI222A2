/*
 * MembershipBuilder.h
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#ifndef MEMBERSHIPBUILDER_H_
#define MEMBERSHIPBUILDER_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

#include "Membership.h"

using namespace std;

class MembershipBuilder{
	public:
		MembershipBuilder();
		MembershipBuilder(vector<Membership>);
		~MembershipBuilder();

		vector<Membership> getVectorOfMembership();

		void setVectorOfMembership(vector<Membership>);

		Membership buildMembership(string, string, float, vector<string>);
		vector<Membership> readFile(string);
		void writeFile(string);
		void printMembership(string);
		void amendMembership(string, string, float, vector<string>);


	private:
		vector<Membership> vectorOfMembership;
};





#endif /* MEMBERSHIPBUILDER_H_ */
