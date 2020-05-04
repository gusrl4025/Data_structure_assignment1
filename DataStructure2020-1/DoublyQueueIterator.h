#pragma once
#include "DoublyLinkedQueue.h"

template<typename ItemType>
class DoublyLinkedQueue;

template <typename ItemType>
struct DoublyNodeType;

template <typename ItemType>
class DoublyQueueIterator
{
	friend class DoublyLinkedQueue<ItemType>;
public:
	DoublyQueueIterator(const DoublyLinkedQueue<ItemType>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}; // Default constructor
	~DoublyQueueIterator() {};
	bool NotNull(); // list�� ���Ұ� Null�� �ƴ��� �˻�
	bool NextNotNull(); // list�� ���� ���Ұ� Null�� �ƴ����˻�
	ItemType First();// list�� ó�� node�� item�� ����
	ItemType Next(); // ���� node�� �̵��ϰ� �ش� node�� item�� ����
	DoublyNodeType<ItemType> GetCurrentNode();// ����node�� ����
private:
	const DoublyLinkedQueue<ItemType>& m_List;// ����� ����Ʈ�� ���� ����
	DoublyNodeType<ItemType>* m_pCurPointer; // Iterator ����
};

template<typename ItemType>
inline bool DoublyQueueIterator<ItemType>::NotNull()
{
	if (m_pCurPointer != nullptr) return true;
	return false;
}

template<typename ItemType>
inline bool DoublyQueueIterator<ItemType>::NextNotNull()
{
	if (m_pCurPointer->next != nullptr) return true;
	return false;
}

template<typename ItemType>
inline ItemType DoublyQueueIterator<ItemType>::First()
{
	return m_List.m_pFirst;
}

template<typename ItemType>
inline ItemType DoublyQueueIterator<ItemType>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->info;
}

template<typename ItemType>
inline DoublyNodeType<ItemType> DoublyQueueIterator<ItemType>::GetCurrentNode()
{
	return *m_pCurPointer;
}
