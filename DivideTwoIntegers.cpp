// DivideTwoIntegers.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "DivideTwoIntegers1.h"

using namespace std;

int main(int argc, char* argv[])
{
    Solution solution;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int result = solution.DivideTwoIntegers(i, j);
            cout << i << "/" << j << " = " << result << "\r\n";
        }
    }

	return 0;
}

