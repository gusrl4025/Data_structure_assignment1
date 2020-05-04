#pragma once
#include "DoublyIterator.h"

template<typename ItemType>
class DoublyIterator;

template<typename ItemType>
struct DoublyNodeType;

template <typename ItemType>
class DoublySortedLinkedList {

	friend class DoublyIterator<ItemType>;

public:
	/*
		Constructor
	*/
	DoublySortedLinkedList();

	/*
		Desturctor
	*/
	~DoublySortedLinkedList();

	/*
		@brief	make list empty
		@pre	none
		@post	clear list
	*/
	void MakeEmpty();

	/*
		@brief	get number of records in list
		@pre	none
		@post	none
		@return	a number of records in list
	*/
	int GetLength() const;


	bool IsEmpty() const;

	/*
		@brief	add new record in list
		@pre	list should be initialize
		@post	added the new record in list
		@paran	data	new data
		@return	return 1 if record is added to list successfully otherwise return 0
	*/
	bool Add(const ItemType& data);

	/*
		@brief	find item which has same keynumber of parameter in list
		@pre	list should be initilized
		@post	parameter changed to item which has same keynumber in list
		@param	data	data to find
		@return	if function works successfully return true, otherwise return false
	*/
	bool Retrieve(ItemType& item);

	/*
		@brief	delete item which is same with param
		@pre	list should be initilized
		@post	deleted data which you want to delete in list
		@param	data	data to delete
		@return	if function works successfully return true, otherwise return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	replace item which has same keynumber with param
		@pre	list should be initilized
		@post	replaced data which you want to replace in list
		@param	data	data to replace
		@return	if function works successfully return true, otherwise return false
	*/
	bool Replace(const ItemType& item);

private:
	DoublyNodeType<ItemType>* m_pFirst;
	DoublyNodeType<ItemType>* m_pLast;
	int m_Length;
};

// Constructor
template<typename ItemType>
inline DoublySortedLinkedList<ItemType>::DoublySortedLinkedList()
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
inline DoublySortedLinkedList<ItemType>::~DoublySortedLinkedList()
{
	MakeEmpty();
	delete m_pFirst;
	delete m_pLast;
}

// make list empty
template<typename ItemType>
inline void DoublySortedLinkedList<ItemType>::MakeEmpty()
{
	DoublyNodeType<ItemType>* pItem;
	DoublyIterator<ItemType> itor(*this);
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
inline int DoublySortedLinkedList<ItemType>::GetLength() const
{
	return m_Length;
}

template<typename ItemType>
inline bool DoublySortedLinkedList<ItemType>::IsEmpty() const
{
	if (m_Length == 0) return true;
	return false;
}

// add new record in list
template<typename ItemType>
inline bool DoublySortedLinkedList<ItemType>::Add(const ItemType& item)
{
	DoublyIterator<ItemType> itor(*this);
	itor.Next();

	if (IsEmpty()) {
		DoublyNodeType<ItemType>* pItem = new DoublyNodeType<ItemType>;
		pItem->info = item;
		pItem->next = m_pLast;
		pItem->prev = m_pFirst;
		m_pFirst->next = pItem;
		m_pLast->prev = pItem;
		m_Length++;
		return true;
	}

	else {
		while (1) {
			if (itor.m_pCurPointer->info > item || itor.m_pCurPointer == m_pLast) {
				DoublyNodeType<ItemType>* pItem = new DoublyNodeType<ItemType>;
				pItem->info = item;
				pItem->next = itor.m_pCurPointer;
				pItem->prev = itor.m_pCurPointer->prev;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem;
				m_Length++;
				return true;
			}
			else if (itor.m_pCurPointer->info < item) {
				itor.Next();
			}
			else {
				cout << "\tId가 중복되었습니다\n";
				return false;
			}
		}
	}
}

// find item which has same keynumber of parameter in list
template<typename ItemType>
inline bool DoublySortedLinkedList<ItemType>::Retrieve(ItemType& item)
{
	DoublyIterator<ItemType> itor(*this);
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
inline bool DoublySortedLinkedList<ItemType>::Delete(ItemType& item)
{
	DoublyIterator<ItemType> itor(*this);
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
inline bool DoublySortedLinkedList<ItemType>::Replace(const ItemType& item)
{
	DoublyIterator<ItemType> itor(*this);
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
