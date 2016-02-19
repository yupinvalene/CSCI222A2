#ifndef BOOKING_H_
#define BOOKING_H_

#include <iostream>
#include <string>

using namespace std;

class Booking
{
	private: 
		string bookingID;
		string memberID;
		string date;
		int bookingStartTime;
		int bookingEndTime;
		string facID;
		string facName;
	
	public:
		Booking();
		string getBookingID();
		string getMemberID();
		string getDate();
		int getBookingStartTime();
		int getBookingEndTime();
		string getFacID();
		string getFacName();
		
		void setBookingID(string );
		void setMemberID(string );
		void setDate(string );
		void setBookingStartTime(int );
		void setBookingEndTime(int );
		void setFacID(string );
		void setFacName(string );
		
};

#endif
