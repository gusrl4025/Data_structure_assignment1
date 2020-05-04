#pragma once
#include "DoublyQueueIterator.h"

template<typename ItemType>
class DoublyQueueIterator;

template<typename ItemType>
struct DoublyNodeType;

template <typename ItemType>
class DoublyLinkedQueue {

	friend class DoublyQueueIterator<ItemType>;

public:
	/*
		Constructor
	*/
	DoublyLinkedQueue();

	/*
		Destructor
	*/
	~DoublyLinkedQueue();

	/*
		@brief	Queue�� ����
		@pre	Queue�� initialize �ž��Ѵ�
		@post	Queue�� �������
	*/
	void MakeEmpty();

	/*
		@brief	Length�� �����´�
		@pre	none
		@post	none
		@return	return m_Length
	*/
	int GetLength() const;

	/*
		@brief	Queue�� ������� �˻��Ѵ�
		@pre	Queue�� iniitialize �ž��Ѵ�
		@post	none
		@return	Queue�� empty�� return true, �ƴϸ� return false
	*/
	bool IsEmpty() const;

	/*
		@brief	Queue�� Rear�� ���ο� ���Ҹ� ����
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	IsFull() == false�� Queue�� Rear�� ���ο� ���Ұ� �־���
		@param	item	Queue�� �߰��� ����
		@return	item�� ����� Queue�� �߰��Ǹ� return true, �ƴϸ� return false
	*/
	bool EnQueue(const ItemType& item);

	/*
		@brief	Queue�� Front�� �ִ� ���Ҹ� �����ϰ� ������
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	IsEmpty() == false�� Queue�� Front�� ���Ұ� ���ŵǸ� item�� ������
		@param	item	top�� ���Ұ� item�� ������
		@return	item�� ����� ���ŵǾ����� return true, �ƴϸ� return false

	*/
	bool DeQueue(ItemType& item);


	/*
		@brief	param�� Id�� ���� Id�� ���� item�� Queue���� ã�� ������
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	param�� Id�� ���� Id�� ���� item�� ������
		@param	item	���� Id�� ���� Queue�� item�� ������
		@return	item�� ã���� return true, �ƴϸ� return false
	*/
	bool Retrieve(ItemType& item);

	/*
		@brief	param�� Id�� ���� Id�� ���� item�� Queue���� ã�� �����ϰ� ������
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	param�� Id�� ���� Id�� ���� item�� Queue���� �����ǰ� ������
		@param	item	���� Id�� ���� Queue�� item�� ������
		@return	item�� ���������� �����ϸ� return true, �ƴϸ� return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	param�� Id�� ���� Id�� ���� item�� Queue���� ã�� ������ Replace�Ѵ�.
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	param�� Id�� ���� Id�� ���� item�� param���� replace�ȴ�.
		@param	item	��ü�ϰ��� �ϴ� item
		@return	item�� ���������� ��ü�ϸ� return true, �ƴϸ� return false
	*/
	bool Replace(const ItemType& item);
	

private:
	DoublyNodeType<ItemType>* m_pFirst;
	DoublyNodeType<ItemType>* m_pLast;
	int m_Length;
};

// Constructor
template<typename ItemType>
inline DoublyLinkedQueue<ItemType>::DoublyLinkedQueue()
{
	m_pFirst = new DoublyNodeType<ItemType>;
	m_pLast = new DoublyNodeType<ItemType>;

	m_pFirst->next = m_pLast;
	m_pFirst->prev = nullptr;

	m_pLast->next = nullptr;
	m_pLast->prev = m_pLast;

	m_Length = 0;
}

// Destructor
template<typename ItemType>
inline DoublyLinkedQueue<ItemType>::~DoublyLinkedQueue()
{
	MakeEmpty();
	delete m_pFirst;
	delete m_pLast;
}

// make list empty
template<typename ItemType>
inline void DoublyLinkedQueue<ItemType>::MakeEmpty()
{
	DoublyNodeType<ItemType>* pItem;
	DoublyQueueIterator<ItemType> itor(*this);
	itor.Next();

	while (itor.NextNotNull()) {
		pItem = itor.m_pCurPointer;
		itor.Next();
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = nullptr;

	m_pLast->next = nullptr;
	m_pLast->prev = m_pLast;

	m_Length = 0;
}

// get number of records in list
template<typename ItemType>
inline int DoublyLinkedQueue<ItemType>::GetLength() const
{
	return m_Length;
}

template<typename ItemType>
inline bool DoublyLinkedQueue<ItemType>::IsEmpty() const
{
	if (m_Length == 0) return true;
	return false;
}

// add new record in list
template<typename ItemType>
inline bool DoublyLinkedQueue<ItemType>::EnQueue(const ItemType& item)
{
	DoublyNodeType<ItemType>* pItem = new DoublyNodeType<ItemType>;
	pItem->info = item;
	pItem->next = m_pFirst->next;
	pItem->prev = m_pFirst;
	m_pFirst->next = pItem;
	pItem->next->prev = pItem;
	m_Length++;
	return true;

}

template<typename ItemType>
inline bool DoublyLinkedQueue<ItemType>::DeQueue(ItemType& item)
{
	if (IsEmpty()) {
		return false;
	}
	else {
		DoublyNodeType<ItemType>* pItem = new DoublyNodeType<ItemType>;
		pItem = m_pLast->prev;
		item = pItem->info;
		pItem->prev->next = m_pLast;
		m_pLast->prev = pItem->prev;
		delete pItem;
		m_Length--;
		return true;
	}
}

// find item which has same keynumber of parameter in list
template<typename ItemType>
inline bool DoublyLinkedQueue<ItemType>::Retrieve(ItemType& item)
{
	DoublyQueueIterator<ItemType> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->info == item)
		{
			item = itor.m_pCurPointer->info;
			return true;
		}
		else
			itor.Next();
	}

	return false;
}

// delete item which is same with param
template<typename ItemType>
inline bool DoublyLinkedQueue<ItemType>::Delete(ItemType& item)
{
	DoublyQueueIterator<ItemType> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast) {
		if (itor.m_pCurPointer->info == item) {
			DoublyNodeType<ItemType>* pItem = new DoublyNodeType<ItemType>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev;
			delete pItem;
			m_Length--;
			return true;
		}
		itor.Next();
	}
	return false;
}

// replace item which has same keynumber with param
template<typename ItemType>
inline bool DoublyLinkedQueue<ItemType>::Replace(const ItemType& item)
{
	DoublyQueueIterator<ItemType> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast) {
		if (itor.m_pCurPointer->info == item) {
			itor.m_pCurPointer->info = item;
			return true;
		}
		itor.Next();
	}
	return false;
}
