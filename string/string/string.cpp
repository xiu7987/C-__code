#include "string.h"
namespace ELY 
{
	string::string()
		:_str(new char[15] {'\0'}),
		_size(0),
		_capacity(14)
	{}

	string::string(const char* s)
		:_size(strlen(s)),
		_capacity(strlen(s))
	{
		_str = new char[_capacity + 1];
		strcpy(_str, s);
	}

	string::string(const string& s)
		:_size(s._size),
		_capacity(s._capacity)
	{
		_str = new char[_capacity + 1];
		strcpy(_str, s._str);
	}

	string& string::operator=(const string& s)
	{
		if (_str != s._str) 
		{
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}

	string& string::operator=(const char* s)
	{
		while (strlen(s) > _capacity)
		{
			char* tmp = new char[(_capacity + 1) * 2] {'\0'};
			delete[] _str;
			_str = tmp;
			_capacity = (_capacity + 1) * 2 - 1;
		}
		strcpy(_str, s);
		_size = strlen(s);
		return *this;
	}

	string::~string()
	{
		delete[]_str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	//modify
	void string::push_back(char c)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : (_capacity+1) * 2 - 1);
		}

		_str[_size] = c;
		_size++;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		while(len + _size > _capacity)
		{
			char* tmp = new char[(_capacity + 1) * 2] {'\0'};
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = (_capacity + 1) * 2 - 1;
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	//capacity
	void string::resize(size_t n, char c)
	{
		if (n > _capacity)
		{
			reserve(n);
			for (size_t i = _size; i < _capacity; i++)
			{
				_str[i] = c;
			}
			_str[_capacity] = '\0';
			_size = _capacity;
		}
		else if (n >= _size && n <= _capacity)
		{
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = c;
				_size++;
			}
		}
		else if (n < _size)
		{
			_str[n] = '\0';
			_size = n;
		}
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1] {'\0'};
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	//relational operators
	bool string:: operator==(const string& s)
	{
		return (strcmp(_str, s._str) == 0);
	}

	bool string:: operator!=(const string& s)
	{
		return !(*this == s);
	}

	bool string::operator<(const string& s)
	{
		return (strcmp(s._str, _str) < 0);
	}

	bool string::operator<=(const string& s)
	{
		return !(*this > s);
	}

	bool string::operator>(const string& s)
	{
		return (strcmp(s._str, _str) > 0);
	}

	bool string::operator>=(const string& s)
	{
		return !(*this < s);
	}

	//find
	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; _str[i]; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}

	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, s);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}

	//insert
	string& string::insert(size_t pos, char c)
	{
		assert(pos <= _size);
		while (_size + 1 > _capacity)
		{
			char* tmp = new char[(_capacity + 1) * 2] {'\0'};
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = (_capacity + 1) * 2 - 1;
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = c;
		_size += 1;
		return *this;
	}

	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		while (_size +  len > _capacity)
		{
			char* tmp = new char[(_capacity + 1) * 2] {'\0'};
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = (_capacity + 1) * 2 - 1;
		}
		size_t end = _size + len;
		while (end >= pos + len)
		{
			_str[end] = _str[end - len];
			end--;
		}
		_size += len;
		for (size_t i = 0; str[i]; i++)
		{
			_str[i + pos] = str[i];
		}
		return *this;
	}

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		size_t n = pos + len;
		if (len > _size - pos - 1)
		{
			_str[pos] = '\0';
			_size -= (_size - pos);
		}
		else
		{
			while (n < _size)
			{
				_str[n - len] = _str[n];
				n++;
			}
			_str[n] = '\0';
			_size -= len;
		}
		return *this;
	}

	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > (_size - pos))
		{
			len = _size - pos;
		}

		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}

		return sub;
	}




	//io
	ostream& operator<<(ostream& _cout, const ELY::string& s)
	{
		for (char e : s)
		{
			cout << e ;
		}
		return _cout;
	}

	istream& operator>>(istream& _cin, ELY::string& s)
	{
		s.clear();
		char ch = _cin.get();
		while (ch != '\n')
		{
			s += ch;
			ch = _cin.get();
		}
		return _cin;
	}
}