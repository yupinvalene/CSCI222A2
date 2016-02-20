#include "ReportGenerator.h"

ReportGenerator::ReportGenerator(){

}

ReportGenerator::~ReportGenerator(){

}

void ReportGenerator::printFacilitiesUsageSummary(vector<Facility> facilities){

	//============================================================================//
	//	monthly usage (bookings) of facilities
	//	Facility class needs "number of times booked" data member/attribute
	//	Facility class needs to get the date from Booking class
	//============================================================================//

	int noOfTimesBooked = 0;

	//====================================================================//
	// 	display facility name, month and number of times booked each month
	//====================================================================//
	cout << "Facility\t"
		 << "Month\t"
		 << "Usage(number of times booked)" << endl;

	for(int i = 0; i < facilities.size(); i++){

		//cout << facilities[i].getName() + "\t"
		//	 << /* "display month" */
			// << /* "display number of times facility is booked per month" */
			 //<< endl;

	}

}

void ReportGenerator::printRentalBehaviour(vector<Member> member, vector<Facility> facilities){

	//=======================================================================================================//
	//	rental behaviour( which members book which facilities frequently)
	//	Member class needs data members/attributes to show how many times they booked a particular facility
	//=======================================================================================================//

	//=================================================================//
	// 	display member name and number of times they book each facility
	//=================================================================//
	cout << "Name\t"
		 << "Facility Name"
		 << "Number of times booked"
		 << endl;

	for(int i = 0; i < member.size(); i++){

		cout << member[i].getName() + "\t"
			 << facilities[i].getName() + "\t"
			 <<	/* "display number of times booked" */
			 << endl;

	}

}

void ReportGenerator::printBookingSummary(vector<Member> member){

	//==========================================================//
	//	discount rates given to each member
	//	Member class needs "discount" data member/attribute
	//==========================================================//

	//===============================================================//
	// 	display member name and discount rate of member
	//===============================================================//
	cout << "Name\t"
		 << "Discount Rate"
		 << endl;

/*	for(int i = 0; i < member.size(); i++){

		cout << member[i].getName() + "\t"
			 << member[i].getDiscountRate
			 << endl;

	}*/

}
