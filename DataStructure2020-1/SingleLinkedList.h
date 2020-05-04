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
		@brief	List�� ����
		@pre	none
		@post	List�� �������
	*/
	void MakeEmpty();

	/*
		@brief	m_Length�� ��ȯ�Ѵ�
		@pre	none
		@post	none
		@return m_Length
	*/
	int GetLength();

	/*
		@brief	List�� item�� �߰��Ѵ�
		@pre	list�� �ʱ�ȭ�ž��Ѵ�.
		@post	List�� �� ������ �ʰ� �ߺ��� ID�� �ƴϸ� List�� �߰��ȴ�.
		@param	item	�߰��Ϸ��� ������
		@return	�������� �߰��Ǿ����� return true,�ƴϸ� return false
	*/
	bool Add(const ItemType& item);

	/*
		@brief	List���� ���ϴ� item�� �����´�
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	parameter�� ã�����ϴ� item�� �����ȴ�
		@param	item	ã�����ϴ� ������
		@return	�������� ã������ return true, �ƴϸ� return false
	*/
	bool Get(ItemType& item);

	/*
		@brief	List���� ���ϴ� item�� �����Ѵ�
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	parameter�� ������ item�� �����ȴ�
		@param	item	�����Ϸ��� ������
		@return	�������� ���������� return true, �ƴϸ� return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	List���� ���ϴ� item�� �����Ѵ�.
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	���ϴ� item�� paramter�� �ִ� item���� �����ȴ�
		@param	item	�����Ϸ��� item
		@return	item�� ���������� return true, �ƴϸ� return false
	*/
	bool Replace(const ItemType& item);

	/*
		@brief	List�� Pointer�� �ʱ�ȭ��Ų��
		@pre	none
		@post	m_pCurPointer = nullptr
	*/
	void ResetList();

	/*
		@brief	���� pointer�� next item�� �ҷ��´�
		@pre	List�� �ʱ�ȭ�ž��Ѵ�
		@post	next item�� ������ parameter�� next item�� �����ȴ�
		@param	item	next item�� ���⿡�����ȴ�
		@return	next item�� �����ϸ� return true, �ƴϸ� return false
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

// List�� ����
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

// m_Length�� ��ȯ�Ѵ�
template<typename ItemType>
inline int SingleLinkedList<ItemType>::GetLength()
{
	return m_Length;
}

// List�� item�� �߰��Ѵ�
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
				cout << "\t�ߺ��� ID�� �ֽ��ϴ�\n";
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

// List���� ���ϴ� item�� �����´�
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

// List���� ���ϴ� item�� �����Ѵ�
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

// List���� ���ϴ� item�� �����Ѵ�.
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

// List�� Pointer�� �ʱ�ȭ��Ų��
template<typename ItemType>
void SingleLinkedList<ItemType>::ResetList()
{
	m_pCurPointer = nullptr;
}

// ���� pointer�� next item�� �ҷ��´�
template<typename ItemType>
bool SingleLinkedList<ItemType>::GetNextItem(ItemType& item)
{
	if (m_pCurPointer == nullptr) {
		m_pCurPointer = m_pList;
		item = m_pCurPointer->info;
		return true;
	}

	if (m_pCurPointer->next == nullptr) {
		return false;
	}

	m_pCurPointer = m_pCurPointer->next;
	item = m_pCurPointer->info;
	return true;
}