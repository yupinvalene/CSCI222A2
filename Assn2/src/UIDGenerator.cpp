/*
 * UIDGenerator.cpp
 *
 *  Created on: 20 Feb 2016
 *      Author: chingyeow
 */

#include "UIDGenerator.h"

UIDGenerator::UIDGenerator() {
}

UIDGenerator::~UIDGenerator() {
}

string UIDGenerator::generate(vector<string> existUID)
{
	srand(time(NULL));
	int randomNo1;
	int randomNo2;
	ostringstream ss;


	randomNo1 = rand() % 9000 + 1000;
	randomNo2 = rand() % 9000 + 1000;

	ss << randomNo1;
	ss << randomNo2;

	return ss.str();

}
