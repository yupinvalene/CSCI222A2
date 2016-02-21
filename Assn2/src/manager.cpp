//Employee.h
//20 Feb 2016, Chen Fei

#include "Manager.h"

Manager::Manager() {
	username = "";
	password = "";

}


Manager::~Manager() {

}

string Manager::getUsername() {
	return username;
}

string Manager::getPassword() {
	return password;
}


void Manager::setUsername(string username) {
	this -> username = username;
}

void Manager::setPassword(string password) {
	this -> password = password;
}


