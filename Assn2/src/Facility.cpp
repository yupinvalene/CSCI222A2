#include "Facility.h"

Facility::Facility()
{

}

Facility::Facility(string facID, string facName, string facAddress, long facOperationStartTime, long facOperationEndTime, bool available)
{
	this->facID = facID;
	this->facName = facName;
	this->facAddress = facAddress;
	this->facOperationStartTime = facOperationStartTime;
	this->facOperationEndTime = facOperationEndTime;
	this->available = available;
}

string Facility::getFacID()
{
	return facID;
}

void Facility::setFacID(string facID)
{
	this->facID = facID;
}


string Facility::getFacName()
{
	return facID;
}

void Facility::setFacName(string facName)
{
	this->facName = facName;
}

string Facility::getFacAddress()
{
	return facAddress;
}

void Facility::setFacAddress(string facAddress)
{
	this->facAddress = facAddress;
}

long Facility::getFacOperationStartTime()
{
	return facOperationStartTime;
}

void Facility::setFacOperationStartTime(long facOperationStartTime)
{
	this->facOperationStartTime = facOperationStartTime;
}

long Facility::getFacOperationEndTime()
{
	return facOperationEndTime;
}

void Facility::setFacOperationEndTime(long facOperationEndTime)
{
	this->facOperationEndTime = facOperationEndTime;
}

bool Facility::getAvailable()
{
	return available;
}

void Facility::setAvailable(bool available)
{
	this->available = available;
}
