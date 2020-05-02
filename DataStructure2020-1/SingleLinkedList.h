#include "pch.h"

template <typename ItemType>
struct NodeType {
	ItemType info;
	NodeType* next;
};

template<typename ItemType>
class SingleLinkedList {
private:
	NodeType<ItemType>* m_pList;
	NodeType<ItemType>* m_pCurPointer;
	int m_Length;
public:
	/*
		constructor
	*/
	SingleLinkedList();

	/*
		Destructor
	*/
	~SingleLinkedList();

	/*
		@brief	List를 비운다
		@pre	none
		@post	List가 비워진다
	*/
	void MakeEmpty();

	/*
		@brief	m_Length를 반환한다
		@pre	none
		@post	none
		@return m_Length
	*/
	int GetLength();

	/*
		@brief	List에 item을 추가한다
		@pre	list가 초기화돼야한다.
		@post	List가 꽉 차있지 않고 중복된 ID가 아니면 List에 추가된다.
		@param	item	추가하려는 아이템
		@return	아이템이 추가되었으면 return true,아니면 return false
	*/
	bool Add(const ItemType& item);

	/*
		@brief	List에서 원하는 item을 가져온다
		@pre	List가 초기화돼야한다
		@post	parameter에 찾고자하는 item이 참조된다
		@param	item	찾고자하는 아이템
		@return	아이템을 찾았으면 return true, 아니면 return false
	*/
	bool Get(ItemType& item);

	/*
		@brief	List에서 원하는 item을 제거한다
		@pre	List가 초기화돼야한다
		@post	parameter에 제거한 item이 참조된다
		@param	item	제거하려는 아이템
		@return	아이템을 제거했으면 return true, 아니면 return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	List에서 원하는 item을 수정한다.
		@pre	List가 초기화돼야한다
		@post	원하는 item이 paramter에 있는 item으로 수정된다
		@param	item	수정하려는 item
		@return	item을 수정했으면 return true, 아니면 return false
	*/
	bool Replace(const ItemType& item);

	/*
		@brief	List의 Pointer를 초기화시킨다
		@pre	none
		@post	m_pCurPointer = nullptr
	*/
	void ResetList();

	/*
		@brief	현재 pointer의 next item을 불러온다
		@pre	List가 초기화돼야한다
		@post	next item이 있으면 parameter에 next item이 참조된다
		@param	item	next item이 여기에참조된다
		@return	next item을 참조하면 return true, 아니면 return false
	*/
	bool GetNextItem(ItemType& item);

	void operator=(SingleLinkedList list) {
		MakeEmpty();
		m_Length = 0;

		if (list.GetLength()) {
			list.ResetList();
			ItemType item;
			while (list.GetNextItem(item)) {
				Add(item);
			}
		}
	}
};

// constructor
template<typename ItemType>
SingleLinkedList<ItemType>::SingleLinkedList()
{
	m_pList = nullptr;
	m_pCurPointer = nullptr;
	m_Length = 0;
}

// destructor
template<typename ItemType>
SingleLinkedList<ItemType>::~SingleLinkedList()
{
	MakeEmpty();
}

// List를 비운다
template<typename ItemType>
void SingleLinkedList<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* TempPtr;
 	TempPtr = m_pList;
	if (m_pList == nullptr) {
		return;
	}
	while (m_pList != nullptr) {
		TempPtr = m_pList;
		m_pList = m_pList->next;
		//delete TempPtr; 
	}

	m_Length = 0;
}

// m_Length를 반환한다
template<typename ItemType>
inline int SingleLinkedList<ItemType>::GetLength()
{
	return m_Length;
}

