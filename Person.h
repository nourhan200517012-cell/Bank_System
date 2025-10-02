#pragma once
#include"Validation.h"

class Person
{
protected:
    string name, password;
    int id;
public:
    //para. const.
    Person(int id, const string& name, const string& password)
        : id(id), name(name), password(password)
    {
    }
    //setters
    void setName(const string& name) {
        if (Validation::validName(name)) this->name = name;
        else cout << "Invalid name!!";
    }
    void setPassword(const string& password) {
        if (Validation::validPassword(password)) this->password = password;
        else cout << "Invalid password!!";
    }
    //getters
    const string& getName() const { return name; }
    const string& getPassword() const { return password; }
    int getId() const { return id; }

    //method
    virtual string display_info() const
    {
        return "ID: " + to_string(id)
            + "\nName: " + name;
    }
    virtual void Display() const {
        cout << "ID: " + to_string(id) << "\nName: " + name;
    }
};