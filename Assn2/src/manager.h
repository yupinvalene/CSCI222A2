//Employee.h
//20 Feb 2016, Chen Fei

#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"


using namespace std;

class Manager: public Employee{
	public:
		Manager();
		~Manager();
		
		//accessor
		string getUsername();
		string getPassword();

		//mutator
		void setUsername(string);
		void setPassword(string);

	private:
		string username;
		string password;

};

#endif 

