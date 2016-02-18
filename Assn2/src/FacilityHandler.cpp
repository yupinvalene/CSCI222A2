#include "FacilityHandler.h"

int main()
{
	cout << "test" << endl;
	FacilityHandler fh;
	fh.readData();
}

vector<Facility> FacilityHandler::getVectorOfFacilities()
{
	return vectorOfFacilities;
}

void FacilityHandler::setVectorOfFacilities(vector<Facility> vectorOfFacilities)
{
	this->vectorOfFacilities = vectorOfFacilities;
}

void FacilityHandler::readData()
{
	string data;
	ifstream datafile;
	datafile.open("facilitiesDatabase.txt");
	getline(datafile, data, '\0'); // read the whole text file as string

	string delimit = ",";
	string delimiter = "\n";
	size_t pos = 0;
	size_t pos2 = -2;

	string line;
	string info;
	long time;
	int avail;

	string id, name, add;
	long sTime, eTime;

	while ((pos = data.find(delimiter)) != string::npos) // split the data string by \n delimiter
	{
	    line = data.substr(0, pos);
	    int i = 0;
	    while ((pos2 = line.find(delimit)) != string::npos) // split the data string by , delimiter
		{
	    		cout << info << endl;
				info = line.substr(0, pos2);
				if(i == 0)
				{
					id = info;
				}
				if(i == 1)
				{
					name = info;
				}
				if(i == 2)
				{
					add = info;
				}
				if(i == 3)
				{
					sTime = atol(info.c_str());
				}
				if(i == 4)
				{
					eTime = atol(info.c_str());
				}
				line.erase(0, pos2 + delimit.length());
				i++;
		}
	    data.erase(0, pos + delimiter.length());
	}

}

void FacilityHandler::writeData()
{

}

void FacilityHandler::addFacility(string facID, string facName, string facAddress, long facOperationStartTime,
				long facOperationEndTime, bool available)
{

}

void FacilityHandler::deleteFacility(string facID)
{

}

Facility FacilityHandler::findFacility(string facID)
{

}

string FacilityHandler::getAvailableFacilities()
{

}
