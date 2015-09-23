/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/23/2015
File: CompareVersionNumbers.cpp
Purpose: Defines the entry point for the CompareVersionNumbers console application.
*/

#include <iostream>

#include "CompareVersionNumbers1.h"

using namespace std;

const int NUM = 6;

int main(int argc, char* argv[])
{
	Solution solution;

    string v1[NUM] = { "0", "1", "0", "0.1", "1.0", "1.2.3" };
    string v2[NUM] = { "0", "0", "1", "1", "0.1", "2.1" };

    for (int i = 0; i < NUM; i++)
    {
        int result = solution.CompareVersionNumbers(v1[i], v2[i]);

        cout << v1[i].c_str() << "\t" << v2[i].c_str() << "\tResult:\t";
        cout << result;
        cout << "\r\n";
    }

	return 0;
}

