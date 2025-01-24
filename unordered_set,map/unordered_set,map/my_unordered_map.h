#pragma once
#include "hash_bucket.h"
namespace Ely
{
	template<class K,class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT 
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<const K,V>, MapKeyOfT,Hash>::HtIterator iterator;
		typedef typename HashTable<K, pair<const K,V>, MapKeyOfT, Hash>::Const_HtIterator const_iterator;
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		iterator Find(const K& key)
		{
			returniterator(_ht.Find(key), *_ht);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		HashTable<K, pair<const K, V>, MapKeyOfT,Hash> _ht;
	};

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert({ "sort", "ÅÅĞò" });
		dict.insert({ "left", "×ó±ß" });
		dict.insert({ "right", "ÓÒ±ß" });
		dict["left"] = "×ó±ß£¬Ê£Óà";
		dict["insert"] = "²åÈë";
		dict["string"];
		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			// ²»ÄÜĞŞ¸Äfirst£¬¿ÉÒÔĞŞ¸Äsecond
			//it->first += 'x';it->second += 'x';
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}