#include "FacilityHandler.h"

vector<Facility> FacilityHandler::getVectorOfFacilities()
{
	return vectorOfFacilities;
}

void FacilityHandler::setVectorOfFacilities(vector<Facility> vectorOfFacilities)
{
	this->vectorOfFacilities = vectorOfFacilities;
}

bool FacilityHandler::readData()
{
	string data;
	ifstream datafile;
	datafile.open("facilitiesDatabase.txt");

	if(!datafile)
	{
		cout << "facilitiesDatabase.txt"
			 << " opened failed!!"
			 << endl;

		exit(-1);
	}

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
	    split(line, delim, linesplit);
	    data.erase(0, pos + delimiter.length());
	}
	int n = 0;
    for(int i = 0; i < linesplit.size(); i++)
    {
    	if(n == 6)
    	{
    		n = 0;
    	}
       switch(n)
       {
           case 0: id = linesplit[i]; break;
           case 1: name = linesplit[i]; break;
           case 2: add = linesplit[i]; break;
           case 3: sTime = atol(linesplit[i].c_str()); break;
           case 4: eTime = atol(linesplit[i].c_str()); break;
           case 5: avail = atoi(linesplit[i].c_str()); break;
       }
       if(n == 5)
       {
    	   Facility fac(id, name, add, sTime, eTime, avail);
    	   vectorOfFacilities.push_back(fac);

       }
       n++;
    }
    datafile.close();

    return true;
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

void FacilityHandler::addFacility(string facName, string facAddress, long facOperationStartTime, long facOperationEndTime, bool available)
{
	string facID = UIDGenerator::generate();
    Facility fac(facID, facName, facAddress, facOperationStartTime, facOperationEndTime, available);
    vectorOfFacilities.push_back(fac);
}

bool FacilityHandler::writeData()
{
	ostringstream oss;
	cout << vectorOfFacilities.size();

	for(int i = 0; i < vectorOfFacilities.size(); i++)
	{
		string id = vectorOfFacilities[i].getFacID();
		string name = vectorOfFacilities[i].getFacName();
		string add = vectorOfFacilities[i].getFacAddress();
		long sTime = vectorOfFacilities[i].getFacOperationStartTime();
		long eTime = vectorOfFacilities[i].getFacOperationEndTime();
		int avail = vectorOfFacilities[i].getAvailable();
		oss << id << "," << name << "," << add << "," << sTime << "," << eTime << "," << avail << "\n";
	}

	string info = oss.str();

	ofstream outfile;
	outfile.open("facilitiesDatabase.txt", ios::out | ios::trunc);

	if(!outfile)
	{
		cout << "facilitiesDatabase.txt"
			 << " opened for writing failed!!"
			 << endl;

		exit(-1);
	}

	outfile << info;
	outfile.close();

	return true;
}

bool FacilityHandler::deleteFacility(string facID)
{
    int i = 0;
	for(int i = 0; i < vectorOfFacilities.size(); i++)
    {
        string id = vectorOfFacilities[i].getFacID();
        if(id.compare(facID) == 0)
        {
            vectorOfFacilities.erase(vectorOfFacilities.begin() + i);
            writeData();
            return true;
        }
        i++;
    }

    return false;
}

bool FacilityHandler::findFacility(string facID, Facility& fac)
{
    int i = 0;
	for(int i = 0; i < vectorOfFacilities.size(); i++)
    {
        string id = vectorOfFacilities[i].getFacID();
        if(id.compare(facID) == 0)
        {
            fac = vectorOfFacilities[i];
            return true;
        }
        i++;
    }
	return false;
}

string FacilityHandler::getAvailableFacilities()
{
    ostringstream os;
    os << "Facilities Available\n===========================\n";
	for(int i = 0; i < vectorOfFacilities.size(); i++)
	 {
	     string name = vectorOfFacilities[i].getFacName();
	     int a = vectorOfFacilities[i].getAvailable();

	     if(a == 1)
	     {
	     	os << name << endl;
	     }
	 }
	 string info;
	 info = os.str();
	 return info;
}

void FacilityHandler::viewAllFacility()
{
	for(int i = 0; i < vectorOfFacilities.size(); i++)
	{
		string id = vectorOfFacilities[i].getFacID();
		string name = vectorOfFacilities[i].getFacName();
		string add = vectorOfFacilities[i].getFacAddress();
		long sTime = vectorOfFacilities[i].getFacOperationStartTime();
		long eTime = vectorOfFacilities[i].getFacOperationEndTime();
		int avail = vectorOfFacilities[i].getAvailable();
		cout << id << "," << name << "," << add << "," << sTime << "," << eTime << "," << avail << endl << endl;
	}

}

