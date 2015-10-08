// LRUCache.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "NumberofBST.h"

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 1; i < 10; i++)
	{
        cout << i << ": " << NumofBST(i) << "\r\n";
	}

	return 0;
}

