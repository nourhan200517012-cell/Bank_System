#pragma once
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include<fstream>
#include<vector>


class DataSourceInterface
{
public:

	virtual  void addClient(const Client& client) = 0;
	virtual  void addEmployee(const Employee& employee) = 0;
	virtual void addAdmin(const Admin& admin) = 0;
	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployees() = 0;
	virtual  vector<Admin> getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
	virtual ~DataSourceInterface() {}
};

