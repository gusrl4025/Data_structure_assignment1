#pragma once
#include "DoublySortedLinkedList.h"

template<typename ItemType>
struct DoublyNodeType;

template<typename ItemType>
class DoublySortedLinkedList;

template <typename ItemType>
class DoublyIterator
{
	friend class DoublySortedLinkedList<ItemType>;
public:
	DoublyIterator(const DoublySortedLinkedList<ItemType>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {};// Default constructor
	bool NotNull(); // list�� ���� ���Ұ� Null�� �ƴ����˻�
	bool NextNotNull(); // list�� ���� ���Ұ� Null�� �ƴ����˻�
	ItemType First();// list�� ó�� node�� item�� ����
	ItemType Next(); // ���� node�� �̵��ϰ� �ش� node�� item�� ����
	DoublyNodeType<ItemType> GetCurrentNode();// ����node�� ����
private:
	const DoublySortedLinkedList<ItemType>& m_List;// ����� ����Ʈ�� ���� ����
	DoublyNodeType<ItemType>* m_pCurPointer; // Iterator ����
};

template<typename ItemType>
inline bool DoublyIterator<ItemType>::NotNull()
{
	if (m_pCurPointer != nullptr) return true;
	return false;
}

template<typename ItemType>
inline bool DoublyIterator<ItemType>::NextNotNull()
{
	if (m_pCurPointer->next != nullptr) return true;
	return false;
}

template<typename ItemType>
inline ItemType DoublyIterator<ItemType>::First()
{
	return m_List.m_pFirst->data;
}

template<typename ItemType>
inline ItemType DoublyIterator<ItemType>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->info;
}

template<typename ItemType>
inline DoublyNodeType<ItemType> DoublyIterator<ItemType>::GetCurrentNode()
{
	return *m_pCurPointer;
}
