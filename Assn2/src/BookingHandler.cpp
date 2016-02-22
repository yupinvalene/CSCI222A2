/*
 * BookingHandler.cpp
 *
 *  Created on: 19 Feb 2016
 *      Author: Dong Bin
 */
#include "BookingHandler.h"

BookingHandler::BookingHandler()
{

}

void BookingHandler::setVectorOfBooking(vector<Booking> currentBooking)
{
	vectorOfBooking = currentBooking;
}

void BookingHandler::readData()
{
	string line;
	vector<string> data;

	ifstream myfile;
	myfile.open("bookingDatabase.txt", ifstream::in);

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

bool BookingHandler::writeData()
{
	ostringstream oss;

	for(int i = 0; i < vectorOfBooking.size(); i++)
	{
		string bookingID = vectorOfBooking[i].getBookingID();
		string memberID = vectorOfBooking[i].getMemberID();
		string date = vectorOfBooking[i].getDate();
		int bookingStartTime = vectorOfBooking[i].getBookingStartTime();
		int bookingEndTime = vectorOfBooking[i].getBookingEndTime();
		string facID = vectorOfBooking[i].getFacID();
		string facName = vectorOfBooking[i].getFacName();
		oss << bookingID << "," << memberID << "," << date << "," << bookingStartTime << "," << bookingEndTime << "," << facID << "," << facName << "\n";
	}

	string info = oss.str();

	ofstream outfile;
	outfile.open("bookingDatabase.txt", ios::out | ios::trunc);

	if(!outfile)
	{
		cout << "bookingDatabase.txt"
			 << " opened for writing failed!!"
			 << endl;

		exit(-1);
	}

	outfile << info;
	outfile.close();

	return true;
}

void BookingHandler::addBooking(string memberID , string date, int startTime, int endTime, string facID, string facName)
{
	Booking temp;
	string uid = UIDGenerator::generate();
	temp.setBookingID(uid);
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

void BookingHandler::printBookingDatabase()
{
	for(int i = 0; i < vectorOfBooking.size(); i++){
		cout << "Booking ID: " << vectorOfBooking[i].getBookingID() << endl
			 << "Member ID: "  << vectorOfBooking[i].getMemberID() << endl
			 << "Date of booking: " << vectorOfBooking[i].getDate() << endl
			 << "Booking start time: " << vectorOfBooking[i].getBookingStartTime() << endl
			 << "Booking end time: " << vectorOfBooking[i].getBookingEndTime() << endl
			 << "Faci/service ID: " << vectorOfBooking[i].getFacID() << endl
			 << "Faci/service name: " << vectorOfBooking[i].getFacName() << endl << endl;
	}
}




