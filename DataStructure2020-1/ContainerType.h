#pragma once

class ContainerType
{
public:
	ContainerType();
	ContainerType(int InContainerId);
	~ContainerType();

	/*
		@brief	m_Id를 가져온다
		@pre	none
		@post	none
		@return	return m_Id
	*/
	int GetId() const;

	/*
		@brief	m_Location를 가져온다
		@pre	none
		@post	none
		@return	return m_Location
	*/
	string GetLocation() const;

	/*
		@brief	Id를 설정한다
		@pre	none
		@post	m_Id = InId
		@param	InId	set할 Id
	*/
	void SetId(int InId);

	/*
		@brief	Location을 설정한다
		@pre	none
		@post	m_Location = InLocation
		@param	InLocation	set할 Location
	*/
	void SetLocation(string InLocation);

	/*
		@brief	Id를 키보드로부터 받아 설정한다
		@pre	none
		@post	Id가 키보드로부터 받아온 값으로 set된다.
	*/
	void SetIdFromKB();

	/*
		@brief	Location을 키보드로부터 받아 설정한다
		@pre	none
		@post	Location이 키보드로부터 받아온 값으로 set된다.
	*/
	void SetLocationFromKB();
	/*
		@brief	Container의 기본정보를 키보드로부터 받아 설정한다.
		@pre	none
		@post	Container의 Location과 Id를 키보드로부터 받아 설정된다.
	*/
	void SetContainerFromKB();

	/*
		@brief	Id를 출력한다.
		@pre	none
		@post	Id가 화면에 출력된다.
	*/
	void DisplayIdOnScreen();

	/*
		@brief	Location을 출력한다.
		@pre	none
		@post	Location이 화면에 출력된다.
	*/
	void DisplayLocationOnScreen();

	/*
		@brief	Container의 정보를 출력한다
		@pre	none
		@post	Container의 Id와 Location이 출력된다.
	*/
	void DisplayContainerOnScreen();

	/*
		@brief	Container를 비운다.
		@pre	none
		@post	Container가 비워진다.
	*/
	void MakeEmpty();

	/*
		@brief	SimpleItemList의 포인터를 초기화시킨다
		@pre	none
		@post	포인터가 초기화된다
	*/
	void ResetSimpleList();

	/*
		@brief	포인터의 다음위치의 item을 참조한다
		@pre	SimpleItemList가 초기화돼야한다
		@post	다음 item을 참조한다
		@param	simpleitem	여기에 다음 item을 참조한다.
		@return	return true if function works, otherwise return false
	*/	
	bool GetNextSimpleItem(SimpleItemType& simpleitem);

	/*
		@brief	item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 추가한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleItemList에 item이 추가됐다.
		@param	item	SimpleItem으로 바꿔줄 data
		@return	return true if function works, otherwise return false
	*/
	bool AddItem(const ItemType& item);

	/*
		@brief	item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 제거한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleItemList에 item이 제거됐다.
		@param	item	SimpleItem으로 바꿔줄 data
		@return	return true if function works, otherwise return false
	*/
	bool DeleteItem(ItemType& item);

	/*
		@brief	item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 교체한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleItemList에 item이 교체됐다.
		@param	item	SimpleItem으로 바꿔줄 data
		@return	return true if function works, otherwise return false
	*/
	bool UpdateItem(const ItemType& item);

	/*
		@brief	photo를 m_photoList에 추가한다.
		@pre	m_photoList가 initialize돼야한다
		@post	m_photoList에 photo가 추가됐다.
		@param	photo	list에 추가할 photo
		@return	return true if function works, otherwise return false
	*/
	bool AddPhoto(const string& photo);

	/*
		@brief	photo를 m_photoList에 제거한다.
		@pre	m_photoList가 initialize돼야한다
		@post	m_photoList에 photo가 제거됐다.
		@param	photo	list에서 제거할 photo
		@return	return true if function works, otherwise return false
	*/
	bool DeletePhoto(string& photo);

	/*
		@brief	photo를 m_photoList에 교체한다.
		@pre	m_photoList가 initialize돼야한다
		@post	m_photoList에 photo가 교체됐다.
		@param	photo	list에 교체할 photo
		@return	return true if function works, otherwise return false
	*/
	bool UpdatePhoto(const string& photo);

	/*
		@brief	m_SimpleItemList에 있는 모든 item을 display한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	m_SimpleList에 있는 모든 item이 display된다.
	*/
	void DisplayAllItem();

	/*
		@brief	m_PhotoList에 있는 모든 photo를 display한다.
		@pre	m_PhotoList가 initialize돼야한다
		@post	m_PhotoList에 있는 모든 photo가 display된다.
	*/
	void DisplayAllPhoto();
	
	/*
		@brief	Container의 item을 masterlist에서 참조해서 display한다
		@pre	masterlist가 초기화돼야한다
		@post	Container의 item 정보가 전부출력된다
	*/
	void DisplayAllDetailsItem(DoublySortedLinkedList<ItemType>& list);

	/*
		@brief	SimpleItem의 Id을 입력받아 m_SimpleItemList에서 같은 Id을 가진 item을 참조한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	찾으려는 Id을 가진 item이 참조된다.
		@param	item	param에 찾으려는 item을 참조한다.
		@return	원하는 item을 찾으면 return true, 아니면 return false
	*/
	bool GetItem(SimpleItemType& item);

	/*
		@brief	SimpleItem의 Name을 입력받아 m_SimpleItemList에서 같은 Name을 가진 item을 참조한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	찾으려는 Name을 가진 item이 참조된다.
		@param	item	param에 찾으려는 item을 참조한다.
		@return	원하는 item을 찾으면 return true, 아니면 return false
	*/
	bool FindByName(SimpleItemType& item);

	/*
		@brief	SimpleItem의 Kind을 입력받아 m_SimpleItemList에서 같은 Kind을 가진 item을 참조한다.
		@pre	m_SimpleItemList가 initialize돼야한다
		@post	찾으려는 Kind을 가진 item이 참조된다.
		@param	item	param에 찾으려는 item을 참조한다.
		@return	원하는 item을 찾으면 return true, 아니면 return false
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
