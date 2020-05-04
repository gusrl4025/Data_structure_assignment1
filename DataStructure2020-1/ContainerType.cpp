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

// m_Id�� �����´�
int ContainerType::GetId() const
{
	return m_Id;
}

// m_Location�� �����´�
string ContainerType::GetLocation() const
{
	return m_Location;
}

// Id�� �����Ѵ�
void ContainerType::SetId(int InId)
{
	m_Id = InId;
}

// Location�� �����Ѵ�
void ContainerType::SetLocation(string InLocation)
{
	m_Location = InLocation;
}

// Id�� Ű����κ��� �޾� �����Ѵ�
void ContainerType::SetIdFromKB()
{
	int InId;
	cout << "\tContainer�� Id�� �Է��Ͻÿ� : ";
	cin >> InId;
	m_Id = InId;
}

// Location�� Ű����κ��� �޾� �����Ѵ�
void ContainerType::SetLocationFromKB()
{
	string InLocation;
	cout << "\tContainer�� Location�� �Է��Ͻÿ� : ";
	cin >> InLocation;
	m_Location = InLocation;
}

// Container�� �⺻������ Ű����κ��� �޾� �����Ѵ�.
void ContainerType::SetContainerFromKB()
{
	SetIdFromKB();
	SetLocationFromKB();
}

// Id�� ����Ѵ�.
void ContainerType::DisplayIdOnScreen()
{
	cout << "\tID : " << m_Id << "\n";
}

// Location�� ����Ѵ�.
void ContainerType::DisplayLocationOnScreen()
{
	cout << "\tLocation : " << m_Location << "\n";
}

// Container�� ������ ����Ѵ�
void ContainerType::DisplayContainerOnScreen()
{
	DisplayIdOnScreen();
	DisplayLocationOnScreen();
	cout << "\n";
}

// Container�� ����.
void ContainerType::MakeEmpty()
{
	m_SimpleItemList.MakeEmpty();
}

// SimpleItemList�� �����͸� �ʱ�ȭ��Ų��
void ContainerType::ResetSimpleList()
{
	m_SimpleItemList.ResetList();
}

// �������� ������ġ�� item�� �����Ѵ�
bool ContainerType::GetNextSimpleItem(SimpleItemType& simpleitem)
{
	return m_SimpleItemList.GetNextItem(simpleitem);
}

// item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �߰��Ѵ�.
bool ContainerType::AddItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Add(SimpleItem)) return true;
	return false;
}

// item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� �����Ѵ�.
bool ContainerType::DeleteItem(ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Delete(SimpleItem)) return true;
	return false;
}

// item�� SimpleItem�� �ٲٰ� m_SimpleItemList�� item�� ��ü�Ѵ�.
bool ContainerType::UpdateItem(const ItemType& item)
{
	SimpleItemType SimpleItem;
	SimpleItem = item;
	if (m_SimpleItemList.Replace(SimpleItem)) return true;
	return false;
}

// photo�� m_photoList�� �߰��Ѵ�.
bool ContainerType::AddPhoto(const string& photo)
{
	if (m_PhotoList.Add(photo)) return true;
	return false;
}

// photo�� m_photoList�� �����Ѵ�.
bool ContainerType::DeletePhoto(string& photo)
{
	if (m_PhotoList.Delete(photo)) return true;
	return false;
}

// photo�� m_photoList�� ��ü�Ѵ�.
bool ContainerType::UpdatePhoto(const string& photo)
{
	if (m_PhotoList.Replace(photo)) return true;
	return false;
}

// m_SimpleItemList�� �ִ� ��� item�� display�Ѵ�.
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

// m_PhotoList�� �ִ� ��� photo�� display�Ѵ�.
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

// Container�� item�� masterlist���� �����ؼ� display�Ѵ�
void ContainerType::DisplayAllDetailsItem(DoublySortedLinkedList<ItemType>& list)
{
	SimpleItemType simpleitem;
	m_SimpleItemList.ResetList();
	while (m_SimpleItemList.GetNextItem(simpleitem)) {
		ItemType item(simpleitem.GetId());
		list.Retrieve(item);
		item.DisplayGoodsExceptStorageOnScreen();
	}

}

// SimpleItem�� Id�� �Է¹޾� m_SimpleItemList���� ���� Id�� ���� item�� �����Ѵ�.
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

// SimpleItem�� Name�� �Է¹޾� m_SimpleItemList���� ���� Name�� ���� item�� �����Ѵ�.
bool ContainerType::FindByName(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	string InName;
	bool found = false;
	cout << "\tã������ item�� �̸��� �Է��Ͻÿ� : ";
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

// SimpleItem�� Kind�� �Է¹޾� m_SimpleItemList���� ���� Kind�� ���� item�� �����Ѵ�.
bool ContainerType::FindByKind(SimpleItemType& item)
{
	m_SimpleItemList.ResetList();
	int InKind;
	cout << "\tã������ item�� ������ �Է��Ͻÿ� : ";
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