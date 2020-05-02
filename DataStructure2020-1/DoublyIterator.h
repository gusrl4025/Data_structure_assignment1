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
	bool NotNull(); // list의 현재 원소가 Null이 아닌지검사
	bool NextNotNull(); // list의 다음 원소가 Null이 아닌지검사
	ItemType First();// list의 처음 node의 item을 리턴
	ItemType Next(); // 다음 node로 이동하고 해당 node의 item을 리턴
	DoublyNodeType<ItemType> GetCurrentNode();// 현재node를 리턴
private:
	const DoublySortedLinkedList<ItemType>& m_List;// 사용할 리스트의 참조 변수
	DoublyNodeType<ItemType>* m_pCurPointer; // Iterator 변수
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
