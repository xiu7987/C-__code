#include <iostream>
#include <assert.h>
#include <cassert>
#include <cstdlib> 
using namespace std;

//class Stack
//{
//public:
//	void Init(int n = 4)
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		if (tmp == nullptr)
//		{
//			perror("realloc fail!");
//			exit(EXIT_FAILURE);
//		}
//		_arr = tmp;
//		top = 0;
//		capacity = n;
//	}
//	void Check()
//	{
//		if (top == capacity)
//		{
//			int* tmp = (int*)realloc(_arr, sizeof(int) * (capacity*2));
//			if (tmp == nullptr)
//			{
//				perror("realloc fail!");
//				exit(EXIT_FAILURE);
//			}
//			_arr = tmp;
//			capacity *= 2;
//		}
//	}
//	void Push(int x)
//	{
//		assert(this);
//		Check();
//		_arr[top++] = x;
//	}
//	int Empty()
//	{
//		assert(this);
//		return (top != 0);
//	}
//	void Pop()
//	{
//		assert(this && Empty());
//		top--;
//	}
//	int Top()
//	{
//		assert(this && Empty());
//		return _arr[top - 1];
//	}
//	void Destory()
//	{
//		free(_arr);
//		_arr = nullptr;
//		top = capacity = 0;
//	}
//private:
//	int* _arr;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack d1;
//	Stack d2;
//	d1.Init();
//	d2.Init();
//	d2.Destory();
//	d1.Destory();
//	return 0;
//}
//
//
//class A
//{
//	public :
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int _i;
//};
//class B
//{
//	public :
//	void Print()
//	{
//		//...
//	}
//};
//class C
//{};



#include<iostream>
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}


//#include<iostream>
//using namespace std;
//class A
//{
//	public :
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}
