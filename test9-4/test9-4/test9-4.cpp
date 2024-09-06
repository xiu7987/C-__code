#include "Date.h"
using namespace std;

void TestDate4()
{
	Date d1(2024, 4, 14);
	Date d2 = d1 + 30000;
	// operator<<(cout, d1)
	cout << d1 << endl;
	cout << d2 << endl;
	cin >> d1 >> d2;
	cout << d1 << " " << d2 << endl;
}

int main()
{
	Date d1(2024,9,5);
	Date d2(2024,9,5);
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	d2 += -100000;
	cout << d2 << d1 << endl;
	d2 -= -1000000;
	cout << d2 << endl;
	Date tmp = --d2;
	cout << tmp <<endl;
	cout << d2 << endl;
	cout << d1 << endl;
	TestDate4();
	return 0;
}