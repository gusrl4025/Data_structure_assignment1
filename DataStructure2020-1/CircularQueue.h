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
		@brief	Queue가 꽉찼는지 검사한다
		@pre	Queue가 initialize돼야한다
		@post	none
		@return	Queue가 full이면 return true, 아니면 return false
	*/
	bool IsFull() const;

	/*
		@brief	Queue가 비었는지 검사한다
		@pre	Queue가 iniitialize 돼야한다
		@post	none
		@return	Queue가 empty면 return true, 아니면 return false
	*/
	bool IsEmpty() const;

	/*
		@brief	Queue를 비운다
		@pre	Queue가 initialize 돼야한다
		@post	Queue가 비워진다
	*/
	void MakeEmpty();

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
		@brief	Queue의 CurPointer를 초기화시킨다.
		@pre	Queue가 initialize 돼야한다.
		@post	CurPointer가 m_Front를 가리킨다.
	*/
	void ResetList();

	/*
		@brief	Queue의 다음 item을 참조한다.
		@pre	Queue가 initialize 돼야한다.
		@post	param이 item이 다음 pointer의 item을 참조한다.
		@param	item	item은 next item을 참조한다.
		@return	Queue의 끝이면 return false, 아니면 return true
	*/
	bool GetNextItem(ItemType& item);

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

	/*
		@brief	Queue에 있는 모든 item의 정보는 Display한다.
		@pre	Queue가 initialize 돼야한다
		@post	Queue에 있는 모든 item의 정보가 Display된다.
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

// Queue가 꽉찼는지 검사한다
template<typename ItemType>
inline bool Queue<ItemType>::IsFull() const
{
	if ((m_Rear + 1) % m_MaxSize == m_Front) return true;
	return false;
}

// Queue가 비었는지 검사한다
template<typename ItemType>
inline bool Queue<ItemType>::IsEmpty() const
{
	if (m_Front == m_Rear) return true;
	return false;
}

// Queue를 비운다
template<typename ItemType>
inline void Queue<ItemType>::MakeEmpty()
{
	delete[] m_Queue;
	m_Queue = new ItemType[m_MaxSize];
	m_Front = -1;
	m_Rear = -1;
	m_CurPointer = -1;
}

// Queue의 Rear에 새로운 원소를 넣음
template<typename ItemType>
inline bool Queue<ItemType>::EnQueue(const ItemType& item)
{
	if (IsFull()) {
		cout << "\tQueue가 가득 찼습니다\n";
		return false;
	}
	m_Rear = (m_Rear + 1) % m_MaxSize;
	m_Queue[m_Rear] = item;
	return true;
}

// Queue의 Front에 있는 원소를 제거하고 참조함
template<typename ItemType>
inline bool Queue<ItemType>::DeQueue(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue가 비었습니다\n";
		return false;
	}
	m_Front = (m_Front + 1) % m_MaxSize;
	item = m_Queue[m_Front];
	return true;
}

// Queue의 CurPointer를 초기화시킨다.
template<typename ItemType>
inline void Queue<ItemType>::ResetList()
{
	m_CurPointer = m_Front;
}

// Queue의 다음 item을 참조한다.
template<typename ItemType>
inline bool Queue<ItemType>::GetNextItem(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue가 비었습니다\n";
		return false;
	}
	if (m_CurPointer == m_Rear) {
		return false;
	}
	m_CurPointer = (m_CurPointer + 1) % m_MaxSize;
	item = m_Queue[m_CurPointer];
	return true;
}

// param의 Id와 같은 Id를 가진 item을 Queue에서 찾아 참조함
template<typename ItemType>
inline bool Queue<ItemType>::Retrieve(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue가 비었습니다.\n";
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

// param의 Id와 같은 Id를 가진 item을 Queue에서 찾아 삭제하고 참조함
template<typename ItemType>
inline bool Queue<ItemType>::Delete(ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue가 비었습니다.\n";
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

// param의 Id와 같은 Id를 가진 item을 Queue에서 찾아 정보를 Replace한다.
template<typename ItemType>
inline bool Queue<ItemType>::Replace(const ItemType& item)
{
	if (IsEmpty()) {
		cout << "\tQueue가 비었습니다.\n";
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
