#ifndef AUTHENTICATE_H_
#define AUTHENTICATE_H__H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Authenticate
{
	public:
		string validateUser(string username, string password);
		void loadData();
		vector<string> split(const string &s, char delim, vector<string> &linesplit);
	private:
		vector<string> vectuser;
		vector<string> vectpw;
		vector<string> vectEUser;
		vector<string> vectEPw;
};

#endif /* AUTHENTICATE_H_ */
