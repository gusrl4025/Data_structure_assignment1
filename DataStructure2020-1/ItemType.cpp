#include "pch.h"
#include "ItemType.h"

// set Kind of Goods from keyboard
void ItemType::SetKindFromKB() {
	cout << "\t��ǰ�� ������ �Է��Ͻÿ�(å=1, �п�ǰ=2, ȭ��ǰ=3, ������ǰ=4, ��Ÿ=0) : ";
	cin >> m_Kind;
}

// set PurchaseDay of Goods from keyboard
void ItemType::SetPurchaseDayFromKB() {
	cout << "\t��ǰ�� �����ϸ� �Է��Ͻÿ�(��: 19970602 (1997��6��2��)) : ";
	cin >> m_PurchaseDay;
}

// set Name of Goods from keyboard
void ItemType::SetNameFromKB() {
	cout << "\t��ǰ�� �̸��� �Է��Ͻÿ� : ";
	cin >> m_Name;
}

// set Price of Goods from keyboard
void ItemType::SetPriceFromKB() {
	cout << "\t��ǰ�� ������ �Է��Ͻÿ� : ";
	cin >> m_Price;
}

// set Id of Goods from keyboard
void ItemType::SetIdFromKB() {
	cout << "\t��ǰ�� ������ȣ�� �Է��Ͻÿ� : ";
	cin >> m_Id;
}

// set ContainerId of Goods from keyboard
void ItemType::SetContainerIdFromKB() {
	cout << "\t��ǰ�� ������ �ڽ��� ��ȣ�� �Է��Ͻÿ�(��� �������� �� �� -1�� �Է��Ͻÿ�) : ";
	cin >> m_ContainerId;
}

// set StorageId of Goods from keyboard
void ItemType::SetStorageIdFromKB() {
	cout << "\t��ǰ�� ������ ������� ��ȣ�� �Է��Ͻÿ�(��� �������� �� �� -1�� �Է��Ͻÿ�) : ";
	cin >> m_StorageId;
}

// set Goods record except storage from keyboard
void ItemType::SetGoodsExceptStorageFromKB() {
	SetKindFromKB();
	SetPurchaseDayFromKB();
	SetNameFromKB();
	SetPriceFromKB();
	SetIdFromKB();
}

// set Goods record from keyboard
void ItemType::SetGoodsFromKB() {
	SetKindFromKB();
	SetPurchaseDayFromKB();
	SetNameFromKB();
	SetPriceFromKB();
	SetIdFromKB();
	SetContainerIdFromKB();
	SetStorageIdFromKB();
}

// display Kind of Goods on screen
void ItemType::DisplayKindOnScreen() {
	cout << "\tKind : " << m_Kind << "\n";
}

// display PurchaseDay of Goods on screen
void ItemType::DisplayPurchaseDayOnScreen() {
	cout << "\tPurchaseDay : " << m_PurchaseDay << "\n";
}

// display Name of Goods on screen
void ItemType::DisplayNameOnScreen() {
	cout << "\tName : " << m_Name << "\n";
}

// display Price of Goods on screen
void ItemType::DisplayPriceOnScreen() {
	cout << "\tPrice : " << m_Price << "\n";
}

// display Id of Goods on screen
void ItemType::DisplayIdOnScreen() {
	cout << "\tId : " << m_Id << "\n";
}

// display ContainerId of Goods on screen
void ItemType::DisplayContainerIdOnScreen() {
	cout << "\tContainerId : " << m_ContainerId << "\n";
}

// display StorageId of Goods on screen
void ItemType::DisplayStorageIdOnScreen()
{
	cout << "\tStorageId : " << m_StorageId << "\n";
}

// display Goods record on screeen
void ItemType::DisplayGoodsOnScreen() {
	DisplayKindOnScreen();
	DisplayPurchaseDayOnScreen();
	DisplayNameOnScreen();
	DisplayPriceOnScreen();
	DisplayIdOnScreen();
	DisplayContainerIdOnScreen();
	DisplayStorageIdOnScreen();
	cout << "\n\n";
}
