#include "Booking.h"

Booking::Booking()
{
	bookingID = "";
	memberID = "";
	date = "";
	bookingStartTime = 0;
	bookingEndTime = 0;
	facID = "";
	facName = "";
}

string Booking::getBookingID()
{
	return bookingID;
}

string Booking::getMemberID()
{
	return memberID;
}

string Booking::getDate()
{
	return date;
}

int Booking::getBookingStartTime()
{
	return bookingStartTime;
}

int Booking::getBookingEndTime()
{
	return bookingEndTime;
}

string Booking::getFacID()
{
	return facID;
}

string Booking::getFacName()
{
	return facName;
}

void Booking::setBookingID(string newID)
{
	bookingID = newID;
}

void Booking::setMemberID(string newID)
{
	memberID = newID;
}

void Booking::setDate(string newDate)
{
	date = newDate;
}

void Booking::setBookingStartTime(int time)
{
	bookingStartTime = time;
}

void Booking::setBookingEndTime(int time)
{
	bookingEndTime = time;
}

void Booking::setFacID(string newID)
{
	facID = newID;
}

void Booking::setFacName(string newName)
{
	facName = newName;
}

