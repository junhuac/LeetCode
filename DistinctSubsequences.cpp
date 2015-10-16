// DistinctSubsequences.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "DistinctSubsequences1.h"

using namespace std;

int main(int argc, char* argv[])
{
    string S("rabbbit");
    string T("rabbit");

    Solution solution;

    int result = solution.DistinctSubsequences(S, T);
    cout << S.c_str() << "\r\n";
    cout << T.c_str() << "\r\n";
    cout << result << "\r\n";

	return 0;
}

