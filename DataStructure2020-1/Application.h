#pragma once

class Application
{
public:

	/*
		constructor
	*/
	Application() {
		m_Command = 0;
		m_Money = 0;
	}

	/*
		destructor
	*/
	~Application() {}

	/*
		@brief	run program(receive the command and execute the function)
		@pre	application is initialized
		@post	program is finished
	*/
	void Run();
	void RunMaster();
	int RunStorage();
	void RunContainer(int InStorageId);
	void RunTemp();
	void RunAccountBook();

	/*
		@brief	shows menu and receive the command from keyboard
		@pre	none
		@post	receive the command
		@return	command
	*/
	int GetCommand();
	int GetCommandMaster();
	int GetCommandStorage();
	int GetCommandContainer(int InStorageId);
	int GetCommandTemp();
	int GetCommandAccountBook();

	/*
		@brief	Item�� �Է¹޾� ContainerId�� ������ MasterList -1�̸� TempList�� �ִ´�.
		@pre	MasterList�� TempList should be initialized
		@post	new item is added to list
		@return if function works return true, otherwise return false
	*/
	bool AddItem();
	bool AddItem(ItemType item);

	/*
		@brief	Id�� �Է¹޾� MasterList�� Container���� �����ش�
		@pre	MasterList, Container�� �ʱ�ȭ �ž��Ѵ�
		@post	the record is deleted in MasterList, Container
		@return if function works return true, otherwise return false
	*/
	bool DeleteItemMasterList();

	/*
		@brief	Item�� �Է¹޾� MasterList�� Container���� �����Ѵ�
		@pre	MasterList, Container�� �ʱ�ȭ �ž��Ѵ�
		@post	the record is replaced in MasterList, Container
		@return if function works return true, otherwise return false
	*/
	bool ReplaceItemMasterList();

	/*
		@brief	Id�� �Է¹޾� MasterList���� �˻��Ѵ�
		@pre	MasterList�� �ʱ�ȭ �ž��Ѵ�
		@post	record user wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool RetrieveItemMasterList();

	/*
		@brief	item ������ �Է¹޾� MasterList���� �˻��Ѵ�
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByKindMasterList();

	/*
		@brief	item �̸��� �Է¹޾� MasterList���� �˻��Ѵ�
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByNameMasterList();

	/*
		@brief	item�� �������� �Է¹޾� MasterList���� �˻��Ѵ�
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByPurchaseDayMasterList();

	/*
		@brief	item�� �������� �������� �Է¹޾� MasterList���� �˻��Ѵ�
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByPurchasePeriodMasterList();

	/*
		@brief	make MasterList empty
		@pre	none
		@post	make MasterList empty
	*/
	void MakeEmptyMasterList();

	/*
		@brief	display all records in MasterList on screen
		@pre	list should be initialized
		@post	display all records in MasterList on screen
	*/
	void DisplayAllItemMasterList();

	/*
		@brief	move item in MasterList to TempList
		@pre	MasterList and TempList should be initialized
		@post	item in MasterList moved to TempList
		@return if function works return true, otherwise return false
	*/
	bool MoveItemMasterToTemp();

	//----------------------- RunStorage -----------------------------------------------------

	/*
		@brief	RunContainer�� �� StorageId�� �Է¹���	
		@pre	none
		@post	none
		@return	return StorageId
	*/
	int GetStorageId();

	/*
		@brief	StorageId�� �Է¹޾� �� �ȿ� �ִ� container�� ������ ����Ʈ�� �����
		@pre	storageList�� �ʱ�ȭ�ž���
		@post	�Է¹��� Storage�ȿ� �ִ� container�� ������ ����Ʈ�� ��µ�
	*/
	void DisplayAllContainer();

	/*
		@brief	StorageId�� �Է¹޾� �� �ȿ� �ִ� container�� �� ������ ����Ʈ�� MasterList�� ������ �����
		@pre	MasterList�� storageList�� �ʱ�ȭ�ž���
		@post	�Է¹��� Storage�ȿ� �ִ� container�� �� ������ ����Ʈ�� ��µ�
	*/
	void DisPlayAllDetailsContainer();
	//----------------------- RunContainer ---------------------------------------------------

	/*
		@brief	������� Container ����� ����Ѵ�
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�
		@post	Container ����� ��µȴ�.
		@param	storage	������ StorageType
	*/
	void PrintContainerList(StorageType& storage);

	/*
		@brief	������� Container�� photo�� �߰��Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�
		@post	������� Container�� photo�� �߰��ȴ�.
		@param	storage	������ StorageType
		@return	Photo�� �߰��Ǹ� return true, �ƴϸ� return false
	*/
	bool AddPhoto(StorageType& storage);

	/*
		@brief	������� Container���� �Է¹��� photo�� �����Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�
		@post	������� Container�� �Է¹��� photo�� ���ŵȴ�.
		@param	storage	������ StorageType
		@return	Photo�� ���ŵǸ� return true, �ƴϸ� return false
	*/
	bool DeletePhoto(StorageType& storage);

