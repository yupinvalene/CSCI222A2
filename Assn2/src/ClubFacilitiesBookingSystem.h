/*
 * ClubFacilitiesBookingSystem.h
 *
 *  Created on: 22 Feb 2016
 *      Author: yupin
 */

#ifndef CLUBFACILITIESBOOKINGSYSTEM_H_
#define CLUBFACILITIESBOOKINGSYSTEM_H_

#include "ServicesHandler.h"
#include "FacilityHandler.h"
#include "MembershipBuilder.h"
#include "MemberHandler.h"

using namespace std;

class ClubFacilitiesBookingSystem{
	public:
		ClubFacilitiesBookingSystem();
		~ClubFacilitiesBookingSystem();
		void run();
		void displayMemberMenu();
		void displayManagerMenu();
		void createClubMember();
		void createClubFacility();
		void createClubMembership();
		void createClubService();
		void searchClubFacilities();
		void searchClubMember();
		void updateClubFacilities();
		void updateClubMember();
		void deleteClubFacilities();
		vector<string> split(const string &s, char delim, vector<string> &linesplit);

	private:

		ServicesHandler serviceHandler;
		FacilityHandler facilityHandler;
		MembershipBuilder membershipBuilder;
		MemberHandler memberHandler;

};

#endif /* CLUBFACILITIESBOOKINGSYSTEM_H_ */
