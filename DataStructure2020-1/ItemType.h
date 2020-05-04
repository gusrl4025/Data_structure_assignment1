#pragma once

class ItemType
{
public:
	/*
		constructor
	*/
	ItemType() {
		m_Kind = 0;
		m_PurchaseDay = 0;
		m_Name = "";
		m_Price = 0;
		m_Id = 0;
		m_ContainerId = -1;
		m_StorageId = -1;
	}

	ItemType(int InId) {
		m_Kind = 0;
		m_PurchaseDay = 0;
		m_Name = "";
		m_Price = 0;
		m_Id = InId;
		m_ContainerId = -1;
		m_StorageId = -1;
	}

	/*
		destructor
	*/
	~ItemType() {};

	/*
		@brief	get Kind of Goods
		@pre	Kind of Goods is set
		@post	none
		@return Kind of Goods
	*/
	int GetKind() const {
		return m_Kind;
	}

	/*
	@brief	get PurchaseDay of Goods
	@pre	PurchaseDay of Goods is set
	@post	none
	@return PurchaseDay of Goods
*/
	int GetPurchaseDay() const {
		return m_PurchaseDay;
	}

	/*
		@brief	get Name of Goods
		@pre	Name of Goods is set
		@post	none
		@return Name of Goods
	*/
	string GetName() const {
		return m_Name;
	}

	/*
		@brief	get Price of Goods
		@pre	Price of Goods is set
		@post	none
		@return Price of Goods
	*/
	int GetPrice() const {
		return m_Price;
	}

	/*
		@brief	get Id of Goods
		@pre	Id of Goods is set
		@post	none
		@return Id of Goods
	*/
	int GetId() const {
		return m_Id;
	}

	/*
		@brief	get ContainerId of Goods
		@pre	ContainerId of Goods is set
		@post	none
		@return Id of Goods
	*/
	int GetContainerId() const {
		return m_ContainerId;
	}

	/*
		@brief	get StorageId of Goods
		@pre	StorageId of Goods is set
		@post	none
		@return Id of Goods
	*/
	int GetStorageId() const {
		return m_StorageId;
	}

	/*
		@brief	set Kind of Goods
		@pre	none
		@post	Kind of Goods is set
		@param	inKind	Kind of Goods
	*/
	void SetKind(int inKind) {
		m_Kind = inKind;
	}

	/*
		@brief	set PurchaseDay of Goods
		@pre	none
		@post	PurchaseDay of Goods is set
		@param	inPurchaseDay	PurchaseDay of Goods
	*/
	void SetPurchaseDay(int inPurchaseDay) {
		m_PurchaseDay = inPurchaseDay;
	}

	/*
		@brief	set Name of Goods
		@pre	none
		@post	Name of Goods is set
		@param	inName	Name of Goods
	*/
	void SetName(string inName) {
		m_Name = inName;
	}

	/*
		@brief	set Price of Goods
		@pre	none
		@post	Price of Goods is set
		@param	inPrice	Price of Goods
	*/
	void SetPrice(int inPrice) {
		m_Price = inPrice;
	}

	/*
		@brief	set Id of Goods
		@pre	none
		@post	Id of Goods is set
		@param	inId	Id of Goods
	*/
	void SetId(int inId) {
		m_Id = inId;
	}

	/*
		@brief	set ContainerId of Goods
		@pre	none
		@post	ContainerId of Goods is set
		@param	inContainerId	Id of Goods
	*/
	void SetContainerId(int inContainerId) {
		m_ContainerId = inContainerId;
	}

	/*
		@brief	set StorageId of Goods
		@pre	none
		@post	StorageId of Goods is set
		@param	inStorageId	Id of Goods
	*/
	void SetStorageId(int inStorageId) {
		m_StorageId = inStorageId;
	}

	/*
		@brief	set Goods record
		@pre	none
		@post	Goods record is set
		@param	inKind			Kind of Goods
		@param	inPurchaseDay	PurchaseDay of Goods
		@param	inName			Name of Goods
		@param	inPrice			Price of Goods
		@param	inId			Id of Goods
		@param	inContainerId	ContainerId of Goods
		@param	inStorageId		StorageId of Goods
	*/
	void SetGoods(int inKind, int inPurchaseDay, string inName, int inPrice, int inId, int inContainerId, int inStorageId) {
		SetKind(inKind);
		SetPurchaseDay(inPurchaseDay);
		SetName(inName);
		SetPrice(inPrice);
		SetId(inId);
		SetContainerId(inContainerId);
		SetStorageId(inStorageId);
	}

