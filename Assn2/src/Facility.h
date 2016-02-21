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
		Facility(string, string, string, long, long, bool);
		string getFacID();
		void setFacID(string facID);
		string getFacName();
		void setFacName(string facName);
		string getFacAddress();
		void setFacAddress(string facAddress);
		long getFacOperationStartTime();
		void setFacOperationStartTime(long facOperationStartTime);
		long getFacOperationEndTime();
		void setFacOperationEndTime(long facOperationEndTime);
		bool getAvailable();
		void setAvailable(bool available);

	private:
		string facID;
		string facName;
		string facAddress;
		long facOperationStartTime;
		long facOperationEndTime;
		bool available;

};

#endif /* FACILITY_H_ */
