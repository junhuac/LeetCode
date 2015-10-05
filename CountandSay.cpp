/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
File: CopyListwithRandomPointer.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "CountandSay1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Solution solution;

    for (int n = 0; n < 10; n++)
    {
        string result = solution.CountandSay(n);

        cout << n << ": " << result << "\r\n";
    }

	return 0;
}

