#include "string.h"

int main()
{
	ELY::string s;
	s = "dasdasdas";
	ELY::string s1("dasdasiduai");
	size_t n = s1.find("si");
	cout << s1.c_str() + n << endl;
	s1.insert(s1.size() - 9, 'c');
	cout << s1 << endl;
	s1.insert(s1.size(), "elysia");
	cout << s1 << endl;
	ELY::string s2 = s1.substr(s1.size() - 6,6);
	cout << s2 << endl;
	return 0;
}