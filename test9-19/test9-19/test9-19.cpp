#include <iostream>
using namespace std;


template<class T>
void Swap(T a, T b)
{
	T c = a;
	a = b;
	b = c;
}


template<class T,class T1>
void Swap(T a, T1 b)
{
	T c = a;
	a = b;
	b = c;
}

template<int N,class T = int>
class Stack
{
public:
	Stack()
		:top(0),
		capacity(N)
	{
		arr = new T[N];
		memset(arr, 0, N * sizeof(T));
	}
private:
	T* arr;
	int top;
	int capacity;
};


int main()
{
	int a = 10;
	int b = 1000;
	Swap(a, b);
	cout << a << ' ' << b << endl;
	Stack<10> st1;
	return 0;
}



//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//	一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要
//背黑锅
//Add(a1, d1);
//*/
//// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	Add(a, (int)d);
//	return 0;
//}
//
//int main(void)
//{
//	int a = 10;
//	double b = 20.0;
//	// 显式实例化
//	Add<int>(a, b);
//	return 0;
//}
//
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}


