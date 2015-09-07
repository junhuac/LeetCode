/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/06/2015
File: TestDragonChallenge.cpp
Purpose: Defines the entry point for the unit test console application.
*/

#include <iostream>

#include "DragonChallenge.h"

using namespace std;

int main(int argc, char* argv[])
{
    Solution solution;
    vector<int> valley = { 5, 6, 0, 4, 2, 4, 1, 0, 0, 4 };
    vector<int> answer = { 0, 5, 9};

    vector<int> flights = solution.DragonChallenge(valley);

    if (flights == answer)
    {
        cout << "Tests have passed\r\n";
    }
    else
    {
        cout << "Tests have failed\r\n";
    }

	return 0;
}

