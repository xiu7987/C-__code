#include "myvector.h"

int main()
{
	ELY::vector<int> arr = { 1,2,3,4,5,6 };
	
	//ELY::vector<int> arr2 = arr;
	//ELY::vector<int> arr1 = arr2;
	//ELY::vector<int> arr3(10, 1);
	//cout << arr3.size() << ' ' << arr3.capacity() << endl;
	//for (auto i : arr3)
	//{
	//	cout << i << ' ';
	//}
	//cout << endl;
	//arr1.push_back(1);
	//arr1.push_back(1);
	//arr1.push_back(1);
	//arr1.push_back(1);
	//arr1.push_back(1);
	//for (auto i : arr1)
	//{
	//	cout << i << ' ';
	//}
	//cout << endl;
	//arr1.resize(20);
	//for (auto i : arr1)
	//{
	//	cout << i << ' ';
	//}
	//cout << endl;
	//arr = arr1;
	//cout << arr.size() << ' ' << arr.capacity() << endl;

	ELY::vector<int> arr1(arr.begin() + 2, arr.end());
	arr1.swap(arr);
	ELY::vector<int>::iterator itor = arr1.insert(arr1.end() - 3, 11);
	
	for (auto i : arr1)
	{
		cout << i << ' ';
	}
	cout << endl;

	arr1.erase(arr1.end() - 1);
	for (; itor < arr1.end(); itor++)
	{
		cout << *itor << ' ';
	}
	cout << endl;

	arr1 = arr;
	arr1.resize(2);
	for (auto i : arr1)
	{
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}