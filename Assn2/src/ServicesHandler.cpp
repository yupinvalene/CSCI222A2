#include "ServicesHandler.h"
int main()
{
	cout << "test" << endl;
	ServicesHandler s;
	s.readData();
}

//constructors and destructor
ServicesHandler::ServicesHandler(){
/*
	this->vectorOfServices = vectorOfServices.setSvcID("");
	this->vectorOfServices = vectorOfServices.setSvcName("");
	this->vectorOfServices = vectorOfServices.setSvcOperationStartTime(0);
	this->vectorOfServices = vectorOfServices.setSvcOperationEndTime(0);
	this->vectorOfServices = vectorOfServices.setAvailable(false);
	*/
}

ServicesHandler::~ServicesHandler(){
}

vector<Services> ServicesHandler::getVectorOfServices(){

	return vectorOfServices;

}

void ServicesHandler::setVectorOfServices(vector<Services> vectorOfServices){

	this->vectorOfServices = vectorOfServices;

}

void ServicesHandler::readData(){

	string data;
	ifstream datafile;
	datafile.open("servicesDatabase.txt");
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
					sTime = atol(info.c_str());
				}
				if(i == 3)
				{
					eTime = atol(info.c_str());
				}

				line.erase(0, pos2 + delimit.length());
				i++;
		}
	    data.erase(0, pos + delimiter.length());
	}

	datafile.close();

}

void ServicesHandler::writeData(){
}

void ServicesHandler::addService(string svcID, string svcName, long svcOperationStartTime, long svcOperationEndTime, bool available){
}

void ServicesHandler::deleteService(string svcID){
}

Services ServicesHandler::findService(string svcID, string svcName){

/*	for(int i = 0; i < vectorOfServices.size(); i++){

		if(vectorOfServices.getID == svcID || vectorOfServices.getName == svcName){

			cout << vectorOfServices.getSvcID << "\t" << vectorOfServices.getSvcName << endl;

		}

	}*/

	return vectorOfServices;

}

string ServicesHandler::getAvailableServices(){

/*	for(int i = 0; i < vectorOfServices.size(); i++){

		if(vectorOfServices.getAvailable == true){

			cout << vectorOfServices.getSvcID << "\t" << vectorOfServices.getSvcName << endl;

		}

	}*/

}
