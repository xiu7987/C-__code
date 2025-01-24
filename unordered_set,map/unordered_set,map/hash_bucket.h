#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class K, class T, class KeyOfSet, class Hash = HashFunc<K>>
class HashTable;

template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;
	HashNode(const T& data)
		:_data(data)
		, _next(nullptr)
	{}
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 131;
			hash += e;
		}
		return hash;
	}
};

template<class K,class T,class KeyOfSet,class Ref,class Ptr,class Hash = HashFunc<K>>
struct HashIterator
{
	typedef HashIterator<K, T, KeyOfSet, Ref, Ptr, Hash> Self;
	typedef HashNode<T> Node;
	typedef HashTable<K, T, KeyOfSet, Hash> HTable;
	Node* _node;
	const HTable* _ht;

	HashIterator(Node* node,HTable* ht)
		:_node(node)
		,_ht(ht)
	{}

	Self& operator++()
	{
		if (_node->_next != nullptr)
		{
			_node = _node->_next;
		}
		else
		{
			KeyOfSet ks;
			Hash hs;
			size_t pos = hs(ks(_node->_data)) % _ht->_tables.size();
			pos += 1;
			while (pos < _ht->_tables.size() && _ht->_tables[pos] == nullptr)
			{
				++pos;
			}
			
			if (pos < _ht->_tables.size())
			{
				_node = _ht->_tables[pos];
			}
			else _node = nullptr;
		}
		return *this;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}
};

template<class K, class T,class KeyOfSet ,class Hash>
class HashTable
{
	template<class K, class T, class KeyOfSet, class Ref, class Ptr, class Hash>
	friend struct HashIterator;
	typedef HashNode<T> Node;
	inline unsigned long __stl_next_prime(unsigned long n)
	{
		// Note: assumes long is at least 32 bits.
		static const int __stl_num_primes = 28;
		static const unsigned long __stl_prime_list[__stl_num_primes] = {
			53, 97, 193, 389, 769,
			1543, 3079, 6151, 12289, 24593,
			49157, 98317, 196613, 393241, 786433,
			1572869, 3145739, 6291469, 12582917, 25165843,
			50331653, 100663319, 201326611, 402653189, 805306457,
			1610612741, 3221225473, 4294967291
		};
		const unsigned long* first = __stl_prime_list;
		const unsigned long* last = __stl_prime_list + __stl_num_primes;
		const unsigned long* pos = lower_bound(first, last, n);
		return pos == last ? *(last - 1) : *pos;
	}
public:
	typedef HashIterator<K, T, KeyOfSet, T&, T*, Hash> HtIterator;
	typedef HashIterator<K, T, KeyOfSet, const T&, const T*, Hash> Const_HtIterator;
	HtIterator begin()
	{
		Node* cur = nullptr;
		for (int i = 0; i < _tables.size(); i++)
		{
			if (_tables[i])
			{
				cur = _tables[i];
				break;
			}
		}
		return HtIterator(cur, this);
	}

	HtIterator end()
	{
		return HtIterator(nullptr, this);
	}

	Const_HtIterator begin() const
	{
		Node* cur = nullptr;
		for (int i = 0; i < _tables.size(); i++)
		{
			if (_tables[i])
			{
				cur = _tables[i];
				break;
			}
		}
		return Const_HtIterator(cur, this);
	}

	Const_HtIterator end() const
	{
		return Const_HtIterator(nullptr, this);
	}

	HashTable()
	{
		_tables.resize(__stl_next_prime(_tables.size()), nullptr);
	}

	pair<HtIterator,bool> Insert(const T& data)
	{
		KeyOfSet kt;
		HtIterator it = HtIterator(Find(kt(data)),this);
		if (it != end())
			return make_pair(it, false);
		Hash hs;
		size_t hashi = hs(kt(data)) % _tables.size();
		// 负载因子为1扩容
		if (_n == _tables.size())
		{
			vector<Node*> newtables(__stl_next_prime(_tables.size()), nullptr);
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					size_t hashi = hs(kt(cur->_data)) % newtables.size();
					cur->_next = newtables[hashi];
					newtables[hashi] = cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_tables.swap(newtables);
		}

		Node* newnode = new Node(data);
		newnode->_next = _tables[hashi];
		_tables[hashi] = newnode;
		++_n;
		return make_pair(HtIterator(newnode,this), true);
	}

	Node* Find(const K& key)
	{
		Hash hs;
		size_t hashi = hs(key) % _tables.size();
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (KeyOfSet()(cur->_data) == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		Hash hs;
		size_t hashi = hs(key) % _tables.size();
		Node* prev = nullptr;
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				if (prev == nullptr)
				{
					_tables[hashi] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}
				delete cur;
				--_n;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}

	~HashTable()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_tables[i] = nullptr;
		}
	}
private:
	vector<Node*> _tables;
	size_t _n = 0;
};
