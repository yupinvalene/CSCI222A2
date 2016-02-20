//Employee.h
//20 Feb 2016, Chen Fei

#ifndef EMPLOYEEHANDLER_H_
#define EMPLOYEEHANDLER_H__H_
#include "Employee.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class EmployeeHandler
{
	public:
		vector<Employee> getVectorOfEmployee();
		void setVectorOfEmployee(vector<Employee> vectorOfEmployee);
		void readData();
		void writeData();
		void addManager(string name, string department, string address, string age,
						string contactNum);
		void deleteManager(string empID);
		Employee findEmployee(string empID);
		string updateManagerDetails(string empID, string name, string department, string address, 
						string age, string contact);

	private:
		vector<Employee> vectorOfEmployee;

};

#endif /* EMPLOYEEHANDLER_H_ */

