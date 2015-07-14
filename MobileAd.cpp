// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "MobileAd.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	MobileAd solution(vector<string>({ "Ad 1", "Ad 2", "Ad 3", "Ad 4", "Ad 5"}));

	vector<string> Users;

	for (unsigned int i = 0; i < 120; i++)
	{
		char id[8];
		_itoa_s(i, id, 10);
		Users.push_back(string("User ") + id);
	}

	for (unsigned int i = 0; i < Users.size(); i++)
	{
		for (unsigned int j = 0; j < i; j++)
		{
			solution.getMobileAd(Users[i]);
		}
	}

	map<string, int> topusers = solution.getTopUsers();

	for (map<string, int>::iterator it = topusers.begin(); it != topusers.end(); it++)
	{
		cout << it->first << ":" << it->second << "\r\n";
	}

	return 0;
}

