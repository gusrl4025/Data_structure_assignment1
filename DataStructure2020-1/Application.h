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
		@brief	Item을 입력받아 ContainerId가 있으면 MasterList -1이면 TempList에 넣는다.
		@pre	MasterList와 TempList should be initialized
		@post	new item is added to list
		@return if function works return true, otherwise return false
	*/
	bool AddItem();
	bool AddItem(ItemType item);

	/*
		@brief	Id를 입력받아 MasterList와 Container에서 지워준다
		@pre	MasterList, Container가 초기화 돼야한다
		@post	the record is deleted in MasterList, Container
		@return if function works return true, otherwise return false
	*/
	bool DeleteItemMasterList();

	/*
		@brief	Item을 입력받아 MasterList와 Container에서 수정한다
		@pre	MasterList, Container가 초기화 돼야한다
		@post	the record is replaced in MasterList, Container
		@return if function works return true, otherwise return false
	*/
	bool ReplaceItemMasterList();

	/*
		@brief	Id을 입력받아 MasterList에서 검색한다
		@pre	MasterList가 초기화 돼야한다
		@post	record user wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool RetrieveItemMasterList();

	/*
		@brief	item 종류를 입력받아 MasterList에서 검색한다
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByKindMasterList();

	/*
		@brief	item 이름을 입력받아 MasterList에서 검색한다
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByNameMasterList();

	/*
		@brief	item의 구매일을 입력받아 MasterList에서 검색한다
		@pre	Masterlist should be initialized
		@post	the records wanted to find displayed on screen
		@return if function works return true, otherwise return false
	*/
	bool SearchByPurchaseDayMasterList();

	/*
		@brief	item의 구매일을 구간으로 입력받아 MasterList에서 검색한다
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
		@brief	RunContainer에 쓸 StorageId를 입력받음	
		@pre	none
		@post	none
		@return	return StorageId
	*/
	int GetStorageId();

	/*
		@brief	StorageId를 입력받아 그 안에 있는 container의 정보와 리스트를 출력함
		@pre	storageList가 초기화돼야함
		@post	입력받은 Storage안에 있는 container의 정보와 리스트가 출력됨
	*/
	void DisplayAllContainer();

	/*
		@brief	StorageId를 입력받아 그 안에 있는 container의 상세 정보와 리스트를 MasterList를 참조해 출력함
		@pre	MasterList와 storageList가 초기화돼야함
		@post	입력받은 Storage안에 있는 container의 상세 정보와 리스트가 출력됨
	*/
	void DisPlayAllDetailsContainer();
	//----------------------- RunContainer ---------------------------------------------------

	/*
		@brief	저장소의 Container 목록을 출력한다
		@pre	m_StorageList가 초기화돼야한다
		@post	Container 목록이 출력된다.
		@param	storage	참조할 StorageType
	*/
	void PrintContainerList(StorageType& storage);

	/*
		@brief	저장소의 Container에 photo를 추가한다.
		@pre	m_StorageList가 초기화돼야한다
		@post	저장소의 Container에 photo를 추가된다.
		@param	storage	참조할 StorageType
		@return	Photo가 추가되면 return true, 아니면 return false
	*/
	bool AddPhoto(StorageType& storage);

	/*
		@brief	저장소의 Container에서 입력받은 photo를 제거한다.
		@pre	m_StorageList가 초기화돼야한다
		@post	저장소의 Container에 입력받은 photo가 제거된다.
		@param	storage	참조할 StorageType
		@return	Photo가 제거되면 return true, 아니면 return false
	*/
	bool DeletePhoto(StorageType& storage);

	/*
		@brief	저장소의 Container에서 입력받은 photo를 수정한다.
		@pre	m_StorageList가 초기화돼야한다
		@post	저장소의 Container에 입력받은 photo가 수정된다.
		@param	storage	참조할 StorageType
		@return	Photo가 수정되면 return true, 아니면 return false
	*/
	bool UpdatePhoto(StorageType& storage);

	/*
		@brief	저장소의 Container의 photolist를 출력한다
		@pre	m_StorageList가 초기화돼야한다.
		@post	저장소의 Container에 있는 photolist가 출력된다.
		@param	storage	참조할 StorageType
		@return	Photolist가 출력되면 return true, 아니면 return false
	*/
	bool PrintPhotoList(StorageType& storage);

	/*
		@brief	저장소의 Container에서 item을 검색한다.
		@pre	m_StorageList가 초기화돼야한다.
		@post	저장소의 Container에 있는 item을 검색한 후 참조함
		@param	storage	참조할 StorageType
		@return	item을 찾으면 return true, 아니면 return false
	*/
	bool RetrieveItemContainerList(StorageType& storage);

	/*
		@brief	저장소의 Container에서 item을 kind로 검색한다.
		@pre	m_StorageList가 초기화돼야한다.
		@post	저장소의 Container에 있는 item을 kind로 검색한 후 참조함
		@param	storage	참조할 StorageType
		@return	item을 찾으면 return true, 아니면 return false
	*/
	bool SearchByKindContainerList(StorageType& storage);

	/*
		@brief	저장소의 Container에서 item을 Name으로 검색한다.
		@pre	m_StorageList가 초기화돼야한다.
		@post	저장소의 Container에 있는 item을 Name으로 검색한 후 참조함
		@param	storage	참조할 StorageType
		@return	item을 찾으면 return true, 아니면 return false
	*/
	bool SearchByNameContainerList(StorageType& storage);

	/*
		@brief	저장소의 Container를 비운다.
		@pre	none
		@post	저장소의 Container가 비워진다.
		@param	storage	참조할 StorageType
	*/
	void MakeEmptyContainer(StorageType& storage);

	/*
		@brief	저장소의 container에 있는 모든 item을 출력한다.
		@pre	m_StorageList가 초기화돼야한다.
		@post	저장소의 container에 있는 모든 item이 출력된다.
		@param	storage	참조할 StorageType
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
		@brief	날짜를 입력받아 그 날 구매한 물품 목록과 총액을 출력한다.
		@pre	MasterList가 초기화돼야된다.
		@post	입력한 날짜에 구매한 물품과 총액이 출력된다.
	*/
	void DisplayDayExpenseRecord();

	/*
		@brief	달을 입력받아 그 달의 소비 분석 결과가 출력된다.
		@pre	MasterList가 초기화돼야한다
		@post	입력받은 달 구매한 물품 목록, 소비 패턴을 분석한 차트, 총액을 출력한다.
	*/
	void DisplayMonthExpenseRecord();
	
	/*
		@brief	해를 입력받아 그 해의 소비 분석 결과가 출력된다.
		@pre	MasterList가 초기화돼야한다
		@post	입력받은 해에 구매한 물품 목록, 소비 패턴을 분석한 차트, 총액을 출력한다.
	*/
	void DisplayYearExpenseRecord();

private:
	DoublySortedLinkedList<ItemType> m_MasterList;
	TempType m_TempList;
	SortedList<StorageType> m_StorageList;
	int m_Command;
	int m_Money;
};


