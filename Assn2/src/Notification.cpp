/*
 * Notification.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#include "Notification.h"

Notification::Notification() {
	message = "";
	notificationID = "";
	memberID = "";
	day = "";
	month = "";
	year = "";
	time = "";
}

Notification::Notification(string message, string notificationID,
		string memberID, string day, string month,
		string year, string time) {
	this -> message = message;
	this -> notificationID = notificationID;

}

Notification::~Notification() {
}

string Notification::getMessage() {
}

string Notification::getNotificationID() {
}

string Notification::getMemberID() {
}

string Notification::getDay() {
}

string Notification::getMonth() {
}

string Notification::getYear() {
}

string Notification::getTime() {
}

void Notification::setMessage(string allocator) {
}

void Notification::setNotificationID(string allocator) {
}

void Notification::setMemberID(string allocator) {
}

void Notification::setDay(string allocator) {
}

void Notification::setMonth(string allocator) {
}

void Notification::setYear(string allocator) {
}

void Notification::setTime(string allocator) {
}

void Notification::toString() {
}
