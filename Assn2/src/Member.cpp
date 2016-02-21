
/*
 * Member.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#include "Member.h"

Member::Member() {
	name = "";
	address = "";
	memberID = "";
	password = "";
	creditCardNo = "";

}

Member::Member(string name, string address, string memberID,
		string password, string email, string contact,
		string creditCardNo, Membership membership) {
	this -> name = name;
	this -> address = address;
	this -> password = password;
	this -> memberID = memberID;
	this -> email = email;
	this -> contact = contact;
	this -> creditCardNo = creditCardNo;
	this -> membership = membership;
}


Member::~Member() {

}

string Member::getName() {
	return name;
}

string Member::getAddress() {
	return address;
}

string Member::getMemberID() {
	return memberID;
}

string Member::getPassword() {
	return password;
}

string Member::getEmail() {
	return email;
}

string Member::getContact() {
	return contact;
}

string Member::getDOB() {
	return dob;
}

string Member::getCreditCardNo() {
	return creditCardNo;
}

void Member::setName(string name) {
	this -> name = name;
}

void Member::setAddress(string address) {
	this -> address = address;
}

void Member::setMemberID(string memberID) {
	this -> memberID = memberID;
}

void Member::setPassword(string password) {
	this -> password = password;
}

void Member::setEmail(string email) {
	this -> email = email;
}

void Member::setContact(string contact) {
	this -> contact = contact;
}

void Member::setDOB(string dob) {
	this -> dob = dob;
}

void Member::setCreditCardNo(string creditCardNo)
{
	this -> creditCardNo = creditCardNo;
}

Membership Member::getMembership() {
	return membership;
}

vector<Notification> Member::getNotification() {
	return vectorOfNotification;
}

void Member::setNotification(vector<Notification> vectorOfNotification) {
	this -> vectorOfNotification = vectorOfNotification;
}

void Member::setMembership(Membership membership) {
	this -> membership = membership;

}
