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
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��
//	һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ
//���ڹ�
//Add(a1, d1);
//*/
//// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	Add(a, (int)d);
//	return 0;
//}
//
//int main(void)
//{
//	int a = 10;
//	double b = 20.0;
//	// ��ʽʵ����
//	Add<int>(a, b);
//	return 0;
//}
//
//
//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}


