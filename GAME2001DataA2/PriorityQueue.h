#pragma once

#include "LinkedList.h"

template<class T, class CMP>
class PriorityQueue
{
private :
	LinkList<T> m_LinkList;
	int m_iSize;

public :
	PriorityQueue(int iSize)
	{
		assert(iSize > 0);
		m_iSize = iSize;
	}

	~PriorityQueue()
	{

	}

	void Push(T newData, int iPriority)
	{
		assert(m_LinkList.GetSize() < m_iSize);

		//If my PriorityQueue is empty...
		if (m_LinkList.GetSize() == 0)
		{
			m_LinkList.Push(newData, iPriority);
		}
		//If my PriorityQueue has items....
		else
		{
			LinkIterator<T> it;
			it = m_LinkList.Begin();

			//used to compare two
			CMP cmp;

			//Iterate through until reach the end
			while (it.isValid())
			{
				//If we found proper posiiton....
				if (cmp(iPriority, (*it)->GetPriority()))
				{
					break;
				}
				++it;
			}

			//If the iterator points to any node..
			if (it.isValid())
			{
				m_LinkList.Insert_Before(it, newData, iPriority);
			}
			//If iteraotr is at end..
			else
			{
				m_LinkList.Push(newData, iPriority);
			}
		}
	}

	void Pop()
	{
		m_LinkList.Pop_Front();
	}

	LinkNode<T>* Front()
	{
		return m_LinkList.Begin();
	}

	bool IsEmpty()
	{
		return (m_LinkList.GetSize() == 0);
	}

	int GetSize()
	{
		return m_LinkList.GetSize();
	}
};
