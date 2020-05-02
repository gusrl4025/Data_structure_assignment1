#pragma once

template<typename ItemType>
class SortedList
{
public:
	/*
		constructor
	*/
	SortedList();

	/*
		destructor
	*/
	~SortedList();

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

	/*
		@brief	check capacity of list is full
		@pre	none
		@post	none
		@return	return true if a number of records in list is MAXSIZE, otherwise return false
	*/
	bool IsFull() const;

	/*
		@brief	add new record in list
		@pre	list should be initialize
		@post	added the new record in list
		@paran	data	new data
		@return	return 1 if record is added to list successfully otherwise return 0
	*/
	int Add(const ItemType& data);

	/*
		@brief	initilize list iterator
		@pre	list should be initilized
		@post	iterator is reset
	*/
	void ResetList();

	/*
		@brief	move list iterator to the next item in list and get that item
		@pre	list should be initilized
		@post	iterator is reset
		@param	data	get current item of list
		@return	return -1 if current item is last item in list otherwise return index of current item
	*/
	int GetNextItem(ItemType& data);

	/*
		@brief	find item which has same keynumber of parameter in list
		@pre	list should be initilized
		@post	parameter changed to item which has same keynumber in list
		@param	data	data to find
		@return	if function works successfully return true, otherwise return false
	*/
	bool Retrieve(ItemType& data);

	/*
		@brief	find item which has same keynumber of parameter in list using binary search
		@pre	list should be initilized
		@post	parameter changed to item which has same keynumber in list
		@param	data	data to find
		@return	if function works successfully return true, otherwise return false
	*/
	bool Retrieve_Binary(ItemType& data);

	/*
		@brief	delete item which is same with param
		@pre	list should be initilized
		@post	deleted data which you want to delete in list
		@param	data	data to delete
		@return	if function works successfully return true, otherwise return false
	*/
	bool Delete(ItemType& data);

	/*
		@brief	replace item which has same keynumber with param
		@pre	list should be initilized
		@post	replaced data which you want to replace in list
		@param	data	data to replace
		@return	if function works successfully return true, otherwise return false
	*/
	bool Replace(const ItemType& data);

private:
	ItemType* m_Array; // ���ڵ�迭
	int m_Length; // ����Ʈ������ȷ��ڵ��
	int m_CurPointer; // current pointer
	int m_MaxSize; // MaxSize of list
};


template<typename ItemType>
SortedList<ItemType>::SortedList() {
	m_MaxSize = MAXSIZE;
	m_Array = new ItemType[m_MaxSize];
	m_Length = 0;
	m_CurPointer = -1;
}

template<typename ItemType>
SortedList<ItemType>::~SortedList() {
	//delete[] m_Array;
}

// make list empty
template<typename ItemType>
void SortedList<ItemType>::MakeEmpty() {
	m_Length = 0;
}

// get number of records in list
template<typename ItemType>
int SortedList<ItemType>::GetLength() const {
	return m_Length;
}

// check capacity of list is full
template<typename ItemType>
bool SortedList<ItemType>::IsFull() const {
	if (m_Length == MAXSIZE) return true;
	else return false;
}

// add new record in list
template<typename ItemType>
int SortedList<ItemType>::Add(const ItemType& data) {
	if (IsFull()) {
		ItemType* TempList = new ItemType[m_Length];
		for (int i = 0; i < m_Length; ++i) {
			TempList[i] = m_Array[i];
		}
		//delete[] m_Array;
		m_MaxSize += MAXSIZE;
		m_Array = new ItemType[m_MaxSize];
		for (int i = 0; i < m_Length; ++i) {
			m_Array[i] = TempList[i];
		}
		delete[] TempList;
	}
	if (m_Length == 0) {
		m_Array[m_Length] = data;
		m_Length++;
		return true;
	}
	int iPos = 0;
	for (iPos; iPos <= m_Length; iPos++) {
		if (iPos == m_Length) break;
		if (m_Array[iPos] == data) {
			cout << "\t�ߺ��� Id�Դϴ�.\n";
			return false;
		}
		if (m_Array[iPos] > data) break;
	}
	if (iPos == m_Length) {
		m_Array[iPos] = data;
		m_Length++;
		return true;
	}
	if (iPos < m_Length) {
		for (int i = m_Length; i > iPos; i--) {
			m_Array[i] = m_Array[i - 1];
		}
		m_Array[iPos] = data;
		m_Length++;
		return true;
	}
}

// initilize list iterator
template<typename ItemType>
void SortedList<ItemType>::ResetList() {
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item
template<typename ItemType>
int SortedList<ItemType>::GetNextItem(ItemType& data) {
	if (m_CurPointer == m_Length) return -1; // iterator�� list�� ���̸� -1�� return
	else {
		m_CurPointer++; // iterator�� ����
		data = m_Array[m_CurPointer]; // data�� next item�� ��
		return m_CurPointer;
	}
}

// find item which has same keynumber of parameter in list
template<typename ItemType>
bool SortedList<ItemType>::Retrieve(ItemType& data) {
	for (int curPos = 0; curPos < m_Length; curPos++) {
		if (m_Array[curPos] == data) {
			data = m_Array[curPos];
			return true;
		}
		else if (m_Array[curPos] > data) return false;
	}
	return false;
}

// find item which has same keynumber of parameter in list using binary search
template<typename ItemType>
bool SortedList<ItemType>::Retrieve_Binary(ItemType& data) {
	int curPos = 0;
	bool found = false;

	int first = 0;
	int last = m_Length - 1;
	int mid;

	while (!found && !(first > last)) {
		mid = (first + last) / 2;
		if (m_Array[mid] == data) {
			data = m_Array[mid];
			found = true;
			return true;
		}
		if (m_Array[mid] > data) {
			last = mid - 1;
		}
		if (m_Array[mid] < data) {
			first = mid + 1;
		}
	}
	return false;
}

// delete item which is same with param
template<typename ItemType>
bool SortedList<ItemType>::Delete(ItemType& data) {
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++) { // ����Ʈ�� ���̸�ŭ �˻��Ѵ�.
		if (data == m_Array[m_CurPointer]) {	// ã���� �ϴ� data�� ���� item�� �߰��ϸ�
			for (int i = m_CurPointer; i < m_Length - 1; i++) {
				m_Array[i] = m_Array[i + 1];	// item�� data�� ������ ��ü�Ѵ�.
			}
			m_Length--;
			return true; // �Լ��� �� �۵������Ƿ� true�� return�Ѵ�.
		}
	}
	return false;	// �Լ��� �� �۵����� �������Ƿ� false�� return�Ѵ�.
}

// replace item which has same keynumber with param
template<typename ItemType>
bool SortedList<ItemType>::Replace(const ItemType& data) {
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++) { // ����Ʈ�� ���̸�ŭ �˻��Ѵ�.
		if (m_Array[m_CurPointer] == data) {	// ã���� �ϴ� data�� ���� item�� �߰��ϸ�
			m_Array[m_CurPointer] = data;	// item�� data�� ������ ��ü�Ѵ�.
			return true;	// �Լ��� �� �۵������Ƿ� true�� return�Ѵ�.
		}
	}
	return false;	// �Լ��� �� �۵����� �������Ƿ� false�� return�Ѵ�.
}