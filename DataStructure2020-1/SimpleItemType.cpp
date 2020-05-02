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

// m_Id�� �����´�
int SimpleItemType::GetId() const
{
	return m_Id;
}

// m_Name�� �����´�
string SimpleItemType::GetName() const
{
	return m_Name;
}

// m_Kind�� �����´�
int SimpleItemType::GetKind() const
{
	return m_Kind;
}

// m_Id�� Set�Ѵ�
void SimpleItemType::SetId(int InId)
{
	m_Id = InId;
}

// m_Name�� set�Ѵ�.
void SimpleItemType::SetName(string InName)
{
	m_Name = InName;
}

void SimpleItemType::SetKind(int InKind)
{
	m_Kind = InKind;
}

// item�� ������ set�Ѵ�.
void SimpleItemType::SetSimpleItem(int InId, string InName, int InKind)
{
	SetId(InId);
	SetName(InName);
	SetKind(InKind);
}

// m_Id�� Ű����κ��� �޾� set�Ѵ�.
void SimpleItemType::SetIdFromKB()
{
	cout << "\t��ǰ�� Id�� �Է��Ͻÿ� : ";
	cin >> m_Id;
}

// m_Name�� Ű����κ��� �޾� set�Ѵ�.
void SimpleItemType::SetNameFromKB()
{
	cout << "\t��ǰ�� �̸��� �Է��Ͻÿ� : ";
	cin >> m_Id;
}

// m_Kind�� Ű����κ��� �޾� set�Ѵ�.
void SimpleItemType::SetKindFromKB()
{
	cout << "\t��ǰ�� ������ �Է��Ͻÿ�(å=1, �п�ǰ=2, ȭ��ǰ=3, ������ǰ=4, ��Ÿ=0) : ";
	cin >> m_Id;
}

// set SimpleItem from keyboard
void SimpleItemType::SetSimpleItemFromKB()
{
	SetKindFromKB();
	SetNameFromKB();
	SetIdFromKB();
}

// m_Name�� display�Ѵ�.
void SimpleItemType::DisplayNameOnScreen() {
	cout << "\tName : " << m_Name << "\n";
}

// m_Kind�� display�Ѵ�.
void SimpleItemType::DisplayKindOnScreen()
{
	cout << "\tKind : " << m_Kind << "\n";
}

// m_Id�� display�Ѵ�.
void SimpleItemType::DisplayIdOnScreen() {
	cout << "\tId : " << m_Id << "\n";
}

// item�� ������ display�Ѵ�.
void SimpleItemType::DisplaySimpleItemOnScreen() {
	DisplayNameOnScreen();
	DisplayKindOnScreen();
	DisplayIdOnScreen();
	cout << "\n\n";
}
