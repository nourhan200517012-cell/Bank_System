#pragma once
#include <vector>
#include <string>
#include<sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class parser
{
public:

	static vector<string> split(const string& line) {
		vector<string>parts;
		string part;
		stringstream s(line);
		while (getline(s, part, '|')) {
			parts.push_back(part);
		}
		return parts;
	}
	static Client parseToClient(const string& line) {
		vector<string> parts = split(line);
		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		double balance = stod(parts[3]);

		return Client(id, name, password, balance);
	}
	static Employee parseToEmployee(const string& line) {
		vector<string>parts = split(line);
		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		double salary = stod(parts[3]);
		return Employee(id, name, password, salary);
	}
	static Admin parseToAdmin(const string& line) {
		vector<string>parts = split(line);
		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		double salary = stod(parts[3]);
		return Admin(id, name, password, salary);
	}
};
