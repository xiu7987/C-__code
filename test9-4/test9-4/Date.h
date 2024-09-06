#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int a = 2024, int b = 9, int c = 25)
	{
		_year = a;
		_month = b;
		_day = c;
		if (!IsTrueDate())
		{
			cout << "检测到非法日期->";
			/*Print();*/
			cout << *this;
			assert(IsTrueDate());
		}
	}
	bool IsTrueDate();
	int GetMonthDay();
	/*void Print();*/
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);

	Date& operator+=(int i);
	Date& operator-=(int i);
	Date operator+(int i);
	Date operator-(int i);

	Date operator++(int i);
	Date& operator++();
	Date operator--(int i);
	Date& operator--();


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, const Date& d);