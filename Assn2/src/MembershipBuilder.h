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
#include <fstream>
#include <sstream>

#include "Membership.h"

using namespace std;

class MembershipBuilder{
	public:
		MembershipBuilder();
		MembershipBuilder(vector<Membership>);
		~MembershipBuilder();

		vector<Membership> getVectorOfMembership();

		void setVectorOfMembership(vector<Membership>);

		void buildMembership(string, string, double, vector<string>);
		void setFilename(char*);
		bool readFile();
		bool writeFile();
		void printMembership(string);
		void printAllMemberships();
		void amendMembership(string, string, double, vector<string>);
		bool getMembership(string, Membership&);


	private:
		vector<Membership> vectorOfMembership;
		char* fileName;
		vector<string> split(const string &s, char delim, vector<string> &linesplit);

};





#endif /* MEMBERSHIPBUILDER_H_ */
