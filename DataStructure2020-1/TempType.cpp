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


// TempList�� item ������ return	
int TempType::GetNumOfItems() const
{
	return NumOfItems;
}

// TempList�� item�� Enqueue�Ѵ�
bool TempType::EnQueue(const ItemType& item)
{
	ItemType temp(item.GetId());
	if (!m_TempItemList.Retrieve(temp)) {
		m_TempItemList.EnQueue(item);
		return true;
	}
	cout << "\t�ߺ��� Id�� �����մϴ�\n";
	return false;
}

// TempList�� Dequeue�Ѵ�.
bool TempType::DeQueue(ItemType& item)
{
	if (m_TempItemList.DeQueue(item)) {
		NumOfItems--;
		return true;
	};
	return false;
}

// TempItemList�� ����.
void TempType::MakeEmpty()
{
	m_TempItemList.MakeEmpty();
	NumOfItems = 0;
}

// param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� ������
bool TempType::Retrieve(ItemType& item)
{
	if (m_TempItemList.Retrieve(item)) return true;
	return false;
}

// param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� �����ϰ� ������1
bool TempType::Delete(ItemType& item)
{
	if (m_TempItemList.Delete(item)) {
		NumOfItems--;
		return true;
	}
	return false;
}

// param�� Id�� ���� Id�� ���� item�� TempItemList���� ã�� ������ Replace�Ѵ�.
bool TempType::Replace(const ItemType& item)
{
	if (m_TempItemList.Replace(item)) return true;
	return false;
}

// TempItemList�� �ִ� ��� ���Ҹ� Display�Ѵ�.	
void TempType::DisplayAllTempItems()
{
	DoublyQueueIterator<ItemType> itor(m_TempItemList);
	ItemType item = itor.Next();
	
	while (itor.NextNotNull()) {
		item.DisplayGoodsExceptStorageOnScreen();
		item = itor.Next();
	}
}

// �Է¹��� Kind�� ���� �������� TempList���� ã�� ����Ѵ�.
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
		cout << "\tã�� ������ item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;
}

// �Է¹��� Name�� ���� �������� TempList���� ã�� ����Ѵ�.
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
		cout << "\tã�� �̸��� item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;
}

// �Է¹��� PurchaseDay�� ���� �������� TempList���� ã�� ����Ѵ�.
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
		cout << "\tã�� �������� item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;
}


