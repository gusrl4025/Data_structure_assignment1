#pragma once

class TempType
{
public:
	/*
		Constructor
	*/
	TempType();

	/*
		Destructor
	*/
	~TempType();

	/*
		@brief	TempList�� ���� á���� Ȯ��
		@pre	TempList�� �ʱ�ȭ�ž��Ѵ�
		@post	none
		@return	���� á���� return 1, �ƴϸ� return 0;
	*/
	bool IsFull() const;

	/*
		@brief	TempList�� item ������ return
		@pre	none
		@post	none
		@return	return NumOfItems
	*/
	int GetNumOfItems() const;

	/*
		@brief	TempList�� item�� Enqueue�Ѵ�
		@pre	TempList�� initialize�ž��Ѵ�
		@post	TempList�� item�� Enqueue�ǰ� NumOfItems++
		@param	item	Enqueue�� item
		@return	Enqueue�� �Ǿ����� return true, �ƴϸ� return false
	*/
	bool EnQueue(const ItemType& item);

	/*
		@brief	TempList�� Dequeue�Ѵ�.
		@pre	TempList�� initialize�ž��Ѵ�
		@post	TempList�� item�� Dequeue�ǰ� NumOfItems--
		@param	item	Dequeue�� item�� ����
		@return Dequeue�� �Ǿ����� return true, �ƴϸ� return false
	*/
	bool DeQueue(ItemType& item);

	/*
		@brief	TempItemList�� CurPointer�� �ʱ�ȭ��Ų��.
		@pre	TempItemList�� initialize �ž��Ѵ�.
		@post	CurPointer�� m_Front�� ����Ų��.
	*/
	void ResetList();

	/*
		@brief	TempItemList�� ����.
		@pre	TempItemList�� initialize�ž��Ѵ�
		@post	TempItemList�� empty�ȴ�.
	*/
	void MakeEmpty();

	/*
		@brief	param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� ������
		@pre	TempItemList�� initialized �ž��Ѵ�.
		@post	param�� Id�� ���� Id�� ���� item�� ������
		@param	item	���� Id�� ���� TempItemList�� item�� ������
		@return	item�� ã���� return true, �ƴϸ� return false

	*/
	bool Retrieve(ItemType& item);

	/*
		@brief	param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� �����ϰ� ������
		@pre	TempItemList�� initialized �ž��Ѵ�.
		@post	param�� Id�� ���� Id�� ���� item�� TempItemList���� �����ǰ� ������
		@param	item	���� Id�� ���� TempItemList�� item�� ������
		@return	item�� ���������� �����ϸ� return true, �ƴϸ� return false
	*/
	bool Delete(ItemType& item);

	/*
		@brief	param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� ������ Replace�Ѵ�.
		@pre	TempItemList�� initialized �ž��Ѵ�.
		@post	param�� Id�� ���� Id�� ���� item�� param���� replace�ȴ�.
		@param	item	��ü�ϰ��� �ϴ� item
		@return	item�� ���������� ��ü�ϸ� return true, �ƴϸ� return false
	*/
	bool Replace(const ItemType& item);

	/*
		@brief	TempItemList�� �ִ� ��� ���Ҹ� Display�Ѵ�.
		@pre	TempItemList�� initialize �ž��Ѵ�.
		@post	TempItemList�� ��� ���Ұ� display�ȴ�.
	*/
	void DisplayAllTempItems();

	/*
		@brief	�Է¹��� Kind�� ���� �������� TempList���� ã�� ����Ѵ�.
		@pre	TempList�� �ʱ�ȭ�ž��Ѵ�.
		@post	ã�� Kind�� item�� ����Ѵ�.
		@return	item�� ã�Ƽ� ����ϸ� true, �ƴϸ� false
	*/
	bool SearchByKind();

	/*
		@brief	�Է¹��� Name�� ���� �������� TempList���� ã�� ����Ѵ�.
		@pre	TempList�� �ʱ�ȭ�ž��Ѵ�.
		@post	ã�� Name�� item�� ����Ѵ�.
		@return	item�� ã�Ƽ� ����ϸ� true, �ƴϸ� false
	*/
	bool SearchByName();

	/*
		@brief	�Է¹��� PurchaseDay�� ���� �������� TempList���� ã�� ����Ѵ�.
		@pre	TempList�� �ʱ�ȭ�ž��Ѵ�.
		@post	ã�� PurchaseDay�� item�� ����Ѵ�.
		@return	item�� ã�Ƽ� ����ϸ� true, �ƴϸ� false
	*/
	bool SearchByPurchaseDay();
private:
	int NumOfItems;
	Queue<ItemType> m_TempItemList;
};

