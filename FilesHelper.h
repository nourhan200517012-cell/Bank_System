#pragma once
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Parser.h"
#include"Employee.h"
using namespace std;
class FilesHelper
{
public:
	static void saveLast(string fileName, int id) {
		ofstream file (fileName, ios::out);
		if (file.is_open()) {
			file << id;
		}
		file.close();
	}
	static int getLast(string fileName){
		ifstream file(fileName, ios::in);
		string s;
		int id = 0;
		if (file.is_open()) {
			if (getline(file, s)) {
				id = stoi(s);
			}
			file.close();
		}
		return id;
	}
	static void saveClient(const Client& c){
		ofstream file("Client.txt", ios::app);
		int id = getLast("lastIdClient.txt") + 1;
		if (file.is_open())
		{
			file << id << "|"
				<< c.getName() << "|"
				<< c.getPassword() << "|"
				<< c.getBalance() << endl;
			file.close();

		}
		saveLast("lastIdClient.txt", id);
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		ofstream file(fileName, ios::app);
		int id = getLast(fileName) + 1;
		if (file.is_open())
		{
			file << id << "|"
				<< e.getName() << "|"
				<< e.getPassword() << "|"
				<< e.getSalary() << endl;
			file.close();
		}
		saveLast(lastIdFile, id); //
	}
	static 	vector<Client> getAllClients() {
		vector<Client> clients;
		fstream client_file("client.txt", ios::in);
		string s;
		if (client_file.is_open()) {
			while (getline(client_file, s)) {
				Client c = parser::parseToClient(s);
				clients.push_back(c);
			}
			client_file.close();
		}
		
		return clients;

	}
	static vector<Employee> getAllEmployees() {
		vector<Employee> employee;
		fstream employee_file("employee.txt", ios::in);
		string s;
		if (employee_file.is_open()) {
			while (getline(employee_file, s)) {
				Employee c = parser::parseToEmployee(s);
				employee.push_back(c);
			}
			employee_file.close();
		}
		
		return employee;
	}
	static vector<Admin> getAllAdmins() {
		vector<Admin> admin;
		fstream admin_file("admin.txt", ios::in);
		string s;
		if (admin_file.is_open()) {
			while (getline(admin_file, s)) {
				Admin c = parser::parseToAdmin(s);
				admin.push_back(c);
			}
		}
		admin_file.close();
		return admin;


	}
	static void clearFile(string fileName, string lastIdFile){
		ofstream file(fileName, ios::out);
		file.close(); //
		saveLast(lastIdFile, 0);
	}
};

