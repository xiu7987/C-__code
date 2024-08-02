#include <iostream>
#include <stdio.h>
#include <string.h>

namespace ikun
{
	int strncat = 0;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(double* a, double* b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
}


int add(int a, int b = 0, int c = 10);

int add(int a, int b,int c)
{
	return a + b + c;
}

int main()
{
	int b = add(1);//正确方式
	std::cout << b << std::endl;
}

int main1()
{
	int a = 0;
	std::cin >> a ;
	printf("%d\n", a);
	scanf_s("%d", &a);
	std::cout << a << std::endl;
	return 0;
}