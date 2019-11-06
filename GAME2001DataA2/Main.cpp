#include <iostream>
#include "PriorityQueue.h"
using namespace std;

template<class T>
class less_cmp
{
public :
	inline bool operator()(T lVal, T rVal)
	{
		return (lVal < rVal);
	}
};

template<class T>
class greater_cmp
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return (lVal > rVal);
	}
};

int main()
{
	PriorityQueue<int, less_cmp<int> > Que(10);

	Que.Push(10, 0);
	Que.Push(14, 3);
	Que.Push(17, 2);
	Que.Push(12, 6);
	Que.Push(18, 1);
	Que.Push(3, 10);
	Que.Push(17, 14);
	Que.Push(9, 12);

	cout << "Less Priority queue size: " << Que.GetSize() << endl;

	while (Que.IsEmpty() == false)
	{
		cout << "Priority: " << Que.Front()->GetPriority();
		cout << "	Data: " << Que.Front()->GetData();
		cout << endl;

		Que.Pop();
	}

	cout << endl;

	if (Que.IsEmpty() == true)
	{
		cout << "The container is empty" << endl;
	}
	else
	{
		cout << "The container is NOT empty" << endl;
	}
	
	cout << endl;
	cout << endl;


	PriorityQueue<int, greater_cmp<int> > Que2(10);

	Que2.Push(10, 0);
	Que2.Push(14, 3);
	Que2.Push(17, 2);
	Que2.Push(12, 6);
	Que2.Push(18, 1);
	Que2.Push(3, 10);
	Que2.Push(17, 14);
	Que2.Push(9, 12);

	cout << "Greater Priority queue size: " << Que2.GetSize() << endl;

	while (Que2.IsEmpty() == false)
	{
		cout << "Priority: " << Que2.Front()->GetPriority();
		cout << "	Data: " << Que2.Front()->GetData();
		cout << endl;

		Que2.Pop();
	}

	cout << endl;

	if (Que2.IsEmpty() == true)
	{
		cout << "The container is empty" << endl;
	}
	else
	{
		cout << "The container is NOT empty" << endl;
	}

	return 0;
}