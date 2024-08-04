#include "test.h"
using namespace std;

void Swap(int& rx, int& ry)
{
	int tmp = rx;
	rx = ry;
	ry = tmp;
}
int main2()
{
	int x = 0, y = 1;
	cout << x << " " << y << endl;
	Swap(x, y);
	cout << x << " " << y << endl;
	return 0;
}


typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
void STInit(ST& rs, int n = 4)
{
	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
	rs.top = 0;
	rs.capacity = n;
} 

void STPush(ST & rs, STDataType x)
{
	// 满了， 扩容
	if (rs.top == rs.capacity)
	{
		printf("扩容\n");
		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
			sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		} 
			rs.a = tmp;
		rs.capacity = newcapacity;
	}
		rs.a[rs.top] = x;
	rs.top++;
}
int& STTop(ST& rs)
{
	assert(rs.top > 0);
	return rs.a[rs.top - 1];
} 
int main1()
{
	// 调⽤全局的
	ST st1;
	STInit(st1);
	STPush(st1, 1);
	STPush(st1, 2);
	cout << STTop(st1) << endl; 
	STTop(st1) += 10;
	cout << STTop(st1) << endl;
	const int a = 10;
	const int& ra = a;
	return 0;
}
int add(int x, int y)
{
	int ret = x + y;
	return ret;
}

int main31()
{
	cout << add(2, 3) << endl;
	return 0;
}

void f(int x)
{
	cout << "f(int x)" << endl;
}

void f(int* ptr)
{
	cout << "f(int* ptr)" << endl;
}

int main()
{
	f(0);
	f(nullptr);
	return 0;
}