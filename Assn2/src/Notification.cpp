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
	this -> memberID = memberID;
	this -> day = day;
	this -> month = month;
	this -> year = year;
	this -> time = time;

}

Notification::~Notification() {
}

string Notification::getMessage() {
	return message;
}

string Notification::getNotificationID() {
	return notificationID;
}

string Notification::getMemberID() {
	return memberID;
}

string Notification::getDay() {
	return day;
}

string Notification::getMonth() {
	return month;
}

string Notification::getYear() {
	return year;
}

string Notification::getTime() {
	return time;
}

void Notification::setMessage(string message) {
	this -> message = message;
}

void Notification::setNotificationID(string notificationID) {
	this -> notificationID = notificationID;
}

void Notification::setMemberID(string memberID) {
	this -> memberID = memberID;
}

void Notification::setDay(string day) {
	this -> day = day;
}

void Notification::setMonth(string month) {
	this -> month = month;
}

void Notification::setYear(string year) {
	this -> year = year;
}

void Notification::setTime(string time) {
	this -> time = time;
}

void Notification::toString() {
	cout << "Message: " << message << endl
		 << "NotificationID: " << notificationID << endl
		 << "MemberID: " << memberID << endl
		 << "Day: " << day << endl
		 << "Month: " << month << endl
		 << "Year: " << year << endl
		 << "Time: " << time << endl << endl;
}