	/*
	@brief	set Kind of Goods from keyboard
	@pre	none
	@post	Kind of Goods is set
	*/
	void SetKindFromKB();

	/*
		@brief	set PurchaseDay of Goods from keyboard
		@pre	none
		@post	PurchaseDay of Goods is set
	*/
	void SetPurchaseDayFromKB();

	/*
		@brief	set Name of Goods from keyboard
		@pre	none
		@post	Name of Goods is set
	*/
	void SetNameFromKB();

	/*
		@brief	set Price of Goods from keyboard
		@pre	none
		@post	Price of Goods is set
	*/
	void SetPriceFromKB();

	/*
		@brief	set Id of Goods from keyboard
		@pre	none
		@post	Id of Goods is set
	*/
	void SetIdFromKB();

	/*
		@brief	set ContainerId of Goods from keyboard
		@pre	none
		@post	ContainerId of Goods is set
	*/
	void SetContainerIdFromKB();

	/*
		@brief	set StorageId of Goods from keyboard
		@pre	none
		@post	StorageId of Goods is set
	*/
	void SetStorageIdFromKB();

	/*
		@brief	set Goods record except storage from keyboard
		@pre	none
		@post	Goods record is set
	*/
	void SetGoodsExceptStorageFromKB();

	/*
		@brief	set Goods record from keyboard
		@pre	none
		@post	Goods record is set
	*/
	void SetGoodsFromKB();

	/*
		@brief	display Kind of Goods on screen
		@pre	none
		@post	Kind of Goods is on screen
	*/
	void DisplayKindOnScreen();

	/*
		@brief	display PurchaseDay of Goods on screen
		@pre	none
		@post	PurchaseDay of Goods is on screen
	*/
	void DisplayPurchaseDayOnScreen();

	/*
		@brief	display Name of Goods on screen
		@pre	none
		@post	Name of Goods is on screen
	*/
	void DisplayNameOnScreen();

	/*
		@brief	display Price of Goods on screen
		@pre	none
		@post	Price of Goods is on screen
	*/
	void DisplayPriceOnScreen();

	/*
		@brief	display Id of Goods on screen
		@pre	none
		@post	Id of Goods is on screen
	*/
	void DisplayIdOnScreen();

	/*
		@brief	display ContainerId of Goods on screen
		@pre	none
		@post	ContainerId of Goods is on screen
	*/
	void DisplayContainerIdOnScreen();

	/*
		@brief	display StorageId of Goods on screen
		@pre	none
		@post	StorageId of Goods is on screen
	*/
	void DisplayStorageIdOnScreen();

	/*
		@brief	display Goods record except storage on screeen
		@pre	none
		@post	StorageId of Goods is on screen
	*/
	void DisplayGoodsExceptStorageOnScreen();

	/*
		@brief	display Goods record on screeen
		@pre	none
		@post	Goods record is on screen
	*/
	void DisplayGoodsOnScreen();

	bool operator==(const ItemType& data) {
		if (GetId() == data.GetId()) return true;
		return false;
	}

	bool operator>(const ItemType& data) {
		if (GetId() > data.GetId()) return true;
		return false;
	}

	bool operator<(const ItemType& data) {
		if (GetId() < data.GetId()) return true;
		return false;
	}

	void operator=(const ItemType& data) {
		m_Kind = data.GetKind();
		m_PurchaseDay = data.GetPurchaseDay();
		m_Name = data.GetName();
		m_Price = data.GetPrice();
		m_Id = data.GetId();
		m_ContainerId = data.GetContainerId();
		m_StorageId = data.GetStorageId();
	}

private:
	int m_Kind;			// Kind of Goods
	int m_PurchaseDay;	// PurchaseDay of Goods
	string m_Name;		// Name of Goods
	int m_Price;		// Price of Goods
	int m_Id;			// Id of Goods
	int m_ContainerId;	// ContainerId of Goods
	int m_StorageId;	// StorageId of Goods
};