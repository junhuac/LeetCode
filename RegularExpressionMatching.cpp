// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#include "RegularExpressionMatching1.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	string s, p;
	bool result = false;

	s = "aa";
	p = "a";

	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	result = solution.isMatch(s, p);

	// Get ending timepoint 
	auto stop = high_resolution_clock::now();

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

	cout << s  << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "aa";
	p = "a*";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "ab";
	p = ".*";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "aab";
	p = "c*a*b";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "mississippi";
	p = "mis*is*p*.";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "aaca";
	p = "ab*a*c*a";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "a";
	p = "ab*";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "bbbba";
	p = ".*a*a";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "aaa";
	p = "ab*a";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "";
	p = "c*c*";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	s = "bcbabcaacacbcabac";
	p = "a*c*a*b*.*aa*c*a*a*";

	// Get starting timepoint 
	start = high_resolution_clock::now();

	result = solution.isMatch(s, p);

	// Get ending timepoint 
	stop = high_resolution_clock::now();

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;
		
	s = "a";
	p = ".*..a*";

	result = solution.isMatch(s, p);

	cout << s << "\t" << p << "\t" << result << "\t" << regex_match(s, regex(p)) << endl;

	return 0;
}

