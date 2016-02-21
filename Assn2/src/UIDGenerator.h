/*
 * UIDGenerator.h
 *
 *  Created on: 20 Feb 2016
 *      Author: yupinvalene
 */

#ifndef SRC_UIDGENERATOR_H_
#define SRC_UIDGENERATOR_H_

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>


using namespace std;

class UIDGenerator {
public:
	UIDGenerator();
	virtual ~UIDGenerator();

	static string generate();
};

#endif /* SRC_UIDGENERATOR_H_ */
