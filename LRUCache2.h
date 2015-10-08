/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/07/2015
Notes:
    // cache class
    // requirements:
    // 1. It can hold up to N elements
    // 2. If it's full and a caller is trying to add another unique element, least recently used (LRU) element is evicted
    //
    // Stages:
    // 1. Pick data structures to optimize for speed of basic operations
    // 2. Code up production quality public interface of the class
    // 3. Implement one of the methods
Solution: 
*/

#include <list>
#include <unordered_map>

using namespace std;

template<class K, class T>
class CacheNode
{
public:
    K key;
    T value;

    CacheNode(K k, T t) : key(k), value(t) {}
};

template<class K, class T>
class LRUCache
{
public:
    LRUCache(int size) : m_size(size) { }

    void set(K key, T obj)
    {
        if (m_map.find(key) == m_map.end())
        {
            // object not in the cache
            if (m_store.size() == m_size)
            {
                m_map.erase(m_store.back().value);
                m_store.pop_back();
            }
        }
        else
        {
            m_store.erase(m_map.find(key)->second);
        }

        m_store.insert(m_store.begin(), CacheNode<K, T>(key, obj));
        m_map[key] = m_store.begin();
    }

    bool exists(K key)
    {
        return m_map.find(key) != m_map.end();
    }

    T& get(K key)
    {
        if (m_map.find(key) != m_map.end())
        {
            return m_map[key]->value;
        }
        else
        {
            return *((T*)NULL);
        }
    }

    int size() { return m_store.size(); }

private:
    int m_size;
    list<CacheNode<K, T>> m_store;

    unordered_map<K, typename list<CacheNode<K, T>>::iterator> m_map;
};