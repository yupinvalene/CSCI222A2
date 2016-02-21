/*
 * MemberHandler.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#include "MemberHandler.h"

MemberHandler::MemberHandler() {
}

MemberHandler::MemberHandler(vector<Member> vectorOfMember) {
	this -> vectorOfMember = vectorOfMember;
}

MemberHandler::~MemberHandler() {
}

vector<Member> MemberHandler::getVectorOfMember() {
	return vectorOfMember;
}


void MemberHandler::setVectorOfMember(vector<Member> vectorOfMember) {
	this -> vectorOfMember = vectorOfMember;
}

void MemberHandler::readData(string fileName) {
}

void MemberHandler::writeData(string fileName) {
}

void MemberHandler::addMember(string name, string address,
		string password, string email, string contact,
		string dob, Membership membership, vector<Notification> vectorOfNotification) {

	Member member;
	member.setName(name);
	member.setAddress(address);
	member.setPassword(password);
	member.setEmail(email);
	member.setContact(contact);
	member.setDOB(dob);
	member.setMembership(membership);
	member.setNotification(vectorOfNotification);

	vectorOfMember.push_back(member);
}

void MemberHandler::deleteMember(string memberID) {
	bool found = false;
	for(int i = 0; i < vectorOfMember.size(); i++){
		if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
			vectorOfMember.erase(vectorOfMember.begin()+i);
			cout << memberID << " is being removed.";
			found = true;
		}
	}
	if(found == false){
		cout << memberID << " doesnt exist";
	}

}

Member MemberHandler::findMember(string memberID) {
	for(int i = 0; i < vectorOfMember.size(); i++){
			if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
				return vectorOfMember[i];
			}
	}
}

void MemberHandler::updateMember(string memberID,
		string name, string address, string password,
		string email, string contact, string dob, string creditCardNo) {
	for(int i = 0; i < vectorOfMember.size(); i++){

			if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){

				if(name.compare(vectorOfMember[i].getName() == 0){
					vectorOfMember[i].setName(name);
				}
				else if(address.compare(vectorOfMember[i].getAddress() == 0){
					vectorOfMember[i].setAddress(address);
				}
				else if(password.compare(vectorOfMember[i].getPassword() == 0){
					vectorOfMember[i].setPassword(password);
				}
				else if(email.compare(vectorOfMember[i].getEmail() == 0){
					vectorOfMember[i].setEmail(email);
				}
				else if(contact.compare(vectorOfMember[i].getContact() == 0){
					vectorOfMember[i].setContact(contact);
				}
				else if(dob.compare(vectorOfMember[i].getDOB() == 0){
					vectorOfMember[i].setDOB(dob);
				}
				else if(creditCardNo.compare(vectorOfMember[i].getCreditCardNo() == 0){
					vectorOfMember[i].setCreditCardNo(creditCardNo);
				}
			}

	}

}

vector<Notification> MemberHandler::getMemberNotification(string memberID) {
	for(int i = 0; i < vectorOfMember.size(); i++){
		if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
			return vectorOfMember[i].getNotification()();
		}
	}
}

void MemberHandler::updateMembership(string memberID, float fee, string rank, vector<string> accessRight, Membership membership) {
	for(int i = 0; i < vectorOfMember.size(); i++){
		if(memberID.compare(vectorOfMember[i].getMemberID()) == 0){
			membership.setRank(rank);
			membership.setAccessRight(accessRight);
			membership.setMembershipFee(fee);
		}
	}

}

void MemberHandler::pushNotification(string memberID, Notification vectorOfNotification) {

}


