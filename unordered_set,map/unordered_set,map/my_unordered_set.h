#pragma once
#include "hash_bucket.h"

namespace Ely
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename HashTable<K, const K, SetKeyOfT,Hash>::HtIterator iterator;
		typedef typename HashTable<K, const K, SetKeyOfT,Hash>::Const_HtIterator const_iterator;
		pair<iterator,bool> insert(const K& key)
		{
			return _ht.Insert(key);
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
			return iterator(_ht.Find(key),*_ht);
		}
	private:
		HashTable<K,const K, SetKeyOfT,Hash> _ht;
	};

	void test_set()
	{
		unordered_set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3,3,15 };
		for (auto e : a)
		{
			s.insert(e);
		}
		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			// 不支持修改
			//*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}