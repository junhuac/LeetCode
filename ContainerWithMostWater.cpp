/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
File: ContainerWithMostWater.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "ContainerWithMostWater1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Solution solution;

    vector<int> container = { 4, 2, 1, 3, 5, 6, 7 };
  
    vector<int> result = solution.ContainerWithMostWater(container);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }

	return 0;
}

