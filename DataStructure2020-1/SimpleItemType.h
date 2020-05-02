#pragma once

class SimpleItemType
{
public:
	/*
		Constructor
	*/
	SimpleItemType();

	/*
		Destructor
	*/
	~SimpleItemType();

	/*
		@brief	m_Id을 가져온다
		@pre	none
		@post	none
		@return return m_Id
	*/
	int GetId() const;

	/*
		@brief	m_Name을 가져온다
		@pre	none
		@post	none
		@return return m_Name
	*/
	string GetName() const;

	/*
		@brief	m_Kind를 가져온다
		@pre	none
		@post	none
		@return	return m_Kind
	*/
	int GetKind() const;

	/*
		@brief	m_Id를 Set한다
		@pre	none
		@post	m_Id = InId
		@param	InId	Id to set
	*/
	void SetId(int InId);

	/*
		@brief	m_Name을 set한다.
		@pre	none
		@post	m_Name = InName
		@param	InName	Name to set
	*/
	void SetName(string InName);

	/*
		@brief	m_Kind을 set한다.
		@pre	none
		@post	m_Kind = InKind
		@param	InKind	Kind to set
	*/
	void SetKind(int InKind);

	/*
		@brief	item의 정보를 set한다.
		@pre	none
		@post	m_Id = InId, m_Name = InName
		@param	InId	Id to set
		@param	InName	Name to set
		@param	InKind	Kind to set
	*/
	void SetSimpleItem(int InId, string InName, int InKind);

	/*
		@brief	m_Id를 키보드로부터 받아 set한다.
		@pre	none
		@post	m_Id가 키보드로부터 받아온 값으로 set된다.
	*/
	void SetIdFromKB();

	/*
		@brief	m_Name을 키보드로부터 받아 set한다.
		@pre	none
		@post	m_Name이 키보드로부터 받아온 값으로 set된다.
	*/
	void SetNameFromKB();

	/*
		@brief	m_Kind를 키보드로부터 받아 set한다.
		@pre	none
		@post	m_Kind가 키보드로부터 받아온 값으로 set된다.
	*/
	void SetKindFromKB();

	/*
		@brief	set SimpleItem from keyboard
		@pre	none
		@post	SimpleItem is set
	*/
	void SetSimpleItemFromKB();

	/*
		@brief	m_Name을 display한다.
		@pre	none
		@post	m_Name이 display된다.
	*/
	void DisplayNameOnScreen();

	/*
		@brief	m_Kind을 display한다.
		@pre	none
		@post	m_Kind이 display된다.
	*/
	void DisplayKindOnScreen();

	/*
		@brief	m_Id를 display한다.
		@pre	none
		@post	m_Id가 display된다.
	*/
	void DisplayIdOnScreen();

	/*
		@brief	item의 정보를 display한다.
		@pre	none
		@post	item의 정보가 display된다.
	*/
	void DisplaySimpleItemOnScreen();

	bool operator==(const SimpleItemType& item) {
		if (GetId() == item.GetId()) return true;
		return false;
	}

	void operator=(const SimpleItemType& item) {
		m_Name = item.GetName();
		m_Kind = item.GetKind();
		m_Id = item.GetId();
	}

	bool operator==(const ItemType& item) {
		if (GetId() == item.GetId()) return true;
		return false;
	}

	void operator=(const ItemType& item) {
		m_Name = item.GetName();
		m_Kind = item.GetKind();
		m_Id = item.GetId();
	}

private:
	int m_Id;
	string m_Name;
	int m_Kind;
};

