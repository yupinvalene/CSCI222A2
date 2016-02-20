/*
 * BookingHandler.cpp
 *
 *  Created on: 19 Feb 2016
 *      Author: Dong Bin
 */

#include "Booking.h"
#include "Booking.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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
		void writeData(string );
		void addBooking(string, string, string, int, int, string, string  );
		void deleteBooking(string );
		Booking findBooking(string );
		void changeBooking(string );
};

BookingHandler::BookingHandler()
{

}

void BookingHandler::setVectorOfBooking(vector<Booking> currentBooking)
{
	vectorOfBooking = currentBooking;
}

void BookingHandler::readData()
{
	cout << "test" << endl;

	string line;
	vector<string> data;

	ifstream myfile;
	myfile.open("BookingDatabase.txt");

	if(myfile.is_open())
	{
		while(getline(myfile, line))
		{
			data.push_back(line);
			//cout << line << endl;
		}
	}
	myfile.close();
	int size = data.size();
	//cout << size << endl;

	for (int i = 0; i < size; i++)
	{
		string str = data.at(i);
		string word;
		string words[6];
		stringstream stream(str);
		Booking temp;
		int s = 0;

		while(getline(stream, word, ','))
		{
			words[s] = word;
			s++;
		}

		temp.setBookingID(words[0]);
		temp.setMemberID(words[1]);
		temp.setDate(words[2]);
		temp.setBookingStartTime(atoi(words[3].c_str()));
		temp.setBookingEndTime(atoi(words[4].c_str()));
		temp.setFacID(words[5]);
		temp.setFacName(words[6]);


		//cout << temp.getBookingID() << endl;
		//cout << temp.getMemberID() << endl;
		//cout << temp.getDate() << endl;
		//cout << temp.getBookingStartTime() << endl;
		//cout << temp.getBookingEndTime() << endl;
		//cout << temp.getFacID() << endl;
		//cout << temp.getFacName() << endl;

		vectorOfBooking.push_back(temp);
	}

	//cout << "vector = " << vectorOfBooking.size() << endl;


}

void BookingHandler::writeData(string data)
{

}

void BookingHandler::addBooking(string bookID, string memberID , string date, int startTime, int endTime, string facID, string facName)
{
	Booking temp;

	temp.setBookingID(bookID);
	temp.setMemberID(memberID);
	temp.setDate(date);
	temp.setBookingStartTime(startTime);
	temp.setBookingEndTime(endTime);
	temp.setFacID(facID);
	temp.setFacName(facName);

	vectorOfBooking.push_back(temp);

}

void BookingHandler::deleteBooking(string bookingID)
{
	int size = vectorOfBooking.size();

	for(int i = 0; i < size; i++)
	{
		if(bookingID.compare(vectorOfBooking.at(i).getBookingID()) == 0)
		{
			vectorOfBooking.erase(vectorOfBooking.begin()+i);
		}
	}
}

Booking BookingHandler::findBooking(string bookingID)
{
		Booking temp;

		int size = vectorOfBooking.size();

		for(int i = 0; i < size; i++)
		{
			if(bookingID.compare(vectorOfBooking.at(i).getBookingID()) == 0)
			{
				temp = vectorOfBooking.at(i);
			}
		}

		return temp;
}

void BookingHandler::changeBooking(string BookingID)
{

}




