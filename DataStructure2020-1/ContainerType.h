#pragma once

class ContainerType
{
public:
	ContainerType();
	ContainerType(int InContainerId);
	~ContainerType();

	/*
		@brief	m_Id�� �����´�
		@pre	none
		@post	none
		@return	return m_Id
	*/
	int GetId() const;

	/*
		@brief	m_Location�� �����´�
		@pre	none
		@post	none
		@return	return m_Location
	*/
	string GetLocation() const;

	/*
		@brief	Id�� �����Ѵ�
		@pre	none
		@post	m_Id = InId
		@param	InId	set�� Id
	*/
	void SetId(int InId);

	/*
		@brief	Location�� �����Ѵ�
		@pre	none
		@post	m_Location = InLocation
		@param	InLocation	set�� Location
	*/
	void SetLocation(string InLocation);

	/*
		@brief	Id�� Ű����κ��� �޾� �����Ѵ�
		@pre	none
		@post	Id�� Ű����κ��� �޾ƿ� ������ set�ȴ�.
	*/
	void SetIdFromKB();

	/*
		@brief	Location�� Ű����κ��� �޾� �����Ѵ�
		@pre	none
		@post	Location�� Ű����κ��� �޾ƿ� ������ set�ȴ�.
	*/
	void SetLocationFromKB();
	/*
		@brief	Container�� �⺻������ Ű����κ��� �޾� �����Ѵ�.
		@pre	none
		@post	Container�� Location�� Id�� Ű����κ��� �޾� �����ȴ�.
	*/
	void SetContainerFromKB();

	/*
		@brief	Id�� ����Ѵ�.
		@pre	none
		@post	Id�� ȭ�鿡 ��µȴ�.
	*/
	void DisplayIdOnScreen();

	/*
		@brief	Location�� ����Ѵ�.
		@pre	none
		@post	Location�� ȭ�鿡 ��µȴ�.
	*/
	void DisplayLocationOnScreen();

	/*
		@brief	Container�� ������ ����Ѵ�
		@pre	none
		@post	Container�� Id�� Location�� ��µȴ�.
	*/
	void DisplayContainerOnScreen();

	/*
		@brief	Container�� ����.
		@pre	none
		@post	Container�� �������.
	*/
	void MakeEmpty();

	/*
		@brief	SimpleItemList�� �����͸� �ʱ�ȭ��Ų��
		@pre	none
		@post	�����Ͱ� �ʱ�ȭ�ȴ�
	*/
	void ResetSimpleList();

	/*
		@brief	�������� ������ġ�� item�� �����Ѵ�
		@pre	SimpleItemList�� �ʱ�ȭ�ž��Ѵ�
		@post	���� item�� �����Ѵ�
		@param	simpleitem	���⿡ ���� item�� �����Ѵ�.
		@return	return true if function works, otherwise return false
	*/	
	bool GetNextSimpleItem(SimpleItemType& simpleitem);

	/*
		@brief	item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �߰��Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleItemList�� item�� �߰��ƴ�.
		@param	item	SimpleItem���� �ٲ��� data
		@return	return true if function works, otherwise return false
	*/
	bool AddItem(const ItemType& item);

	/*
		@brief	item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleItemList�� item�� ���ŵƴ�.
		@param	item	SimpleItem���� �ٲ��� data
		@return	return true if function works, otherwise return false
	*/
	bool DeleteItem(ItemType& item);

	/*
		@brief	item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� ��ü�Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleItemList�� item�� ��ü�ƴ�.
		@param	item	SimpleItem���� �ٲ��� data
		@return	return true if function works, otherwise return false
	*/
	bool UpdateItem(const ItemType& item);

	/*
		@brief	photo�� m_photoList�� �߰��Ѵ�.
		@pre	m_photoList�� initialize�ž��Ѵ�
		@post	m_photoList�� photo�� �߰��ƴ�.
		@param	photo	list�� �߰��� photo
		@return	return true if function works, otherwise return false
	*/
	bool AddPhoto(const string& photo);

	/*
		@brief	photo�� m_photoList�� �����Ѵ�.
		@pre	m_photoList�� initialize�ž��Ѵ�
		@post	m_photoList�� photo�� ���ŵƴ�.
		@param	photo	list���� ������ photo
		@return	return true if function works, otherwise return false
	*/
	bool DeletePhoto(string& photo);

	/*
		@brief	photo�� m_photoList�� ��ü�Ѵ�.
		@pre	m_photoList�� initialize�ž��Ѵ�
		@post	m_photoList�� photo�� ��ü�ƴ�.
		@param	photo	list�� ��ü�� photo
		@return	return true if function works, otherwise return false
	*/
	bool UpdatePhoto(const string& photo);

	/*
		@brief	m_SimpleItemList�� �ִ� ��� item�� display�Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	m_SimpleList�� �ִ� ��� item�� display�ȴ�.
	*/
	void DisplayAllItem();

	/*
		@brief	m_PhotoList�� �ִ� ��� photo�� display�Ѵ�.
		@pre	m_PhotoList�� initialize�ž��Ѵ�
		@post	m_PhotoList�� �ִ� ��� photo�� display�ȴ�.
	*/
	void DisplayAllPhoto();
	
	/*
		@brief	Container�� item�� masterlist���� �����ؼ� display�Ѵ�
		@pre	masterlist�� �ʱ�ȭ�ž��Ѵ�
		@post	Container�� item ������ ������µȴ�
	*/
	void DisplayAllDetailsItem(DoublySortedLinkedList<ItemType>& list);

	/*
		@brief	SimpleItem�� Id�� �Է¹޾� m_SimpleItemList���� ���� Id�� ���� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	ã������ Id�� ���� item�� �����ȴ�.
		@param	item	param�� ã������ item�� �����Ѵ�.
		@return	���ϴ� item�� ã���� return true, �ƴϸ� return false
	*/
	bool GetItem(SimpleItemType& item);

	/*
		@brief	SimpleItem�� Name�� �Է¹޾� m_SimpleItemList���� ���� Name�� ���� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	ã������ Name�� ���� item�� �����ȴ�.
		@param	item	param�� ã������ item�� �����Ѵ�.
		@return	���ϴ� item�� ã���� return true, �ƴϸ� return false
	*/
	bool FindByName(SimpleItemType& item);

	/*
		@brief	SimpleItem�� Kind�� �Է¹޾� m_SimpleItemList���� ���� Kind�� ���� item�� �����Ѵ�.
		@pre	m_SimpleItemList�� initialize�ž��Ѵ�
		@post	ã������ Kind�� ���� item�� �����ȴ�.
		@param	item	param�� ã������ item�� �����Ѵ�.
		@return	���ϴ� item�� ã���� return true, �ƴϸ� return false
	*/
	bool FindByKind(SimpleItemType& item);

	bool operator==(const ContainerType& container) {
		if (GetId() == container.GetId()) return true;
		return false;
	}

	bool operator>(const ContainerType& container) {
		if (GetId() > container.GetId()) return true;
		return false;
	}

	bool operator<(const ContainerType& container) {
		if (GetId() < container.GetId()) return true;
		return false;
	}

private:
	int m_Id;
	string m_Location;
	UnSortedList<string> m_PhotoList;
	UnSortedList<SimpleItemType> m_SimpleItemList;
};
