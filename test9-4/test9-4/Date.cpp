#include "Date.h"

//void Date::Print()
//{
//	cout << _year << "年" << _month << "月" << _day << "日" << endl;
//}

int Date::GetMonthDay()
{
	assert(_month <= 12 || _month > 0);
	static int arr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
	{
		return 29;
	}
	return arr[_month];
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::IsTrueDate()
{
	if (_month <= 12 && _month > 0 && _day <= GetMonthDay() && _day > 0)
	{
		return true;
	}
	return false;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	return false;
}

bool Date::operator<=(const Date& d)
{
	return (operator<(d) || operator==(d));
}

bool Date::operator==(const Date& d)
{
	return (_year == d._year &&
		_month == d._month &&
		_day == d._day);
}

bool Date::operator>=(const Date& d)
{
	return (!operator<(d));
}

bool Date::operator>(const Date& d)
{
	return (!operator<=(d));
}

Date& Date::operator+=(int i)
{
	if (i < 0)
	{
		return *this -= -i;
	}
	_day += i;
	while (_day > GetMonthDay())
	{
		_day -= GetMonthDay();
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator-(int i)
{
	Date tmp = *this;
	tmp -= i;
	return tmp;
}

Date Date::operator+(int i)
{
	Date tmp = *this;
	tmp += i;
	return tmp;
}

Date& Date::operator-=(int i)
{
	if (i < 0)
	{
		return *this += -i;
	}
	_day -= i;
	while (_day < 0)
	{
		_day += GetMonthDay();
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
	}
	return *this;
}

Date Date::operator++(int i)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator++()
{
	return (*this += 1);
}

Date Date::operator--(int i)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

Date& Date::operator--()
{
	return (*this -= 1);
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日";
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请输入一个日期" << endl;
	while (1)
	{
		in >> d._year >> d._month >> d._day;
		if (!d.IsTrueDate())
		{
			cout << "非法日期，请重新输入" << endl;
		}
		else break;
	}
	return in;
}