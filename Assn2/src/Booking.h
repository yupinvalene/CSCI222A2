#include <iostream>
#include <string>

using namespace std;

class Booking
{
	private: 
		string bookingID;
		string memberID;
		int bookingStartTime;
		int bookingEndTime;
		string facID;
		string facName;
	
	public:
		Booking();
		string getBookingID();
		string getMemberID();
		int getBookingStartTime();
		int getBookingEndTime();
		string getFacID();
		string getFacName();
		
		void setBookingID(string );
		void setMemberID(string );
		void setBookingStartTime(int );
		void setBookingEndTime(int );
		void setFacID(string );
		void setFacName(string );
		
};

