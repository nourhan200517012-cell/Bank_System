#pragma once
#include "Person.h"
#include "Employee.h"
#include<fstream>

class Admin : public Employee
{
    vector<Client> clients;
    vector<Employee> employees;
public:

    Admin(int id, const string& name, const string& password, double salary)
        : Employee(id, name, password, salary)
    {
    }
    string display_info() const override {
        return Person::display_info() + ", Salary: " + to_string(salary);
    }
    void savetofile() {

        ofstream admin("admin.txt", ios::app);
        if (admin.is_open()) {
            admin << getId() << "," << getName() << "," << getPassword() << "\n";
            admin.close();
            cout << "Admin saved to file successfully!" << endl;
        }
        else {
            cout << "Error: Could not open file." << endl;
        }
    }
    void addClient(const Client& client) {
        clients.push_back(client);
    }
    Client* searchClient(int id) {
        for (Client& client : clients) {
            if (client.getId() == id)
                return &client;
        }
        return nullptr;
    }
    void listClients() {
        if (clients.empty()) {
            cout << "No clients found!" << endl;
            return;
        }
        for (Client& client : clients) {
            cout << "ID: " << client.getId()
                << " | Name: " << client.getName()
                << " | Password: " << client.getPassword()
                << " | Balance: " << client.getBalance() << endl;
        }
    }
    void editClient(int id, const string& newName, const string& newPassword, double newBalance) {
        for (Client& client : clients) { //for each
            if (client.getId() == id) {
                client.setName(newName);
                client.setPassword(newPassword);
                client.setBalance(newBalance);
                cout << "Client info updated successfully!" << endl;
                return;
            }
        }
        cout << "Client not found!" << endl;
    }
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }
    Employee* searchEmployee(int id) {
        for (Employee& employee : employees) {
            if (employee.getId() == id)
                return &employee;
        }
        return nullptr;
    }
    void editEmployee(int id, const string& newName, const string& newPassword, double newSalary) {
        for (Employee& employee : employees) { //for each
            if (employee.getId() == id) {
                employee.setName(newName);
                employee.setPassword(newPassword);
                employee.setSalary(newSalary);
                cout << "Employee info updated successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }
    void listEmployees() {
        if (employees.empty()) {
            cout << "No Employee found!" << endl;
            return;
        }
        for (Employee& employee : employees) {
            cout << "ID: " << employee.getId()
                << " | Name: " << employee.getName()
                << " | Password: " << employee.getPassword()
                << " | Salary: " << employee.getSalary() << endl;
        }
    }
};