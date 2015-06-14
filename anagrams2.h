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
		typedef map<string, vector<int>> MAP;
		MAP strmap;
		vector<string> result;

		for (unsigned int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());

			strmap[s].push_back(i);
		}

		for (MAP::iterator it = strmap.begin(); it != strmap.end(); it++)
		{
			if (it->second.size() > 1)
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					result.push_back(strs[it->second[i]]);
				}
				result.push_back("\r\n");
			}
		}

		return result;
	}
};