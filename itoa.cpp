/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/02/2015
File: itoa.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "itoa.h"

using namespace std;

int main(int argc, char* argv[])
{
    int test[] = { 0, -1, 1, 100, -100, 1414143124, -1414143124 };

    for (int i = 0; i < sizeof(test) / sizeof(int); i++)
    {
        char* result = itoa(test[i]);
        cout << test[i] << ": " << result << "\r\n";
        free(result);
    }

	return 0;
}

