//Employee.h
//20 Feb 2016, Chen Fei


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Employee{
	public:
		Employee();
		Employee(string, string, string, string, string, string);
		~Employee();
		
		//accessor
		string getName();
		string getDepartment();
		string getAddress();
		string getAge();
		string getContactNum();
		string getEmpID();

		//mutator
		void setName(string);
		void setDepartment(string);
		void setAddress(string);
		void setAge(string);
		void setContactNum(string);
		void setEmpID(string);

	private:
		string name;
		string department;
		string address;
		string age;
		string contactNum;
		string empID;
};
#endif 

