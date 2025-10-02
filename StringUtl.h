#pragma once
#include<iostream>
#include<string>
using namespace std;

class StringUtl
{
public:
    static string to_string_deluxe(double x) {

        string x_str = to_string(x);

        while (x_str.rfind('0') == x_str.size() - 1) {

            x_str.erase(x_str.rfind('0'), 1);
        }

        if (x_str.find('.') == x_str.size() - 1) x_str.erase(x_str.rfind('.'), 1);

        return x_str;
    }
};