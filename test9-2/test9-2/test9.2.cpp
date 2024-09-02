#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int n = 0,int b = 4)
	{
		top = n;
		capacity = b;
		int* top1 = (int*)malloc(4 * sizeof(int));
		if (top1 == nullptr)
		{
			perror("fail realloc arr");
			return;
		}
		arr = top1;
	}
	Stack(Stack& st)
	{
		int* top1 = (int*)realloc(arr,st.capacity * sizeof(int));
		if (top1 == nullptr)
		{
			perror("fail realloc arr");
			return;
		}
		arr = top1;
		capacity = st.capacity;
	}
	~Stack()
	{
		top = 0;
		capacity = 0;
		free(arr);
		arr = nullptr;
	}
private:
	int* arr;
	int top;
	int capacity;
};

void func(Stack a1)
{

}

int main()
{
	Stack d1;
	Stack d2(d1);
	func(d1);
}