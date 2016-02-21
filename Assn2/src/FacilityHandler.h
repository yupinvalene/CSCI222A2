#ifndef FACILITYHANDLER_H_
#define FACILITYHANDLER_H__H_
#include "Facility.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class FacilityHandler
{
	public:
		vector<Facility> getVectorOfFacilities();
		void setVectorOfFacilities(vector<Facility> vectorOfFacilities);
		void readData();
		void writeData();
		void addFacility(string, string, string, long, long, bool);
		void deleteFacility(string facID);
		Facility findFacility(string facID);
		string getAvailableFacilities();
		vector<string> split(const string &s, char delim, vector<string> &linesplit);

	private:
		vector<Facility> vectorOfFacilities;

};

#endif /* FACILITYHANDLER_H_ */
