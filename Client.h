#pragma once
#include"StringUtl.h"
#include "Person.h"

class Client : public Person
{
protected:
    double balance;
public:
    //para. const.
    Client(int id, const string& name, const string& password, double balance)
        :Person(id, name, password),
        balance(Validation::validBalance(balance) ? balance : 1500.0)
    {
    }
    Client(int id, const string& name, const string& password)
        :Person(id, name, password), balance(1500.0)
    {
    }
    //copy const.
    Client(const Client& obj)
        :Person(obj.id, "Copy of " + obj.name, obj.password), balance(obj.balance)
    {
    }
    //getters
    double getBalance() const { return balance; }
    //setter
    void setBalance(double balance) { this->balance = balance; }
    //methods
    pair<double, bool> Deposit(double amount) {

        pair<double, bool> result;
        result.second = false;

        if (Validation::validAmount(amount))
        {
            result.second = true;

            balance += amount;
            result.first = balance;

            return result;
        }
        result.first = balance;
        return result;
    }

    pair<double, bool> Withdraw(double amount) {

        pair<double, bool> result;
        result.second = false;

        if (Validation::validAmount(amount, balance))
        {
            result.second = true;

            balance -= amount;
            result.first = balance;

            return result;
        }
        result.first = balance;
        return result;
    }

    string operationStatus(pair<double, bool> operation)
        const {
        if (operation.second)
            return "Operation successful, your balance is: " + StringUtl::to_string_deluxe(balance);
        else
            return"Operation failed, your balance is: " + StringUtl::to_string_deluxe(balance);
    }

    pair<double, bool> transferTo(double amount, Client& recipient)
    {
        pair<double, bool> result;
        result.second = false;

        if (Validation::validAmount(amount, balance))
        {
            if (Withdraw(amount).second)
            {
                recipient.Deposit(amount);
                result.second = true;
            }
            result.first = balance;
            return result;
        }
        result.first = balance;
        return result;
    }
    string checkBalance() const {
        return "\nBalance: " + StringUtl::to_string_deluxe(balance);
    }
    string display_info() const
    {
        return Person::display_info()
            + "\nBalance: " + StringUtl::to_string_deluxe(balance) + "\n";
    }
    void Display() const {
        cout << display_info() << endl;
    }


};