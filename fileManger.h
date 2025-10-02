#pragma once
#include "DataSourceInterface.h"
#include<fstream>
#include"Client.h"
#include"Person.h"
#include<string>
#include"Parser.h"
class fileManger :public DataSourceInterface
{
public:
	void addClient(const Client& client) {  //
		fstream client_file("client.txt", ios::app);
		if (client_file.is_open()) {
			client_file << client.getId() << "|"
				<< client.getName() << "|"
				<< client.getPassword() << "|"
				<< client.getBalance() << endl;
		}
		client_file.close();
	}
	void addEmployee(const Employee& employee) {
		fstream employee_file("employee.txt", ios::app);
		if (employee_file.is_open()) {
			employee_file << employee.getId() << "|"
				<< employee.getName() << "|"
				<< employee.getPassword() << "|"
				<< employee.getSalary() << endl;
		}
		employee_file.close();
	}
	void addAdmin(const Admin& admin) {
		fstream admin_file("admin.txt", ios::app);
		if (admin_file.is_open()) {
			admin_file << admin.getId() << "|"
				<< admin.getName() << "|"
				<< admin.getPassword() << "|"
				<< admin.getSalary() << endl;
		}
		admin_file.close();
	}
	vector<Client> getAllClients() {
		vector<Client> clients;
		fstream client_file("client.txt", ios::in);
		string s;
		if (client_file.is_open()) {
			while (getline(client_file, s)) {
				Client c = parser::parseToClient(s);
				clients.push_back(c);
			}
		}
		client_file.close();
		return clients;

	}
	vector<Employee> getAllEmployees() {
		vector<Employee> employee;
		fstream employee_file("employee.txt", ios::in);
		string s;
		if (employee_file.is_open()) {
			while (getline(employee_file, s)) {
				Employee c = parser::parseToEmployee(s);
				employee.push_back(c);
			}
		}
		employee_file.close();
		return employee;
	}
	vector<Admin> getAllAdmins() {
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



	void removeAllClients() {
		fstream client_file("client.txt", ios::out);
		client_file.close();
	}
	void removeAllEmployees() {
		fstream employee_file("employee.txt", ios::out);
		employee_file.close();
	}
	void removeAllAdmins() {
		fstream admin_file("admin.txt", ios::out);
		admin_file.close();
	}

};

