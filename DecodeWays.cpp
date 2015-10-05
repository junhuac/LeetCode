/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
File: DecodeWays.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "DecodeWays1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Solution solution;

    const int NUM = 5;
    string msgs[NUM] = { "1", "2", "12", "123", "1234" };

    for (int i = 0; i < NUM; i++)
    {
        int n = solution.DecodeWays(msgs[i]);

        cout << msgs[i] << ": " << n << "\r\n";
    }

	return 0;
}

