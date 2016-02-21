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

		void buildMembership(string, string, float, vector<string>);
		void setFilename(string);
		bool readFile();
		bool writeFile();
		void printMembership(string);
		void printAllMemberships();
		void amendMembership(string, string, float, vector<string>);
		bool getMembership(string, Membership&);


	private:
		vector<Membership> vectorOfMembership;
		string fileName;
};





#endif /* MEMBERSHIPBUILDER_H_ */
