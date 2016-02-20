#include "FacilityHandler.h"

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
	FacilityHandler fh;
	string data;
	ifstream datafile;
	datafile.open("facilitiesDatabase.txt");
	getline(datafile, data, '\0'); // read the whole text file as string

	string delimiter = "\n";
	char delim = ',';
	size_t pos = 0;
	size_t pos2 = 0;
	string line;

	string id, name, add;
	long sTime, eTime;
	int avail;
	vector<string> linesplit;

	while ((pos = data.find(delimiter)) != string::npos) // split the data string by \n delimiter
	{
	    line = data.substr(0, pos);
	    fh.split(line, delim, linesplit);
	    data.erase(0, pos + delimiter.length());
	}
	int i = 0;
    for(string s : linesplit)
    {
    	if(i == 6)
    	{
    		i = 0;
    	}
       switch(i)
       {
           case 0: id = s; break;
           case 1: name = s; break;
           case 2: add = s; break;
           case 3: sTime = atol(s.c_str()); break;
           case 4: eTime = atol(s.c_str()); break;
           case 5: avail = atoi(s.c_str()); break;
       }
       if(i == 5)
       {
    	   fh.addFacility(id, name, add, sTime, eTime, avail);
       }
       i++;
    }

}

vector<string> FacilityHandler::split(const string &s, char delim, vector<string> &linesplit)
{
	stringstream ss(s);
	string item;
	while(getline(ss, item, delim))
	{
		linesplit.push_back(item);
	}
	return linesplit;
}

void FacilityHandler::writeData()
{
	ostringstream = oss;

	for(Facility f : vectorOfFacilities)
	{
		string id = f.getFacID();
		string name = f.getFacName();
		string add = f.getFacAddress();
		long sTime = f.getFacOperationStartTime();
		long eTime = f.getFacOperationEndTime();
		int avail = f.getAvailable();

		oss << id << "," << name << "," << add << "," << sTime << "," << eTime << "," << avail << endl;
	}

	string info = oss.str();

	ofstream outfile;
	outfile.open("facilitiesDatabase.txt", ios::out | ios::trunc);
	outfile << info;
	outfile.close();
}

void FacilityHandler::addFacility(string facID, string facName, string facAddress, long facOperationStartTime, long facOperationEndTime, bool available)
{
    Facility fac(facID, facName, facAddress, facOperationStartTime, facOperationEndTime, available);
    vectorOfFacilities.push_back(fac);
}

void FacilityHandler::deleteFacility(string facID)
{
    int i = 0;
    for(Facility f : vectorOfFacilities)
    {
        string id = f.getFacID();
        if(id == facID)
        {
            vectorOfFacilities.erase(vectorOfFacilities.begin()+i);
        }
        i++;
    }
}

Facility FacilityHandler::findFacility(string facID)
{
    int i = 0;
    for(Facility f : vectorOfFacilities)
    {
        string id = f.getFacID();
        if(id == facID)
        {
            return f;
        }
        i++;
    }
}

string FacilityHandler::getAvailableFacilities()
{
    ostringstream os;
	 for(Facility f : vectorOfFacilities)
	 {
	     string id = f.getFacID();
	     int a = f.getAvailable();
	     os << "Facilities Available\n===========================\n";

	     if(a == 1)
	     {
	     	ostringstream os;
	     	os << id << endl;
	     }
	 }
	 string info;
	 info = os.str();
	 return info;
}
