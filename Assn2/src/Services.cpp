#include "Services.h"

Services::Services(){

	svcID = "";
	svcName = "";
	svcOperationStartTime = 0;
	svcOperationEndTime = 0;
	available = false;

}

Services::Services(string svcID, string svcName, float fee, long svcOperationStartTime, long svcOperationEndTime, bool available){

	this->svcID = svcID;
	this->svcName = svcName;
	this->svcOperationStartTime = svcOperationStartTime;
	this->svcOperationEndTime = svcOperationEndTime;
	this->available = available;
	this -> fee = fee;

}

Services::~Services(){

}

void Services::setSvcID(string svcID){

	this->svcID = svcID;

}

void Services::setSvcName(string svcName){

	this->svcName = svcName;

}

void Services::setSvcOperationStartTime(long svcOperationStartTime){

	this->svcOperationStartTime = svcOperationStartTime;

}

void Services::setFee(float) {
	this -> fee = fee;

}

void Services::setSvcOperationEndTime(long svcOperationEndTime){

	this->svcOperationEndTime = svcOperationEndTime;

}

void Services::setAvailable(bool available){

	this->available = available;

}

string Services::getSvcID(){

	return svcID;

}

float Services::getFee(){
	return fee;
}

string Services::getSvcName(){

	return svcName;

}

long Services::getSvcOperationStartTime(){

	return svcOperationStartTime;

}

long Services::getSvcOperationEndTime(){

	return svcOperationEndTime;

}

bool Services::getAvailable(){

	return available;

}
