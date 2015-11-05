// DiceOnYacht.cpp : Given a long string made of only 4 unique characters find the 2 most frequently occurring substring of length 10.
//

/*
If the length of string is n (n is astronomically big)
and length of substring is m (m is of the order of 10)
number of unique characters is k (k is small e.g. 4)
what is the runtime of your solution ?
What is the space requirement ?
What if we want X number of most frequently occurring substrings ?
runtime: O(n*log(m)) + O(n*log(x))
space : O(k**m)
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

list<string> FindSubstr(string Str) {
    map<string, int> m;
    int counters[2] = { 0, 0 };
    string strs[2];

    for (unsigned int i = 0; i < Str.length() - 10; i++) {
        string s = Str.substr(i, 10);

        int count = ++m[s];

        for (int j = 0; j < 2; j++)
        {
            if (count > counters[j])
            {
                counters[j] = count;
                strs[j] = s;
            }
        }
    }

    list<string> result;
    for (int j = 0; j < 2; j++)
    {
        result.push_back(strs[j]);
    }

    return result;
}

int main(int argc, char* argv[])
{
    string teststring = "abcdabcdabcdabcd";

    list<string> result = FindSubstr(teststring);

    for (list<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << (*it).c_str();
        cout << "\n";
    }
}


