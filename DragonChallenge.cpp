// DragonChallenge.cpp : Defines the entry point for the DragonChallenge console application.
//

#include "stdafx.h"
#include <iostream>

#include "DragonChallenge.h"

using namespace std;

const int maxdigits = 20;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	vector<int> valley;

    while (true)
    {
        char buf[maxdigits];
        int length;

        cin.getline(buf, maxdigits);

        if (isdigit(buf[0]))
        {
            length = atoi(buf);
            valley.push_back(length);
        }
        else
        {
            break;
        }
    }

    vector<int> flights = solution.DragonChallenge(valley);

    if (flights.size() == 0)
    {
        cout << "failure\r\n";
    }
    else
    {
        for (int i = 0; i < flights.size(); i++)
        {
            cout << flights[i] << ",";
        }
        cout << "out\r\n";
    }

	return 0;
}

