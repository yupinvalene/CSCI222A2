//Employee.h
//20 Feb 2016, Chen Fei

#include "employee.h"

Employee::Employee() {
	name = "";
	department = "";
	address = "";
	age = "";
	contactNum = "";
	empID = "";

}

Employee::Employee(string name, string department, string address,
		string age, string contactNum, string empID) {
	this -> name = name;
	this -> department = department;
	this -> address = address;
	this -> age = age;
	this -> contactNum = contactNum;
	this -> empID = empID;
}


Employee::~Employee() {

}

string Employee::getName() {
	return name;
}

string Employee::getDepartment() {
	return department;
}

string Employee::getAddress() {
	return address;
}

string Employee::getAge() {
	return age;
}

string Employee::getContactNum() {
	return contactNum;
}

string Employee::getEmpID() {
	return empID;
}


void Employee::setName(string name) {
	this -> name = name;
}

void Employee::setDepartment(string department) {
	this -> department = department;
}

void Employee::setAddress(string address) {
	this -> address = address;
}

void Employee::setAge(string age) {
	this -> age = age;
}

void Employee::setContactNum(string contactNum) {
	this -> contactNum = contactNum;
}

void Employee::setEmpID(string empID) {
	this -> empID = empID;
}

