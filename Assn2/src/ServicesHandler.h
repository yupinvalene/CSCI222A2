/*
 * ServicesHandler.h
 *
 *  Created on: 20 Feb 2016
 *      Author: Khairul
 */

#ifndef SRC_SERVICESHANDLER_H_
#define SRC_SERVICESHANDLER_H_

#include "Services.h"
#include "UIDGenerator.h"
#include <fstream>

class ServicesHandler{

	public:

			//constructors and destructor
			ServicesHandler();
			~ServicesHandler();

			vector<Services> getVectorOfServices();
			void setVectorOfServices(vector<Services>);
			bool readData();
			bool writeData();
			void addService(string, float, long, long, bool);

			bool deleteService(string);
			bool findServices(string, Services&);
			string getAvailableServices();
			void viewAllServices();

	private:
			vector<string> split(const string &s, char delim, vector<string> &linesplit);

			vector<Services> vectorOfServices;

};


#endif /* SRC_SERVICESHANDLER_H_ */
