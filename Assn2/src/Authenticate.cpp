#include "Authenticate.h"

string Authenticate::validateUser(string username, string password)
{
	// note: username is memberID
	Authenticate auth;
	string result;
	int i = 0;

	for(string s : vectuser)
	{
		if(s == username)
		{
			if(vectpw[i] == password)
			{
				result = "Member";
				return result;
			}
		}
		i++;
	}
	// Codes for verifying employee // Need EmployeeDatabase.txt
	/*
	for(string s : vectEUser)
	{
		if(s == username)
		{
			if(vectEPw[i] == password)
			{
				result = "Employee";
				return result;
			}
		}
		i++;
	}
	*/

	result = "Failed";
	return result;
}

void Authenticate::loadData()
{
	Authenticate auth;
	string data;
	ifstream datafile;
	datafile.open("MemberDatabase.txt");
	getline(datafile, data, '\0'); // read the whole text file as string

	string delimiter = "\n";
	char delim = ':';
	size_t pos = 0;
	size_t pos2 = 0;
	string line;

	string id, name, add;
	long sTime, eTime;
	int avail;
	vector<string> linesplit;

	while ((pos = data.find(delimiter)) != string::npos) // split the data string by \n delimiter
	{
	    line = data.substr(0, pos);
	    auth.split(line, delim, linesplit);
	    data.erase(0, pos + delimiter.length());
	}
	int size = linesplit.size();
	for(int i = 2; i < size; i+=8)
	{
		string user = linesplit[i];
		vectuser.push_back(user);
	}
	for(int j = 3; j < size; j+=8)
	{
		string pw = linesplit[j];
		vectpw.push_back(pw);
	}
	datafile.close();

	// Codes for Employee // Need EmployeeDatabase.txt // Still need edit once received employee database // edit int i and int j
	/*
	datafile.open("EmployeeDatabase.txt");
	getline(datafile, data, '\0'); // read the whole text file as string

	while ((pos = data.find(delimiter)) != string::npos) // split the data string by \n delimiter
	{
	    line = data.substr(0, pos);
	    auth.split(line, delim, linesplit);
	    data.erase(0, pos + delimiter.length());
	}
	int size = linesplit.size();
	for(int i = 0; i < size; i+=8)
	{
		string user = linesplit[i];
		vectEUser.push_back(user);
	}
	for(int j = 3; j < size; j+=8)
	{
		string pw = linesplit[j];
		vectEPw.push_back(pw);
	}
	datafile.close();
	*/
}

vector<string> Authenticate::split(const string &s, char delim, vector<string> &linesplit)
{
	stringstream ss(s);
	string item;
	while(getline(ss, item, delim))
	{
		linesplit.push_back(item);
	}
	return linesplit;
}

/*
int main()
{
	Authenticate auth;
	auth.loadData();
	string result = auth.validateUser("S4100023F", "qwerty");
	cout << result;
}
*/
