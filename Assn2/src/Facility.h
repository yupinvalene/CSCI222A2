#ifndef FACILITY_H_
#define FACILITY_H__H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Facility
{
	public:
		Facility();
		Facility(facID, facName, facAddress, facOperationStartTime, facOperationEndTime, hourlyRate, available);

	private:
		string facID;
		string facName;
		string facAddress;
		long facOperationStartTime;
		long facOperationEndTime;
		float hourlyRate;
		bool available;

};

#endif /* FACILITY_H_ */