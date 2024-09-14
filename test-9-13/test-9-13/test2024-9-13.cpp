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
//operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
//失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否
//则抛异常。
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: 该函数最终是通过free来释放空间的
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