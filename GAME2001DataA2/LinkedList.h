#pragma once
#include <cassert>

template<class T> class LinkIterator;
template<class T> class LinkList;

//Single node in Linked List
template<class T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class LinkList<T>;

private :
	int m_iPriority;
	T m_Data;
	LinkNode* m_pNext;
	LinkNode* m_pPrev;

public :
	LinkNode() :m_iPriority(0), m_pNext(nullptr), m_pPrev(nullptr)
	{

	}
	~LinkNode()
	{

	}

	int GetPriority() const { return m_iPriority; }
	T GetData() const { return m_Data; }
};


//Iterator for Linked List
template<class T>
class LinkIterator
{
	friend class LinkList<T>;

private :
	LinkNode<T>* m_node;

public :
	LinkIterator() :m_node(nullptr)
	{

	}
	~LinkIterator()
	{

	}

	void operator=(LinkNode<T>* node)
	{
		m_node = node;
	}

	LinkNode<T>* operator*()
	{
		assert(m_node != nullptr);
		return m_node;
	}

	//Prefix
	void operator++()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_pNext;
	}

	//PostFix
	void operator++(int)
	{
		assert(m_node != nullptr);
		m_node = m_node->m_pNext;
	}

	//Prefix
	void operator--() // Prefix
	{
		assert(m_node != nullptr);
		m_node = m_node->m_pPrev;
	}

	//PostFix
	void operator--(int)
	{
		assert(m_node != nullptr);
		m_node = m_node->m_pPrev;
	}

	bool operator!=(LinkNode<T>* node)
	{
		return (m_node != node);
	}

	bool operator==(LinkNode<T>* node)
	{
		return (m_node == node);
	}

	bool isValid()
	{
		return (m_node != NULL);
	}
};


//Linked List Data Structure
template<class T>
class LinkList
{
private :
	int m_iSize;
	LinkNode<T>* m_pRoot;
	LinkNode<T>* m_pLast;

public :
	LinkList() :m_iSize(0), m_pRoot(nullptr), m_pLast(nullptr)
	{

	}

	~LinkList()
	{
		while (m_pRoot)
		{
			Pop();
		}
	}

	LinkNode<T>* Begin()
	{
		assert(m_pRoot != nullptr);
		return m_pRoot;
	}

	LinkNode<T>* End()
	{
		return nullptr;
	}

	LinkNode<T>* Last()
	{
		return m_pLast;
	}

	void Insert_Before(LinkIterator<T>& it, T newData, int iPriority)
	{
		assert(it.m_node != nullptr);

		LinkNode<T>* newNode = new LinkNode<T>;
		assert(newNode != nullptr);

		newNode->m_Data = newData;
		newNode->m_iPriority = iPriority;
		newNode->m_pNext = it.m_node;
		newNode->m_pPrev = it.m_node->m_pPrev;

		if (newNode->m_pPrev != nullptr)
		{
			newNode->m_pPrev->m_pNext = newNode;
		}

		it.m_node->m_pPrev = newNode;

		if (it.m_node == m_pRoot)
		{
			m_pRoot = newNode;
		}

		++m_iSize;
	}

	void Insert_After(LinkIterator<T>& it, T newData, int iPriority)
	{
		assert(it.m_node != nullptr);

		LinkNode<T>* newNode = new LinkNode<T>;
		newNode->m_Data = newData;
		newNode->m_iPriority = iPriority;
		newNode->m_pNext = it.m_node->m_pNext;
		newNode->m_pPrev = it.m_node;

		if (newNode->m_pNext != nullptr)
		{
			newNode->m_pNext->m_pPrev = newNode;
		}

		it.m_node->m_pNext = newNode;

		if (it.m_node == m_pLast)
		{
			m_pLast = newNode;
		}

		++m_iSize;
	}

	void Push_Front(T newData, int iPriority)
	{
		LinkNode<T>* newNode = new LinkNode<T>;
		assert(newNode != nullptr);

		newNode->m_Data = newData;
		newNode->m_iPriority = iPriority;
		newNode->m_pNext = nullptr;
		newNode->m_pPrev = nullptr;

		//If root exist
		if (m_pRoot != nullptr)
		{
			newNode->m_pNext = m_pRoot;
			m_pRoot->m_pPrev = newNode;
			m_pRoot = newNode;
		}
		//No root
		else
		{
			m_pRoot = newNode;
			m_pLast = newNode;
		}

		++m_iSize;
	}

	void Pop_Front()
	{
		assert(m_pRoot != nullptr);

		LinkNode<T>* temp = m_pRoot;

		m_pRoot = m_pRoot->m_pNext;

		if (m_pRoot != nullptr)
		{
			m_pRoot->m_pPrev = nullptr;
		}
		else
		{
			m_pLast = nullptr;
		}

		delete temp;
		temp = nullptr;

		// Prevent negative numbers
		m_iSize = (m_iSize == 0 ? m_iSize : m_iSize - 1);
	}

	void Push(T newData, int iPriority)
	{
		LinkNode<T>* newNode = new LinkNode<T>;
		assert(newNode != nullptr);

		newNode->m_Data = newData;
		newNode->m_iPriority = iPriority;
		newNode->m_pNext = nullptr;
		newNode->m_pPrev = nullptr;

		//If item exit in linked list
		if (m_pLast != nullptr)
		{
			m_pLast->m_pNext = newNode;
			newNode->m_pPrev = m_pLast;
		}
		//If linked list is empty
		else
		{
			m_pRoot = newNode;
		}

		m_pLast = newNode;

		++m_iSize;
	}

	void Pop()
	{
		assert(m_pRoot != nullptr);

		//If only root exit in linked list
		if (m_pRoot->m_pNext == nullptr)
		{
			delete m_pRoot;
			m_pRoot = nullptr;
			m_pLast = nullptr;
		}
		//If there are more than 2 items in linked list
		else
		{
			LinkNode<T>* prevNode = m_pLast->m_pPrev;

			prevNode->m_pNext = nullptr;
			delete m_pLast;
			m_pLast = prevNode;
		}

		// Prevent negative size
		m_iSize = (m_iSize == 0 ? m_iSize : m_iSize - 1);
	}

	int GetSize()
	{
		return m_iSize;
	}
};