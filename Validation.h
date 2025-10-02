#pragma once
#include<iostream>
#include<string>
using namespace std;

class Validation
{
public:
    static bool validName(const string& name)
    {
        if (name.size() < 5 || name.size() > 20) return false;

        for (char c : name) { //for each loop to traverse over the string 
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }




    static bool validPassword(const string& password)
    {
        if (password.size() < 8 || password.size() > 20) return false;

        return true;
    }



    static bool validBalance(double balance)
    {
        return (balance >= 1500);
    }
    static bool validSalary(double salary)
    {
        return (salary >= 5000);
    }
    static bool validAmount(double amount)
    {
        return (amount > 0);
    }
    static bool validAmount(double amount, double balance)
    {
        return (amount > 0 && amount <= balance);
    }



};