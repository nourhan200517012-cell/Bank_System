#pragma once
#include<vector>
#include "Person.h"
#include "Client.h"

class Employee : public Person
{
protected:
    double salary;
    vector<Client> clients;

public:

    Employee(int id, const string& name, const string& password, double salary)
        : Person(id, name, password), salary(salary)
    {
    }
    double getSalary()const { return salary; }
    void setSalary(double salary) {
        if (Validation::validSalary(salary)) this->salary = salary;
        else cout << "Invalid salary!!";
    }
    void empLogin(int id, const string& password) const {
        if (this->id == id && this->password == password)
            cout << "Login successful!" << endl;
        else
            cout << "Invalid id or password!" << endl;
    }
    void addClient(const Client& client) {
        clients.push_back(client); //
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
    void displayInfo() const {
        cout << "Employee ID: " << id
            << " | Name: " << name
            << " | Salary: " << salary << endl;
    }
};