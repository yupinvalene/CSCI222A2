//Employee.h
//20 Feb 2016, Chen Fei

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

//#include "Employee.h"
//#include "Notification.h"
//#include "Membership.h"
//#include "MembershipBuilder.h"


using namespace std;

class Manager{
	public:
		Manager();
		Manager(/*Employee*/, string, string);
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

