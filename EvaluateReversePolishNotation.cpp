/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/28/2015
File: DecodeWays.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>
#include "EvaluateReversePolishNotation1.h"

using namespace std;

int main(int argc, char* argv[])
{
    Math solution;
    vector<string> str = {"4", "13", "5", "/", "+"};

    try
    {
        int result = solution.EvaluateReversePolishNotation(str);

        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i].c_str() << " ";
        }
        cout << " = " << result << "\r\n";
    }
    catch (exception& e)
    {
        cout << e.what();
    }

	return 0;
}

