/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 08/07/2015
Notes:
	Design and implement a data structure for Least Recently Used (LRU) cache.
	It should support the following operations: get and set.
	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
	exists(key) - Test if a key is in cache

	Time complexities of all methods should be O(1)

	Solution: Hash + list.
*/

#include <vector>

using namespace std;

template<typename TKey, typename TValue> class LRUCache
{
public:
	LRUCache(int size) : m_Size(size) {}
	~LRUCache() {}

	TValue get(TKey key)
	{
		for (int i = 0; i < m_Keys.size(); i++)
		{
			if (key == m_Keys[i])
			{
				return m_Values[i];
			}
		}

		return -1;
	}

	void set(TKey key, TValue value)
	{
		for (int i = 0; i < m_Keys.size(); i++)
		{
			if (key == m_Keys[i])
			{
				for (int j = i; j < m_Keys.size() - 1; j++)
				{
					m_Keys[j] = m_Keys[j + 1];
					m_Values[j] = m_Values[j + 1];
				}
				m_Keys[m_Keys.size() - 1] = key;
				m_Values[m_Values.size() - 1] = value;
				return;
			}
		}

		if (m_Size > m_Keys.size())
		{
			m_Keys.push_back(key);
			m_Values.push_back(value);
		}
		else
		{
			for (int i = 0; i < m_Keys.size() - 1; i++)
			{
				m_Keys[i] = m_Keys[i + 1];
				m_Values[i] = m_Values[i + 1];
			}
			m_Keys[m_Keys.size() - 1] = key;
			m_Values[m_Values.size() - 1] = value;
		}
	}

	bool exists(TKey key)
	{
		for (int i = 0; i < m_Keys.size(); i++)
		{
			if (key == m_Keys[i])
			{
				return true;
			}
		}

		return false;
	}

private:
	int m_Size;
	vector<TKey> m_Keys;
	vector<TValue> m_Values;
};