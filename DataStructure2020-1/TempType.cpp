#include "pch.h"
#include "TempType.h"

// constructor
TempType::TempType()
{
	NumOfItems = 0;
}

// destructor
TempType::~TempType()
{
}


// TempList의 item 개수를 return	
int TempType::GetNumOfItems() const
{
	return NumOfItems;
}

// TempList에 item을 Enqueue한다
bool TempType::EnQueue(const ItemType& item)
{
	ItemType temp(item.GetId());
	if (!m_TempItemList.Retrieve(temp)) {
		m_TempItemList.EnQueue(item);
		return true;
	}
	cout << "\t중복된 Id가 존재합니다\n";
	return false;
}

// TempList을 Dequeue한다.
bool TempType::DeQueue(ItemType& item)
{
	if (m_TempItemList.DeQueue(item)) {
		NumOfItems--;
		return true;
	};
	return false;
}

// TempItemList를 비운다.
void TempType::MakeEmpty()
{
	m_TempItemList.MakeEmpty();
	NumOfItems = 0;
}

// param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 참조함
bool TempType::Retrieve(ItemType& item)
{
	if (m_TempItemList.Retrieve(item)) return true;
	return false;
}

// param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 삭제하고 참조함1
bool TempType::Delete(ItemType& item)
{
	if (m_TempItemList.Delete(item)) {
		NumOfItems--;
		return true;
	}
	return false;
}

// param의 Id와 같은 Id를 가진 item을 TempItemList에서 찾아 정보를 Replace한다.
bool TempType::Replace(const ItemType& item)
{
	if (m_TempItemList.Replace(item)) return true;
	return false;
}

// TempItemList에 있는 모든 원소를 Display한다.	
void TempType::DisplayAllTempItems()
{
	DoublyQueueIterator<ItemType> itor(m_TempItemList);
	ItemType item = itor.Next();
	
	while (itor.NextNotNull()) {
		item.DisplayGoodsExceptStorageOnScreen();
		item = itor.Next();
	}
}

// 입력받은 Kind와 같은 아이템을 TempList에서 찾아 출력한다.
bool TempType::SearchByKind()
{
	DoublyQueueIterator<ItemType> itor(m_TempItemList);
	ItemType item = itor.Next();
	
	ItemType temp;
	temp.SetKindFromKB();
	bool found = false;

	cout << "\t=====================Item Kind:" << temp.GetKind() << "=====================\n";
	
	while (itor.NextNotNull()) {
		if (item.GetKind() == temp.GetKind()) {
			item.DisplayGoodsExceptStorageOnScreen();
			item = itor.Next();
			found = true;
		}
	}
	if (!found) {
		cout << "\t찾는 종류의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// 입력받은 Name와 같은 아이템을 TempList에서 찾아 출력한다.
bool TempType::SearchByName()
{
	DoublyQueueIterator<ItemType> itor(m_TempItemList);
	ItemType item = itor.Next();

	ItemType temp;
	temp.SetNameFromKB();
	bool found = false;

	cout << "\t=====================Item Name:" << temp.GetName() << "=====================\n";

	while (itor.NextNotNull()) {
		if (item.GetName() == temp.GetName()) {
			item.DisplayGoodsExceptStorageOnScreen();
			item = itor.Next();
			found = true;
		}
	}
	if (!found) {
		cout << "\t찾는 이름의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// 입력받은 PurchaseDay와 같은 아이템을 TempList에서 찾아 출력한다.
bool TempType::SearchByPurchaseDay()
{
	DoublyQueueIterator<ItemType> itor(m_TempItemList);
	ItemType item = itor.Next();

	ItemType temp;
	temp.SetPurchaseDayFromKB();
	bool found = false;

	cout << "\t=====================Item PurchaseDay:" << temp.GetPurchaseDay() << "=====================\n";

	while (itor.NextNotNull()) {
		if (item.GetPurchaseDay() == temp.GetPurchaseDay()) {
			item.DisplayGoodsExceptStorageOnScreen();
			item = itor.Next();
			found = true;
		}
	}
	if (!found) {
		cout << "\t찾는 구매일의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}


