#ifndef SRC_SERVICES_H_
#define SRC_SERVICES_H_

#include "ReportGenerator.h"

class Services{

	public:

			//constructors and destructor
			Services();
			Services(string, string, float, long, long, bool);
			~Services();

			//setters
			void setSvcID(string);
			void setSvcName(string);
			void setSvcOperationStartTime(long);
			void setSvcOperationEndTime(long);
			void setAvailable(bool);
			void setFee(float);

			//getters
			string getSvcID();
			string getSvcName();
			long getSvcOperationStartTime();
			long getSvcOperationEndTime();
			bool getAvailable();
			float getFee();

	private:

			//data members
			string svcID;
			string svcName;
			float fee;
			long svcOperationStartTime;
			long svcOperationEndTime;
			bool available;

};



#endif /* SRC_SERVICES_H_ */
