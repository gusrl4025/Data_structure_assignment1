#pragma once

template <typename ItemType>
class Queue
{
public:
	/*
		Constructor
	*/
	Queue();

	/*
		Destructor
	*/
	~Queue();

	/*
		@brief	Queue�� ��á���� �˻��Ѵ�
		@pre	Queue�� initialize�ž��Ѵ�
		@post	none
		@return	Queue�� full�̸� return true, �ƴϸ� return false
	*/
	bool IsFull() const;

	/*
		@brief	Queue�� ������� �˻��Ѵ�
		@pre	Queue�� iniitialize �ž��Ѵ�
		@post	none
		@return	Queue�� empty�� return true, �ƴϸ� return false
	*/
	bool IsEmpty() const;

	/*
		@brief	Queue�� ����
		@pre	Queue�� initialize �ž��Ѵ�
		@post	Queue�� �������
	*/
	void MakeEmpty();

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
		@brief	Queue�� CurPointer�� �ʱ�ȭ��Ų��.
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	CurPointer�� m_Front�� ����Ų��.
	*/
	void ResetList();

	/*
		@brief	Queue�� ���� item�� �����Ѵ�.
		@pre	Queue�� initialize �ž��Ѵ�.
		@post	param�� item�� ���� pointer�� item�� �����Ѵ�.
		@param	item	item�� next item�� �����Ѵ�.
		@return	Queue�� ���̸� return false, �ƴϸ� return true
	*/
	bool GetNextItem(ItemType& item);

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

	/*
		@brief	Queue�� �ִ� ��� item�� ������ Display�Ѵ�.
		@pre	Queue�� initialize �ž��Ѵ�
		@post	Queue�� �ִ� ��� item�� ������ Display�ȴ�.
	*/
	void DisplayQueue();

private:
	int m_Front;
	int m_Rear;
	int m_CurPointer;
	int m_MaxSize;
	ItemType* m_Queue;
};

// constructor
template<typename ItemType>
inline Queue<ItemType>::Queue()
{
	m_MaxSize = MAXQUEUE;
	m_Queue = new ItemType[m_MaxSize];
	m_Front = -1;
	m_Rear = -1;
	m_CurPointer = -1;
}

// destructor
template<typename ItemType>
inline Queue<ItemType>::~Queue()
{
	delete[] m_Queue;
}

// Queue�� ��á���� �˻��Ѵ�
template<typename ItemType>
inline bool Queue<ItemType>::IsFull() const
{
	if ((m_Rear + 1) % m_MaxSize == m_Front) return true;
	return false;
}

// Queue�� ������� �˻��Ѵ�
template<typename ItemType>
inline bool Queue<ItemType>::IsEmpty() const
{
	if (m_Front == m_Rear) return true;
	return false;
}

// Queue�� ����
template<typename ItemType>
inline void Queue<ItemType>::MakeEmpty()
{
	delete[] m_Queue;
	m_Queue = new ItemType[m_MaxSize];
	m_Front = -1;
	m_Rear = -1;
	m_CurPointer = -1;
}

// Queue�� Rear�� ���ο� ���Ҹ� ����
template<typename ItemType>
inline bool Queue<ItemType>::EnQueue(const ItemType& item)
{
	if (IsFull()) {
		cout << "\tQueue�� ���� á���ϴ�\n";
		return false;
	}
	m_Rear = (m_Rear + 1) % m_MaxSize;
	m_Queue[m_Rear] = item;
	return true;
}

// Queue�� Front�� �ִ� ���Ҹ� �����ϰ� ������
template<typename ItemType>
inline bool Queue<ItemType>::DeQueue(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue�� ������ϴ�\n";
		return false;
	}
	m_Front = (m_Front + 1) % m_MaxSize;
	item = m_Queue[m_Front];
	return true;
}

// Queue�� CurPointer�� �ʱ�ȭ��Ų��.
template<typename ItemType>
inline void Queue<ItemType>::ResetList()
{
	m_CurPointer = m_Front;
}

// Queue�� ���� item�� �����Ѵ�.
template<typename ItemType>
inline bool Queue<ItemType>::GetNextItem(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue�� ������ϴ�\n";
		return false;
	}
	if (m_CurPointer == m_Rear) {
		return false;
	}
	m_CurPointer = (m_CurPointer + 1) % m_MaxSize;
	item = m_Queue[m_CurPointer];
	return true;
}

// param�� Id�� ���� Id�� ���� item�� Queue���� ã�� ������
template<typename ItemType>
inline bool Queue<ItemType>::Retrieve(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue�� ������ϴ�.\n";
		return false;
	}
	for (int curPos = m_Front; curPos != m_Rear; curPos = (curPos + 1) % m_MaxSize) {
		curPos++;
		if (m_Queue[curPos] == item) {
			item = m_Queue[curPos];
			return true;
		}
	}
	return false;
}

// param�� Id�� ���� Id�� ���� item�� Queue���� ã�� �����ϰ� ������
template<typename ItemType>
inline bool Queue<ItemType>::Delete(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue�� ������ϴ�.\n";
		return false;
	}
	for (int curPos = m_Front; curPos != m_Rear; curPos = (curPos + 1) % m_MaxSize) {
		curPos++;
		if (m_Queue[curPos] == item) {
			item = m_Queue[curPos];
			for (int i = curPos; i != m_Rear; i = (i + 1) % m_MaxSize) {
				m_Queue[i] = m_Queue[(i + 1) % m_MaxSize];
			}
			m_Rear--;
			return true;
		}
	}
	return false;
}

// param�� Id�� ���� Id�� ���� item�� Queue���� ã�� ������ Replace�Ѵ�.
template<typename ItemType>
inline bool Queue<ItemType>::Replace(const ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue�� ������ϴ�.\n";
		return false;
	}
	for (int curPos = m_Front; curPos != m_Rear; curPos = (curPos + 1) % m_MaxSize) {
		curPos++;
		if (m_Queue[curPos] == item) {
			m_Queue[curPos] = item;
			return true;
		}
	}
	return false;
}
