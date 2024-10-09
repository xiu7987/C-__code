#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


namespace ELY
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			assert(first && last);
			InputIterator itor = first;
			for (; itor < last; itor++)
			{
				push_back(*itor);
			}
		}

		vector(initializer_list<T> il)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(il.size());
			for (auto& i : il)
			{
				push_back(i);
			}
		}

		vector(size_t n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, value);
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			_finish = _start + v.size();
			memcpy(_start, v._start, size() * sizeof(T));
		}

		vector<T>& operator=(const vector<T>& v)
		{
			reserve(v.capacity());
			_finish = _start + v.size();
			memcpy(_start, v._start, size() * sizeof(T));
			return *this;
		}

		//iterator
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		//capacity
		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, size() * sizeof(T));
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + oldsize;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& pos = T())
		{
			while (size() < n)
			{
				push_back(pos);
			}
			if (n <= size())
				_finish = _start + n;
		}

		//access
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		//modify
		void push_back(T n)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = n;
			_finish++;
		}

		void pop_back()
		{
			assert(size());
			_finish--;
		}

		void swap(vector<T>& v)
		{
			iterator itor = _start;
			_start = v._start;
			v._start = itor;
			itor = _finish;
			_finish = v._finish;
			v._finish = itor;
			itor = _end_of_storage;
			_end_of_storage = v._end_of_storage;
			v._end_of_storage = itor;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator itor = _finish;
			while (itor >= pos)
			{
				*(itor + 1) = *itor;
				--itor;
			}
			*pos = x;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator itor = pos;
			while (itor < _finish - 1)
			{
				*pos = *(pos + 1);
			}
			_finish--;
			return pos;
		}


		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}