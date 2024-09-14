#include <iostream>
using namespace std;
//Date(int year = 2024, int month = 9, int day = 13)
//	:_year(year),
//	_month(month),
//	_day(day)
//{
//
//}

class Date
{
friend class B;

friend void Print(const Date& d);

public:
	Date(int year = 2024, int month = 9, int day = 13)
	:_year(year),
	_month(month),
	_day(day)
{

}

private:
	int _year;
	int _month;
	int _day;
};
class B
{
	//..........
};

void Print(const Date& d)
{
	cout << d._year << '-' << d._month << '-' << d._day << endl;
}

int main()
{
	Date d;
	Print(d);
	return 0;
}


/*
//operator new���ú���ʵ��ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�
//ʧ�ܣ�����ִ�п� �䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬��
//�����쳣��
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: �ú���������ͨ��free���ͷſռ��
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}