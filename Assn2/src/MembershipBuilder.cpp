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

Membership MembershipBuilder::buildMembership(string membershipID,
		string rank, float membershipFee, vector<string> vectorOfAccessRight) {
	Membership membership;
	membership.setMembershipID(membershipID);
	membership.setRank(rank);
	membership.setMembershipFee(membershipFee);
	membership.setAccessRight(vectorOfAccessRight);
	return membership;
}

vector<Membership> MembershipBuilder::readFile(string allocator) {

}

void MembershipBuilder::writeFile(string allocator) {

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

void MembershipBuilder::amendMembership(string membershipID, string rank,float fee, vector<string> accessRight) {

	for(int i = 0; i < vectorOfMembership.size(); i++){
		if(membershipID.compare(vectorOfMembership[i].getMembershipID()) == 0){
			if(rank.compare(vectorOfMembership[i].getRank()) == 0){
				vectorOfMembership[i].setRank(rank);
			}
			else if(fee == vectorOfMembership[i].getMembershipFee){
				vectorOfMembership[i].setMembershipFee(fee);
				vectorOfMembership[i].setAccessRight(accessRight);
			}

		}

	}
}
