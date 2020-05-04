#include "pch.h"
#include "SimpleItemType.h"

// Constructor
SimpleItemType::SimpleItemType()
{
	m_Id = 0;
	m_Name = "";
	m_Kind = 0;
}

// Destructor
SimpleItemType::~SimpleItemType()
{
}

// m_Id을 가져온다
int SimpleItemType::GetId() const
{
	return m_Id;
}

// m_Name을 가져온다
string SimpleItemType::GetName() const
{
	return m_Name;
}

// m_Kind를 가져온다
int SimpleItemType::GetKind() const
{
	return m_Kind;
}

// m_Id를 Set한다
void SimpleItemType::SetId(int InId)
{
	m_Id = InId;
}

// m_Name을 set한다.
void SimpleItemType::SetName(string InName)
{
	m_Name = InName;
}

void SimpleItemType::SetKind(int InKind)
{
	m_Kind = InKind;
}

// item의 정보를 set한다.
void SimpleItemType::SetSimpleItem(int InId, string InName, int InKind)
{
	SetId(InId);
	SetName(InName);
	SetKind(InKind);
}

// m_Id를 키보드로부터 받아 set한다.
void SimpleItemType::SetIdFromKB()
{
	cout << "\t물품의 Id를 입력하시오 : ";
	cin >> m_Id;
}

// m_Name을 키보드로부터 받아 set한다.
void SimpleItemType::SetNameFromKB()
{
	cout << "\t물품의 이름을 입력하시오 : ";
	cin >> m_Name;
}

// m_Kind를 키보드로부터 받아 set한다.
void SimpleItemType::SetKindFromKB()
{
	cout << "\t물품의 종류을 입력하시오(책=1, 학용품=2, 화장품=3, 전자제품=4, 기타=0) : ";
	cin >> m_Kind;
	while (m_Kind < 0 || m_Kind > 4) {
		cout << "\t물품의 종류를 잘못 입력하였습니다. 다시 입력하시오(책=1, 학용품=2, 화장품=3, 전자제품=4, 기타=0) : ";
		cin >> m_Kind;
	}
}

// set SimpleItem from keyboard
void SimpleItemType::SetSimpleItemFromKB()
{
	SetKindFromKB();
	SetNameFromKB();
	SetIdFromKB();
}

// m_Name을 display한다.
void SimpleItemType::DisplayNameOnScreen() {
	cout << "\tName : " << m_Name << "\n";
}

// m_Kind을 display한다.
void SimpleItemType::DisplayKindOnScreen()
{
	cout << "\tKind : " << m_Kind << "\n";
}

// m_Id를 display한다.
void SimpleItemType::DisplayIdOnScreen() {
	cout << "\tId : " << m_Id << "\n";
}

// item의 정보를 display한다.
void SimpleItemType::DisplaySimpleItemOnScreen() {
	DisplayNameOnScreen();
	DisplayKindOnScreen();
	DisplayIdOnScreen();
	cout << "\n\n";
}
