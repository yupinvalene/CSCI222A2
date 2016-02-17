/*
 * Notification.h
 *
 *  Created on: 17 Feb 2016
 *      Author: yupin
 */

#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Notification{
	public:

	Notification();
	Notification(string, string, string, string, string, string, string);
	~Notification();

	string getMessage();
	string getNotificationID();
	string getMemberID();
	string getDay();
	string getMonth();
	string getYear();
	string getTime();

	void setMessage(string);
	void setNotificationID(string);
	void setMemberID(string);
	void setDay(string);
	void setMonth(string);
	void setYear(string);
	void setTime(string);

	void toString();


	private:
	string message;
	string notificationID;
	string memberID;
	string day;
	string month;
	string year;
	string time;

};



#endif /* NOTIFICATION_H_ */
