#pragma once
#include <iostream>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;

namespace ELY
{
	class string
	{
	friend ostream& operator<<(ostream& _cout, const ELY::string& s);
	friend istream& operator>>(istream& _cin, ELY::string& s);
	public:
		using iterator = char*;

		string();
		string(const char* s);
		string(const string& s);
		string& operator=(const string& s);
		string& operator=(const char* s);
		~string();

		//iterator

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const iterator begin() const
		{
			return _str;
		}
		const iterator end() const
		{
			return _str + _size;
		}
		//modify
		void push_back(char c);

		string& operator+=(char c)
		{
			(*this).push_back(c);
			return *this;
		}
		void append(const char* str);
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void clear()
		{
			memset(_str, '\0', _size + 1);
			_size = 0;
		}
		void swap(string& s)
		{
			string s1 = *this;
			*this = s;
			s = s1;
		}
		const char* c_str()const
		{
			return _str;
		}
		//capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			assert(_str);
			return (_size > 0);
		}
		void resize(size_t n, char c = '\0');
		void reserve(size_t n);

		//access
		char& operator[](size_t n)
		{
			assert(n >= 0 && n < _size - 1);
			return _str[n];
		}
		const char& operator[](size_t n)const
		{
			assert(n >= 0 && n < _size);
			return _str[n];
		}

		//relational operators
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len = npos);

		string substr(size_t pos, size_t len = npos);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos = -1;
	};

}