	/*
		@brief	������� Container���� �Է¹��� photo�� �����Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�
		@post	������� Container�� �Է¹��� photo�� �����ȴ�.
		@param	storage	������ StorageType
		@return	Photo�� �����Ǹ� return true, �ƴϸ� return false
	*/
	bool UpdatePhoto(StorageType& storage);

	/*
		@brief	������� Container�� photolist�� ����Ѵ�
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�.
		@post	������� Container�� �ִ� photolist�� ��µȴ�.
		@param	storage	������ StorageType
		@return	Photolist�� ��µǸ� return true, �ƴϸ� return false
	*/
	bool PrintPhotoList(StorageType& storage);

	/*
		@brief	������� Container���� item�� �˻��Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�.
		@post	������� Container�� �ִ� item�� �˻��� �� ������
		@param	storage	������ StorageType
		@return	item�� ã���� return true, �ƴϸ� return false
	*/
	bool RetrieveItemContainerList(StorageType& storage);

	/*
		@brief	������� Container���� item�� kind�� �˻��Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�.
		@post	������� Container�� �ִ� item�� kind�� �˻��� �� ������
		@param	storage	������ StorageType
		@return	item�� ã���� return true, �ƴϸ� return false
	*/
	bool SearchByKindContainerList(StorageType& storage);

	/*
		@brief	������� Container���� item�� Name���� �˻��Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�.
		@post	������� Container�� �ִ� item�� Name���� �˻��� �� ������
		@param	storage	������ StorageType
		@return	item�� ã���� return true, �ƴϸ� return false
	*/
	bool SearchByNameContainerList(StorageType& storage);

	/*
		@brief	������� Container�� ����.
		@pre	none
		@post	������� Container�� �������.
		@param	storage	������ StorageType
	*/
	void MakeEmptyContainer(StorageType& storage);

	/*
		@brief	������� container�� �ִ� ��� item�� ����Ѵ�.
		@pre	m_StorageList�� �ʱ�ȭ�ž��Ѵ�.
		@post	������� container�� �ִ� ��� item�� ��µȴ�.
		@param	storage	������ StorageType
	*/
	void DisplayAllItemContainer(StorageType& storage);

	//---------------TempList--------------------------------

		/*
		@brief	receive keynumber from keyboard and find item in TempList which same keynumber and delete that item
		@pre	TempList should be initialized
		@post	the record is deleted in MasterList
		@return if function works return true, otherwise return false
	*/
	bool DeleteItemTempList();

	/*
		@brief	receive Goods record from keyboard and find item has same keynumber and replace the record with new record
		@pre	TempList should be initialized
		@post	the record is replace with new record
		@return if function works return true, otherwise return false
	*/
	bool ReplaceItemTempList();

	/*
		@brief	receive ID from keyboard and find item which has same ID and display that record on screen
		@pre	TempList should be initialized
		@post	record user wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool RetrieveItemTempList();

	/*
		@brief	receive word from keyboard and display the kind of item Kind display that record on screen
		@pre	TempList should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByKindTempList();

	/*
		@brief	receive Name from keyboard and find item which Name include the Name and display that record on screen
		@pre	TempList should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByNameTempList();

	/*
		@brief	receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
		@pre	TempList should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByPurchaseDayTempList();

	/*
		@brief	make TempList empty
		@pre	none
		@post	make TempList empty
	*/
	void MakeEmptyTempList();

	/*
		@brief	display all records in list on screen
		@pre	TempList should be initialized
		@post	display all records in list on screen
	*/
	void DisplayAllItemTempList();

	/*
		@brief	move all items in TempList to MasterList
		@pre	MasterList and TempList should be initialized
		@post	items in TempList moved to MasterList
	*/
	void MoveItemTempToMaster();

	//---------------AccountBook--------------------------------
	/*
		@brief	��¥�� �Է¹޾� �� �� ������ ��ǰ ��ϰ� �Ѿ��� ����Ѵ�.
		@pre	MasterList�� �ʱ�ȭ�žߵȴ�.
		@post	�Է��� ��¥�� ������ ��ǰ�� �Ѿ��� ��µȴ�.
	*/
	void DisplayDayExpenseRecord();

	/*
		@brief	���� �Է¹޾� �� ���� �Һ� �м� ����� ��µȴ�.
		@pre	MasterList�� �ʱ�ȭ�ž��Ѵ�
		@post	�Է¹��� �� ������ ��ǰ ���, �Һ� ������ �м��� ��Ʈ, �Ѿ��� ����Ѵ�.
	*/
	void DisplayMonthExpenseRecord();
	
	/*
		@brief	�ظ� �Է¹޾� �� ���� �Һ� �м� ����� ��µȴ�.
		@pre	MasterList�� �ʱ�ȭ�ž��Ѵ�
		@post	�Է¹��� �ؿ� ������ ��ǰ ���, �Һ� ������ �м��� ��Ʈ, �Ѿ��� ����Ѵ�.
	*/
	void DisplayYearExpenseRecord();

private:
	DoublySortedLinkedList<ItemType> m_MasterList;
	TempType m_TempList;
	SortedList<StorageType> m_StorageList;
	int m_Command;
	int m_Money;
};


