#include "Facility.h"

Facility::Facility()
{

}

Facility::Facility(facID, facName, facAddress, facOperationStartTime, facOperationEndTime, hourlyRate, available)
{
	this->facID = facID;
	this->facName = facName;
	this->facAddress = facAddress;
	this->facOperationStartTime = facOperationStartTime;
	this->facOperationEndTime = facOperationEndTime;
	this->hourlyRate = hourlyRate;
	this->available = available;
}

Facility::~Facility()
{

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
float Facility::getHourlyRate()
{
	return hourlyRate;
}
void Facility::setHourlyRate(float hourlyRate)
{
	this->hourlyRate = hourlyRate;
}
bool Facility::getAvailable()
{
	return available;
}
void Facility::setAvailable(bool available)
{
	this->available = available;
}
