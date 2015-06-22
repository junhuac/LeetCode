/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 06/17/2015
Problem: 
	We have a mobile application making a web service call to our web service API.
	This mobile application is widely adopted and we expect high traffic to our web service.

	Service API:
	Public Facing Service operation :  String getMobileAd(String userId)
	Internal Admin Service operation : Map<String, Integer> getTopUsers()

	Maintain a realtime list of top 100 users calling our API getMobileAd(). 
	Write code to maintain this list.
	Assume a single host deployment
*/

#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef map<string, int> MAP;

class MobileAd
{
public:
	MobileAd() {}
	MobileAd(vector<string> Ad) { m_Ad = Ad; }
	~MobileAd() {}

	string getMobileAd(string userId)
	{
		static int index = 0;

		//EnterCriticalSection();
		m_AllUsers[userId]++;
		//LeaveCriticalSection();

		return m_Ad[index++ % m_Ad.size()];
	}

	MAP getTopUsers()
	{
		MAP TopUsers;
		vector<int> Frequencies;

		if (m_AllUsers.size() <= 100)
		{
			return m_AllUsers;
		}

		for (MAP::iterator it = m_AllUsers.begin(); it != m_AllUsers.end(); it++)
		{
			Frequencies.push_back(it->second);
		}

		sort(Frequencies.begin(), Frequencies.end());


		for (MAP::iterator it = m_AllUsers.begin(); it != m_AllUsers.end(); it++)
		{
			if (it->second >= Frequencies[Frequencies.size() - 100])
			{
				TopUsers[it->first] = it->second;
			}
		}

		return TopUsers;
	}

private:
	vector<string> m_Ad;
	MAP m_AllUsers;
};