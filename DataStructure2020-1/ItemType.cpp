#include "pch.h"
#include "ItemType.h"

// set Kind of Goods from keyboard
void ItemType::SetKindFromKB() {
	cout << "\t물품의 종류을 입력하시오(책=1, 학용품=2, 화장품=3, 전자제품=4, 기타=0) : ";
	cin >> m_Kind;
	while (m_Kind < 0 || m_Kind > 4) {
		cout << "\t물품의 종류를 잘못 입력하였습니다. 다시 입력하시오(책=1, 학용품=2, 화장품=3, 전자제품=4, 기타=0) : ";
		cin >> m_Kind;
	}
}

// set PurchaseDay of Goods from keyboard
void ItemType::SetPurchaseDayFromKB() {
	cout << "\t물품의 구매일를 입력하시오(예: 19970602 (1997년6월2일)) : ";
	cin >> m_PurchaseDay;
	while (m_PurchaseDay < 19000000 || m_PurchaseDay > 21000000 || (m_PurchaseDay / 100) % 100 == 0 || (m_PurchaseDay / 100) % 100 > 12) {
		cout << "\t물품의 구매일를 잘못 입력하였습니다. 다시 입력하시오(예: 19970602 (1997년6월2일)) : ";
		cin >> m_PurchaseDay;
	}
}

// set Name of Goods from keyboard
void ItemType::SetNameFromKB() {
	cout << "\t물품의 이름을 입력하시오 : ";
	cin >> m_Name;
}

// set Price of Goods from keyboard
void ItemType::SetPriceFromKB() {
	cout << "\t물품의 가격을 입력하시오 : ";
	cin >> m_Price;
}

// set Id of Goods from keyboard
void ItemType::SetIdFromKB() {
	cout << "\t물품의 고유번호를 입력하시오 : ";
	cin >> m_Id;
}

// set ContainerId of Goods from keyboard
void ItemType::SetContainerIdFromKB() {
	cout << "\t물품을 저장할 박스의 번호를 입력하시오(어디에 저장할지 모를 때 -1로 입력하시오) : ";
	cin >> m_ContainerId;
}

// set StorageId of Goods from keyboard
void ItemType::SetStorageIdFromKB() {
	cout << "\t물품을 저장할 저장소의 번호를 입력하시오(어디에 저장할지 모를 때 -1로 입력하시오) : ";
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

void ItemType::DisplayGoodsExceptStorageOnScreen()
{
	DisplayKindOnScreen();
	DisplayPurchaseDayOnScreen();
	DisplayNameOnScreen();
	DisplayPriceOnScreen();
	DisplayIdOnScreen();
	cout << "\n\n";
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
