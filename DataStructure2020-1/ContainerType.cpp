#include "pch.h"
#include "ContainerType.h"

// Constructor
ContainerType::ContainerType()
{
	m_Id = 0;
	m_Location = "";
}

// Constructor
ContainerType::ContainerType(int InContainerId)
{
	m_Id = InContainerId;
	m_Location = "";
}

// Destructor
ContainerType::~ContainerType()
{
}

// m_Id를 가져온다
int ContainerType::GetId() const
{
	return m_Id;
}

// m_Location를 가져온다
string ContainerType::GetLocation() const
{
	return m_Location;
}

// Id를 설정한다
void ContainerType::SetId(int InId)
{
	m_Id = InId;
}

// Location을 설정한다
void ContainerType::SetLocation(string InLocation)
{
	m_Location = InLocation;
}

// Id를 키보드로부터 받아 설정한다
void ContainerType::SetIdFromKB()
{
	int InId;
	cout << "\tContainer의 Id를 입력하시오 : ";
	cin >> InId;
	m_Id = InId;
}

// Location을 키보드로부터 받아 설정한다
void ContainerType::SetLocationFromKB()
{
	string InLocation;
	cout << "\tContainer의 Location을 입력하시오 : ";
	cin >> InLocation;
	m_Location = InLocation;
}

// Container의 기본정보를 키보드로부터 받아 설정한다.
void ContainerType::SetContainerFromKB()
{
	SetIdFromKB();
	SetLocationFromKB();
}

// Id를 출력한다.
void ContainerType::DisplayIdOnScreen()
{
	cout << "\tID : " << m_Id << "\n";
}

// Location을 출력한다.
void ContainerType::DisplayLocationOnScreen()
{
	cout << "\tLocation : " << m_Location << "\n";
}

// Container의 정보를 출력한다
void ContainerType::DisplayContainerOnScreen()
{
	DisplayIdOnScreen();
	DisplayLocationOnScreen();
	cout << "\n";
}

// Container를 비운다.
void ContainerType::MakeEmpty()
{
	m_SimpleItemList.MakeEmpty();
}

// SimpleItemList의 포인터를 초기화시킨다
void ContainerType::ResetSimpleList()
{
	m_SimpleItemList.ResetList();
}

// 포인터의 다음위치의 item을 참조한다
bool ContainerType::GetNextSimpleItem(SimpleItemType& simpleitem)
{
	return m_SimpleItemList.GetNextItem(simpleitem);
}

// item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 추가한다.
bool ContainerType::AddItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Add(SimpleItem)) return true;
	return false;
}

// item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 제거한다.
bool ContainerType::DeleteItem(ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Delete(SimpleItem)) return true;
	return false;
}

// item을 SimpleItem로 바꾸고 m_SimpleItemList에 item을 교체한다.
bool ContainerType::UpdateItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Replace(SimpleItem)) return true;
	return false;
}

// photo를 m_photoList에 추가한다.
bool ContainerType::AddPhoto(const string& photo)
{
	if (m_PhotoList.Add(photo)) return true;
	return false;
}

// photo를 m_photoList에 제거한다.
bool ContainerType::DeletePhoto(string& photo)
{
	if (m_PhotoList.Delete(photo)) return true;
	return false;
}

// photo를 m_photoList에 교체한다.
bool ContainerType::UpdatePhoto(const string& photo)
{
	if (m_PhotoList.Replace(photo)) return true;
	return false;
}

// m_SimpleItemList에 있는 모든 item을 display한다.
void ContainerType::DisplayAllItem()
{
	SimpleItemType simpleitem;
	m_SimpleItemList.ResetList();
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(simpleitem); 
		simpleitem.DisplaySimpleItemOnScreen();
	}
}

// m_PhotoList에 있는 모든 photo를 display한다.
void ContainerType::DisplayAllPhoto()
{
	string photo;
	m_PhotoList.ResetList();
	int length = m_PhotoList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_PhotoList.GetNextItem(photo);
		cout << "\t" << photo << "\n";
	}
}

// Container의 item을 masterlist에서 참조해서 display한다
void ContainerType::DisplayAllDetailsItem(SortedList<ItemType>& masterlist)
{
	SimpleItemType simpleitem;
	m_SimpleItemList.ResetList();
	while (m_SimpleItemList.GetNextItem(simpleitem)) {
		ItemType item;
		item.SetId(simpleitem.GetId());
		masterlist.Retrieve_Binary(item);
		item.DisplayGoodsOnScreen();
	}

}

// SimpleItem의 Id을 입력받아 m_SimpleItemList에서 같은 Id을 가진 item을 참조한다.
bool ContainerType::GetItem(SimpleItemType& item)
{
	SimpleItemType temp;
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(temp);
		if (temp == item) {
			item = temp;
			return true;
		}
	}
	return false;
}

// SimpleItem의 Name을 입력받아 m_SimpleItemList에서 같은 Name을 가진 item을 참조한다.
bool ContainerType::FindByName(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	string InName;
	bool found = false;
	cout << "\t찾으려는 item의 이름을 입력하시오 : ";
	cin >> InName;
	cout << "\n";
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(item);
		if (item.GetName() == InName) {
			item.DisplaySimpleItemOnScreen();
			return true;
		}
	}
	return false;
}

// SimpleItem의 Kind을 입력받아 m_SimpleItemList에서 같은 Kind을 가진 item을 참조한다.
bool ContainerType::FindByKind(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	int InKind;
	cout << "\t찾으려는 item의 종류를 입력하시오 : ";
	cin >> InKind;
	cout << "\n";
	int length = m_SimpleItemList.GetLength();
	for (int CurPos = 0; CurPos < length; CurPos++) {
		m_SimpleItemList.GetNextItem(item);
		if (item.GetKind() == InKind) {
			item.DisplaySimpleItemOnScreen();
			return true;
		}
	}
	return false;
}