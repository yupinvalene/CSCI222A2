/*
 * Membership.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#include "Membership.h"

Membership::Membership() {
	membershipID = "";
	rank = "";
	membershipFee = 0.0;
}

Membership::Membership(string membershipID, string rank, double membershipFee,
		vector<string> accessRight) {
	this -> membershipID = membershipID;
	this -> rank = rank;
	this -> membershipFee = membershipFee;
	this -> accessRight = accessRight;
}

Membership::~Membership() {
}

string Membership::getRank() {
	return rank;
}

double Membership::getMembershipFee() {
	return membershipFee;
}

vector<string> Membership::getAccessRight() {
	return accessRight;
}

string Membership::getMembershipID() {
	return membershipID;
}

void Membership::setRank(string rank) {
	this -> rank = rank;
}

void Membership::setMembershipFee(double membershipFee) {
	this -> membershipFee = membershipFee;
}

void Membership::setAccessRight(vector<string> accessRight) {
	this -> accessRight = accessRight;
}

void Membership::setMembershipID(string membershipID) {
	this -> membershipID = membershipID;
}

void Membership::toString(){
	cout << "MembershipID: " << membershipID << endl
		 << "Rank: " << rank << endl
		 << "MembershipFee: " << membershipFee << endl
		 << "Access Right: " ;
	for(int i = 0; i < accessRight.size(); i++){
		cout << accessRight[i] << endl;;
	}
}
