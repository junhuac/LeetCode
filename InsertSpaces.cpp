/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
File: DecodeWays.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>
#include <set>

using namespace std;

set<string> dictionary = {"i", "eat", "food"};

bool isWord(string word)
{
    return dictionary.find(word) != dictionary.end();
}

#include "InsertSpaces.h"

int main(int argc, char* argv[])
{
	Solution solution;
    string str = "ieatfood";

    try
    {
        string str2 = solution.InsertSpaces(str);

        cout << str2.c_str() << "\r\n";
    }
    catch (exception& e)
    {
        cout << e.what();
    }

	return 0;
}

