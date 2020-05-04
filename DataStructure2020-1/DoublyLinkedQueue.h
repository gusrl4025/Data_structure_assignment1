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
		@brief	Queue를 비운다
		@pre	Queue가 initialize 돼야한다
		@post	Queue가 비워진다
	*/
	void MakeEmpty();

	/*
		@brief	Length를 가져온다
		@pre	none
		@post	none
		@return	return m_Length
	*/
	int GetLength() const;

	/*
		@brief	Queue가 비었는지 검사한다
		@pre	Queue가 iniitialize 돼야한다
		@post	none
		@return	Queue가 empty면 return true, 아니면 return false
	*/
	bool IsEmpty() const;

	/*
		@brief	Queue의 Rear에 새로운 원소를 넣음
		@pre	Queue가 initialize 돼야한다.
		@post	IsFull() == false면 Queue의 Rear에 새로운 원소가 넣어짐
		@param	item	Queue에 추가할 원소
		@return	item이 제대로 Queue에 추가되면 return true, 아니면 return false
	*/
	bool EnQueue(const ItemType& item);

	/*
		@brief	Queue의 Front에 있는 원소를 제거하고 참조함
		@pre	Queue가 initialize 돼야한다.
		@post	IsEmpty() == false면 Queue의 Front에 원소가 제거되면 item에 참조됨
		@param	item	top의 원소가 item에 참조됨
		@return	item이 제대로 제거되었으면 return true, 아니면 return false

	*/
	bool DeQueue(ItemType& item);


	/*
		@brief	param의 Id와 같은 Id를 가진 item을 Queue에서 찾아 참조함
		@pre	Queue가 initialize 돼야한다.
		@post	param의 Id와 같은 Id를 가진 item을 참조함
		@param	item	같은 Id를 가진 Queue의 item을 참조함
		@return	item을 찾으면 return true, 아니면 return false
	*/
	bool Retrieve(ItemType& item);

	/*
		@brief	param의 Id와 같은 Id를 가진 item을 Queue에서 찾아 삭제하고 참조함
		@pre	Queue가 initialize 돼야한다.
		@post	param의 Id와 같은 Id를 가진 item이 Queue에서 삭제되고 참조됨
		@param	item	같은 Id를 가진 Queue의 item을 참조함
		@return	item을 성공적으로 삭제하면 return true, 아니면 return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	param의 Id와 같은 Id를 가진 item을 Queue에서 찾아 정보를 Replace한다.
		@pre	Queue가 initialize 돼야한다.
		@post	param의 Id와 같은 Id를 가진 item이 param으로 replace된다.
		@param	item	교체하고자 하는 item
		@return	item을 성공적으로 교체하면 return true, 아니면 return false
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
