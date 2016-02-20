//Employee.h
//20 Feb 2016, Chen Fei

#include "Manager.h"

Manager::Manager() {
	username = "";
	password = "";

}

Manager::Manager(Employee employee, string username, string password) {
	this -> username = username;
	this -> password = password;
	this -> password = password;
	this -> memberID = memberID;
	this -> email = email;
	this -> contact = contact;
	this -> creditCardNo = creditCardNo;
	this -> membership = membership;
	this -> vectorOfNotification = vectorOfNotification;
}


Manager::~Manager() {

}

string Manager::getUsername() {
	return name;
}

string Manager::getPassword() {
	return address;
}


void Manager::setUsername(string username) {
	this -> name = name;
}

void Manager::setPassword(string password) {
	this -> password = password;
}


