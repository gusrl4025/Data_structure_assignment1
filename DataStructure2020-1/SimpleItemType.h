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
		@brief	m_Id�� �����´�
		@pre	none
		@post	none
		@return return m_Id
	*/
	int GetId() const;

	/*
		@brief	m_Name�� �����´�
		@pre	none
		@post	none
		@return return m_Name
	*/
	string GetName() const;

	/*
		@brief	m_Kind�� �����´�
		@pre	none
		@post	none
		@return	return m_Kind
	*/
	int GetKind() const;

	/*
		@brief	m_Id�� Set�Ѵ�
		@pre	none
		@post	m_Id = InId
		@param	InId	Id to set
	*/
	void SetId(int InId);

	/*
		@brief	m_Name�� set�Ѵ�.
		@pre	none
		@post	m_Name = InName
		@param	InName	Name to set
	*/
	void SetName(string InName);

	/*
		@brief	m_Kind�� set�Ѵ�.
		@pre	none
		@post	m_Kind = InKind
		@param	InKind	Kind to set
	*/
	void SetKind(int InKind);

	/*
		@brief	item�� ������ set�Ѵ�.
		@pre	none
		@post	m_Id = InId, m_Name = InName
		@param	InId	Id to set
		@param	InName	Name to set
		@param	InKind	Kind to set
	*/
	void SetSimpleItem(int InId, string InName, int InKind);

	/*
		@brief	m_Id�� Ű����κ��� �޾� set�Ѵ�.
		@pre	none
		@post	m_Id�� Ű����κ��� �޾ƿ� ������ set�ȴ�.
	*/
	void SetIdFromKB();

	/*
		@brief	m_Name�� Ű����κ��� �޾� set�Ѵ�.
		@pre	none
		@post	m_Name�� Ű����κ��� �޾ƿ� ������ set�ȴ�.
	*/
	void SetNameFromKB();

	/*
		@brief	m_Kind�� Ű����κ��� �޾� set�Ѵ�.
		@pre	none
		@post	m_Kind�� Ű����κ��� �޾ƿ� ������ set�ȴ�.
	*/
	void SetKindFromKB();

	/*
		@brief	set SimpleItem from keyboard
		@pre	none
		@post	SimpleItem is set
	*/
	void SetSimpleItemFromKB();

	/*
		@brief	m_Name�� display�Ѵ�.
		@pre	none
		@post	m_Name�� display�ȴ�.
	*/
	void DisplayNameOnScreen();

	/*
		@brief	m_Kind�� display�Ѵ�.
		@pre	none
		@post	m_Kind�� display�ȴ�.
	*/
	void DisplayKindOnScreen();

	/*
		@brief	m_Id�� display�Ѵ�.
		@pre	none
		@post	m_Id�� display�ȴ�.
	*/
	void DisplayIdOnScreen();

	/*
		@brief	item�� ������ display�Ѵ�.
		@pre	none
		@post	item�� ������ display�ȴ�.
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

