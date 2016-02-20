/*
 * ServicesHandler.h
 *
 *  Created on: 20 Feb 2016
 *      Author: Khairul
 */

#ifndef SRC_SERVICESHANDLER_H_
#define SRC_SERVICESHANDLER_H_

#include "Services.h"

class ServicesHandler{

	public:

			//constructors and destructor
			ServicesHandler();
			~ServicesHandler();

			vector<Services> getVectorOfServices();
			void setVectorOfServices(vector<Services>);
			void readData();
			void writeData();
			void addService(string, string, long, long, bool);

			void deleteService(string);
			Services findService(string, string);
			string getAvailableServices();

	private:

			vector<Services> vectorOfServices;

};


#endif /* SRC_SERVICESHANDLER_H_ */
