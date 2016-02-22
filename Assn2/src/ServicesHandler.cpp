#include "ServicesHandler.h"

//constructors and destructor
ServicesHandler::ServicesHandler(){

}

ServicesHandler::~ServicesHandler(){
}

vector<Services> ServicesHandler::getVectorOfServices(){

	return vectorOfServices;

}

void ServicesHandler::setVectorOfServices(vector<Services> vectorOfServices){

	this->vectorOfServices = vectorOfServices;

}

bool ServicesHandler::readData(){

	string data;
	ifstream datafile;
	datafile.open("servicesDatabase.txt", ifstream::in);
	getline(datafile, data, '\0'); // read the whole text file as string

	string delimiter = "\n";
	char delim = ',';
	size_t pos = 0;
	size_t pos2 = 0;
	string line;

	string id, name;
	long sTime, eTime;
	float fee;
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
		   case 2: fee = atof(linesplit[i].c_str()); break;
		   case 3: sTime = atol(linesplit[i].c_str()); break;
		   case 4: eTime = atol(linesplit[i].c_str()); break;
		   case 5: avail = atol(linesplit[i].c_str()); break;
	   }
	   if(n == 5)
	   {
		   Services service(id, name, fee, sTime, eTime, avail);
		   vectorOfServices.push_back(service);
	   }
	   n++;
	}
	datafile.close();

	return true;
}

vector<string> ServicesHandler::split(const string &s, char delim, vector<string> &linesplit)
{
	stringstream ss(s);
	string item;
	while(getline(ss, item, delim))
	{
		linesplit.push_back(item);
	}
	return linesplit;
}

bool ServicesHandler::writeData(){
	ostringstream oss;

	for(int i = 0; i < vectorOfServices.size(); i++)
	{
		string id = vectorOfServices[i].getSvcID();
		string name = vectorOfServices[i].getSvcName();
		float fee = vectorOfServices[i].getFee();
		long sTime = vectorOfServices[i].getSvcOperationStartTime();
		long eTime = vectorOfServices[i].getSvcOperationEndTime();
		int avail = vectorOfServices[i].getAvailable();

		oss << id << "," << name << "," << fee << "," << sTime << "," << eTime << "," << avail << "\n";
	}

	string info = oss.str();

	ofstream outfile;
	outfile.open("servicesDatabase.txt", ios::out | ios::trunc);
	outfile << info;
	outfile.close();

	return true;
}

void ServicesHandler::addService(string svcName, float fee, long svcOperationStartTime, long svcOperationEndTime, bool available){
	string svcID = UIDGenerator::generate();

	Services service(svcID, svcName, fee, svcOperationStartTime, svcOperationEndTime, available);
	vectorOfServices.push_back(service);

}

bool ServicesHandler::deleteService(string svcID){
	int i = 0;
	for(int i = 0; i < vectorOfServices.size(); i++)
	{
		string id = vectorOfServices[i].getSvcID();
		if(id.compare(svcID))
		{
			vectorOfServices.erase(vectorOfServices.begin() + i);
			writeData();
			return true;
		}
		i++;
	}

	return false;
}

bool ServicesHandler::findServices(string serID, Services& ser){

    int i = 0;
	for(int i = 0; i < vectorOfServices.size(); i++)
    {
        string id = vectorOfServices[i].getSvcID();
//        cout << i << ": " << id << endl;
        if(id.compare(serID) == 0)
        {
            ser = vectorOfServices[i];
            return true;
        }
    }
	return false;
}

string ServicesHandler::getAvailableServices(){

	ostringstream os;
	os << "Services Available\n===========================\n";
	for(int i = 0; i < vectorOfServices.size(); i++)
	 {
		 string name = vectorOfServices[i].getSvcName();
		 int a = vectorOfServices[i].getAvailable();

		 if(a == 1)
		 {
			os << name << endl;
		 }
	 }
	 string info;
	 info = os.str();
	 return info;

}

void ServicesHandler::viewAllServices()
{
	for(int i = 0; i < vectorOfServices.size(); i++)
	{
		string id = vectorOfServices[i].getSvcID();
		string name = vectorOfServices[i].getSvcName();
		long sTime = vectorOfServices[i].getSvcOperationStartTime();
		long eTime = vectorOfServices[i].getSvcOperationEndTime();
		int avail = vectorOfServices[i].getAvailable();
		float fee = vectorOfServices[i].getFee();
		cout << id << "," << name << "," << sTime << "," << eTime << "," << eTime << ",$" << fee << "," << avail << endl << endl;
	}

}
