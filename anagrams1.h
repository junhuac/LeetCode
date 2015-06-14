#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Anagrams
{
public:
	Anagrams() {}

	// Returns strings which are anagrams
	vector<string> anagrams(vector<string> strs)
	{
		map<string, int> strmap;
		vector<string> result;

		for (int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());

			if (strmap.find(s) == strmap.end())
			{
				strmap[s] = i;
			}
			else
			{
				if (strmap[s] > -1)
				{
					result.push_back(strs[strmap[s]]);
					strmap[s] = -1;
				}
				result.push_back(strs[i]);
			}
		}

		return result;
	}
};