// List에 item을 추가한다
template<typename ItemType>
bool SingleLinkedList<ItemType>::Add(const ItemType& item)
{
	bool found = false;

	NodeType<ItemType>* PredLoc;
	NodeType<ItemType>* TempPtr;
	TempPtr = new NodeType<ItemType>;

	TempPtr->info = item;

	if (m_Length == 0) {
		m_pList = TempPtr;
		TempPtr->next = nullptr;
		m_Length++;
	}
	else {
		PredLoc = m_pList;
		m_pCurPointer = m_pList;
		while (m_pCurPointer != nullptr) {
			if (m_pCurPointer->info == item) {
				cout << "\t중복된 ID가 있습니다\n";
				return false;
			}
			if (m_pCurPointer->info > item) {
				found = true;
				break;
			}
			if (m_pCurPointer->info < item) {
				PredLoc = m_pCurPointer;
				m_pCurPointer = m_pCurPointer->next;
			}
		}

		if (PredLoc == m_pCurPointer) {
			TempPtr->next = m_pList;
			m_pList = TempPtr;
		}

		else {
			PredLoc->next = TempPtr;
			TempPtr->next = m_pCurPointer;
		}
		m_Length++;
		return true;
	}
}

// List에서 원하는 item을 가져온다
template<typename ItemType>
bool SingleLinkedList<ItemType>::Get(ItemType& item)
{
	m_pCurPointer = m_pList;

	while (m_pCurPointer != nullptr) {
		if (m_pCurPointer->info == item) {
			item = m_pCurPointer->info;
			return true;
		}
		if (m_pCurPointer->info > item) {
			return false;
		}
		if (m_pCurPointer->info < item) {
			m_pCurPointer = m_pCurPointer->next;
		}
	}
	return false;
}

// List에서 원하는 item을 제거한다
template<typename ItemType>
inline bool SingleLinkedList<ItemType>::Delete(ItemType& item)
{
	bool found = false;
	NodeType<ItemType>* PredLoc;
	NodeType<ItemType>* TempPtr;
	TempPtr = new NodeType<ItemType>;

	TempPtr->info = item;

	if (m_Length == 0) {
		return false;
	}

	else {
		PredLoc = m_pList;
		m_pCurPointer = m_pList;
		while (m_pCurPointer == nullptr) {
			if (TempPtr->info == m_pCurPointer->info) {
				found = true;
			}
			if (TempPtr->info > m_pCurPointer->info) {
				return false;
			}
			if (TempPtr->info < m_pCurPointer->info) {
				PredLoc = m_pCurPointer;
				m_pCurPointer = m_pCurPointer->next;
			}
		}
		if (!found) return false;
		else {
			if (m_pCurPointer == m_pList) {
				m_pList = m_pList->next;
				delete PredLoc;
			}
			if (m_pCurPointer->next == nullptr) {
				PredLoc->next = nullptr;
				delete m_pCurPointer;
			}
			PredLoc->next = m_pCurPointer->next;
			delete m_pCurPointer;
			return true;
		}
	}
}

// List에서 원하는 item을 수정한다.
template<typename ItemType>
inline bool SingleLinkedList<ItemType>::Replace(const ItemType& item)
{
	m_pCurPointer = m_pList;

	while (m_pCurPointer != nullptr) {
		if (m_pCurPointer->info == item) {
			m_pCurPointer->info = item;
			return true;
		}
		if (m_pCurPointer->info < item) {
			m_pCurPointer = m_pCurPointer->next;
		}
		if (m_pCurPointer->info > item) {
			return false;
		}
	}
}

// List의 Pointer를 초기화시킨다
template<typename ItemType>
void SingleLinkedList<ItemType>::ResetList()
{
	m_pCurPointer = nullptr;
}

// 현재 pointer의 next item을 불러온다
template<typename ItemType>
bool SingleLinkedList<ItemType>::GetNextItem(ItemType& item)
{
	if (m_pCurPointer == nullptr) {
		m_pCurPointer = m_pList;
		item = m_pCurPointer->info;
		return true;
	}

	if (m_pCurPointer->next == nullptr) {
		ResetList();
		return false;
	}

	m_pCurPointer = m_pCurPointer->next;
	item = m_pCurPointer->info;
	return true;
}