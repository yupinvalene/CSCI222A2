/*
 * BookingHandler.h
 *
 *  Created on: 22 Feb 2016
 *      Author: yupin
 */

#ifndef SRC_BOOKINGHANDLER_H_
#define SRC_BOOKINGHANDLER_H_

#include "Booking.h"
#include "UIDGenerator.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class BookingHandler
{
	private:
		vector<Booking> vectorOfBooking;

	public:
		BookingHandler();
		vector<Booking> getVectorOfBooking();
		void setVectorOfBooking(vector<Booking>);
		void readData();
		bool writeData();
		void addBooking(string, string, int, int, string, string  );
		void deleteBooking(string );
		Booking findBooking(string );
		void changeBooking(string );
};



#endif /* SRC_BOOKINGHANDLER_H_ */
