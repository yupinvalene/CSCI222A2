#ifndef FACILITYHANDLER_H_
#define FACILITYHANDLER_H__H_
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include "Facility.h"
#include "UIDGenerator.h"

using namespace std;

class FacilityHandler
{
	public:
		vector<Facility> getVectorOfFacilities();
		void setVectorOfFacilities(vector<Facility> vectorOfFacilities);
		bool readData();
		bool writeData();
		void addFacility(string, string, long, long, bool);
		bool deleteFacility(string facID);
		Facility findFacility(string facID);
		string getAvailableFacilities();
		vector<string> split(const string &s, char delim, vector<string> &linesplit);
		void viewAllFacility();

	private:
		vector<Facility> vectorOfFacilities;

};

#endif /* FACILITYHANDLER_H_ */
