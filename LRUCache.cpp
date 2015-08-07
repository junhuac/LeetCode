// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "LRUCache1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LRUCache<int, int> cache(3);

	cache.set(1, 1);
	cache.set(2, 2);
	cache.set(3, 3);
	cache.set(4, 4);

	for (int i = 1; i < 5; i++)
	{
		cout << i << ": ";
		if (cache.exists(i))
		{
			cout << cache.get(i);
		}
		else
		{
			cout << "N/A";
		}
		cout << "\r\n";
	}

	return 0;
}

