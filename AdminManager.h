#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Admin.h"
#include<fstream>
#include<sstream>
using namespace std;
class AdminManager
{
public:
	static void printEmployeeMenu() {

		cout << "Employee Menu:\n";
		cout << "1. Add Client\n";
		cout << "2. Search Client\n";
		cout << "3. Edit Client\n";
		cout << "4. List Clients\n";
		cout << "5. Logout\n";
	
	}
	static Admin* login(int id, string password) {

		 fstream  admin("admin.txt", ios::in);

		 if (!admin.is_open()) {
		
			 cout << "Couid not open file  " << endl;
			 
			 return nullptr;
		 }

		 string line;
		 
		 while (getline(admin, line)) {

			 stringstream s(line);

			 string sid, name, pass;

			 getline(s, sid, ',');
			 getline(s, name, ',');
			 getline(s, pass, ',');

			 int ID = stoi(sid);

			 if (id == ID && password == pass) {

				 return new Admin(ID, name, pass, 0.0);
			 
			 }
		 }
		 cout << "Invalid ID or Password!" << endl;
		 return nullptr;

	 }
	static bool AdminOptions(Client* client) {
		if (client == nullptr) {
			
			cout << "Client not found!" << endl;
			
			return false; 
		}
		int choise;

		cout << "Admin Options \n";
		cout << "1. View Client Info\n";
		cout << "2. Edit Client Info\n";
		cout << "3. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choise;
		switch (choise) {

		case 1: cout << "id: " << client->getId()
			<< endl << "name: " << client->getName()
			<< endl << "balance: " << client->getBalance() << endl;
			return true;

		case 2:
		{
			string newName, newPassword;
			double newBalance;
			
			cout << "Enter newName: \n";
			cin >> newName;
			cout << "Enter newpassword: \n ";
			cin >> newPassword;
			cout << "Enter newBalance: \n";
			cin >> newBalance;

			client->setName(newName);
			client->setPassword(newPassword);
			client->setBalance(newBalance);

			cout << "Client update. \n";
		}
			return true;
		
		case 3:

			return false;

		case 4:

			return true;
		}

	}

};

