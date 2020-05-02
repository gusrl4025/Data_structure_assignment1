#include "pch.h"
#include "Application.h"

// run program(receive the command and execute the function)
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 물품 정보를 입력 받아 리스트에 추가					
			AddItem();
			break;
		case 2:		// 물품의 고유번호를 입력 받아 리스트에서 삭제					
			RunMaster();
			break;
		case 3:		// 물품 정보를 입력 받아서 리스트에서 해당 물품 정보를 갱신			
			RunStorage();
			break;
		case 4:		// 입력된 종류의 모든 물품을 화면에 출력
			RunTemp();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// run program(receive the command and execute the function)
void Application::RunMaster()
{
	while (1)
	{
		m_Command = GetCommandMaster();

		switch (m_Command)
		{
		case 1:		// Item을 입력받아 ContainerId가 있으면 MasterList -1이면 TempList에 넣는다.					
			AddItem();
			break;
		case 2:		// receive keynumber from keyboard and find item in Masterlist which same keynumber and delete that item
			DeleteItemMasterList();
			break;
		case 3:		// receive Goods record from keyboard and find item has same keynumber and replace the record with new record	
			ReplaceItemMasterList();
			break;
		case 4:		// receive ID from keyboard and find item which has same ID and display that record on screen
			RetrieveItemMasterList();
			break;
		case 5:		// receive word from keyboard and display the kind of item Kind display that record on screen
			SearchByKindMasterList();
			break;
		case 6:		// receive Name from keyboard and find item which Name include the Name and display that record on screen				
			SearchByNameMasterList();
			break;
		case 7:		// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
			SearchByPurchaseDayMasterList();
			break;
		case 8:
			SearchByPurchasePeriod();
			break;
		case 9:		// make MasterList empty
			MakeEmptyMasterList();
			break;
		case 10: 	// display all records in list on screen
			DisplayAllItemMasterList();
			break;
		case 11:	// move item in MasterList to TempList
			MoveItemMasterToTemp();
			break;
		case 0:
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// run program(receive the command and execute the function)
int Application::RunStorage() {
	while (1)
	{
		m_Command = GetCommandStorage();

		switch (m_Command)
		{
		case 1:
			RunContainer(GetStorageId());
			break;
		case 2:
			DisplayAllContainer();
			break;
		case 3:
			//DisPlayAllDetailsContainer();
		case 0:
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// run program(receive the command and execute the function)
void Application::RunContainer(int InStorageId)
{
	StorageType storage;
	storage.SetId(InStorageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		while (1)
		{
			m_Command = GetCommandContainer(InStorageId);

			switch (m_Command)
			{
			case 1:		// 물품 정보를 입력 받아 리스트에 추가					
				AddItem();
				break;
			case 2:		// 물품의 고유번호를 입력 받아 리스트에서 삭제					
				PrintContainerList(storage);
				break;
			case 3:		// 물품 정보를 입력 받아서 리스트에서 해당 물품 정보를 갱신			
				AddPhoto(storage);
				break;
			case 4:		// 입력된 종류의 모든 물품을 화면에 출력
				DeletePhoto(storage);
				break;
			case 5:		// 물품명에 입력된 단어가 포함된 모든 물품을 화면에 출력
				UpdatePhoto(storage);
				break;
			case 6:		// 입력된 정보로 리스트에서 물품을 찾아서 화면에 출력				
				PrintPhotoList(storage);
				break;
			case 7:		// 리스트에 저장된 모든 물품을 화면에 출력
				RetrieveItemContainerList(storage);
				break;
			case 8: 	// 리스트에 입력된 모든 물품을 삭제
				SearchByKindContainerList(storage);
				break;
			case 9:		// load list data from a file.
				SearchByNameContainerList(storage);
				break;
			case 10:	// save list data into a file.
				MakeEmptyContainer(storage);
				break;
			case 11:	// save list data into a file.
				DisplayAllItemContainer(storage);
				break;
			case 12:

			case 0:
				Run();
				break;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}
	else {
		cout << "\t찾으려는 저장소가 존재하지 않습니다.\n";
		RunStorage();
	}
}

// run program(receive the command and execute the function)
void Application::RunTemp()
{
	while (1)
	{
		m_Command = GetCommandTemp();

		switch (m_Command)
		{
		case 1:		// 물품 정보를 입력 받아 리스트에 추가					
			AddItem();
			break;
		case 2:		// receive keynumber from keyboard and find item in TempList which same keynumber and delete that item					
			DeleteItemTempList();
			break;
		case 3:		// receive Goods record from keyboard and find item has same keynumber and replace the record with new record		
			ReplaceItemTempList();
			break;
		case 4:		// receive ID from keyboard and find item which has same ID and display that record on screen
			RetrieveItemTempList();
			break;
		case 5:		// receive word from keyboard and display the kind of item Kind display that record on screen
			SearchByKindTempList();
			break;
		case 6:		// receive Name from keyboard and find item which Name include the Name and display that record on screen			
			SearchByNameTempList();
			break;
		case 7:		// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
			SearchByPurchaseDayTempList();
			break;
		case 8: 	// make TempList empty
			MakeEmptyTempList();
			break;
		case 9:		// display all records in list on screen
			DisplayAllItemTempList();
			break;
		case 10:	// move item in TempList to MasterList
			MoveItemTempToMaster();
			break;
		case 0:
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// shows menu and receive the command from keyboard
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t===================================================\n";
	cout << "\t|집안물품 정리 프로그램에 접속하신 것을 환영합니다|\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Add Item\n";
	cout << "\t 2 : MasterList에 접근하기\n";
	cout << "\t 3 : StorageList에 접근하기\n";
	cout << "\t 4 : TempList에 접근하기\n";
	cout << "\t 0 : 프로그램 종료" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandMaster()
{
	int command;
	cout << endl << endl;
	cout << "\tMasterList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Item 제거하기\n";
	cout << "\t 3 : Item 업데이트\n";
	cout << "\t 4 : Item 검색하기\n";
	cout << "\t 5 : 종류로 Item 검색하기\n";
	cout << "\t 6 : 이름으로 Item 검색하기\n";
	cout << "\t 7 : 구매일로 Item 검색하기\n";
	cout << "\t 8 : 일정기간 안에 구매한 Item 검색하기\n";
	cout << "\t 9 : MasterList 비우기\n";
	cout << "\t 10 : 모든 Item 출력하기\n";
	cout << "\t 11 : TempList로 Item 옮기기 \n";
	cout << "\t 0 : 목록으로 돌아가기\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandStorage()
{
	int command;
	cout << "\n\n";
	cout << "\tStorageList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : 접근할 Storage 입력\n";
	cout << "\t 2 : Storage 하나의 컨테이너들의 정보 출력\n";
	cout << "\t 3 : Storage 하나의 컨테이너들의 상세 정보 출력\n";
	cout << "\t 0 : 목록으로 돌아가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandContainer(int InStorageId)
{
	int command;
	cout << endl << endl;
	cout << "\t=====================Storage ID : " << InStorageId << "=====================\n";
	cout << "\tContainerList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Container 목록 출력하기\n";
	cout << "\t 3 : 사진 저장하기\n";
	cout << "\t 4 : 사진 제거하기\n";
	cout << "\t 5 : 사진 업데이트하기\n";
	cout << "\t 6 : 사진 목록 출력\n";
	cout << "\t 7 : Item 검색하기\n";
	cout << "\t 8 : 종류로 Item 검색하기\n";
	cout << "\t 9 : 이름으로 Item 검색하기\n";
	cout << "\t 10 : Container 하나 비우기\n";
	cout << "\t 11 : Container 하나의 모든 Item 출력하기\n";
	cout << "\t 0 : 목록으로 돌아가기\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandTemp()
{
	int command;
	cout << endl << endl;
	cout << "\tTempList에서 실행할 command를 입력하세요\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item 추가하기\n";
	cout << "\t 2 : Item 제거하기 \n";
	cout << "\t 3 : Item 업데이트하기\n";
	cout << "\t 4 :	Item 검색하기\n";
	cout << "\t 5 : 종류로 Item 검색하기\n";
	cout << "\t 6 : 이름으로 Item 검색하기\n";
	cout << "\t 7 : 구매일로 Item 검색하기\n";
	cout << "\t 8 : TempList 비우기\n";
	cout << "\t 9 : 모든 Item 출력하기\n";
	cout << "\t 10 : MasterList로 Item 옮기기 \n";
	cout << "\t 0 : 목록으로 돌아가기\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// receive Goods record from keyboard and add to list
bool Application::AddItem() {
	cout << "\t=====================Add item=====================\n";
	ItemType item;
	item.SetGoodsFromKB(); // item을 입력받는다
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		if (m_TempList.EnQueue(item)) {
			cout << "\n\t Item저장에 성공했습니다\n";
			DisplayAllItemTempList();
			return true;
		}
		cout << "\n\tItem저장에 실패했습니다\n";
		return false;
	}
	else { // StorageId, ContainerList가 -1이 아니면
		StorageType storage; // StorageId를 가진 storage를 하나 생성
		storage.SetId(item.GetStorageId());
		if (m_MasterList.Add(item)) {
			if (m_StorageList.Retrieve_Binary(storage)) { // StorageId와 같은 storage가 존재하면
				ContainerType container;
				container.SetId(item.GetContainerId());
				if (storage.GetContainer(container)) { // containerId와 같은 container가 존재하면
					if (container.AddItem(item)) {
						storage.UpdateContainer(container);
						m_StorageList.Replace(storage);
						cout << "\n\t Item저장에 성공했습니다.\n";
						cout << "\n\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
						return true;
					}
				}
				else { // storageId와 같은 storage는 있는데 그 안의 containerId와 같은 container가 없을 시
					if (!storage.IsFull()) { // storage가 꽉 차지 않았을 때
						cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " 생성=====================\n";
						container.SetLocationFromKB();
						container.AddItem(item);
						if (storage.AddContainer(container)) {
							if (m_StorageList.Replace(storage)) {
								cout << "\n\t Item저장에 성공했습니다.\n";
								cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
								container.DisplayAllItem();
								return true;
							}
							else {
								cout << "\n\tItem저장에 실패했습니다\n";
								return false;
							}
						}
					}
					else { // storage가 꽉 찼을 떄
						cout << "\n\tStorage:" << storage.GetId() << " 에 더이상 Container를 생성할 수 없습니다\n";
						m_MasterList.Delete(item);
						return false;
					}
				}
			}
			else { // StorageId와 같은 storage가 존재하지 않을 때(container도 당연히 없다)
				int InMaxNum;
				cout << "\n\t=====================Storage:" << storage.GetId() << " 생성=====================\n";
				ContainerType container;
				cout << "\t해당하는 storage가 없어 새로 만듭니다.\n";
				cout << "\t최대 보관가능한 컨테이터의 개수를 입력하시오 : ";
				cin >> InMaxNum;
				storage.SetMaxNum(InMaxNum);
				cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << item.GetContainerId() << " 생성=====================\n";
				container.SetId(item.GetContainerId());
				container.SetLocationFromKB();
				container.AddItem(item);
				if (storage.AddContainer(container)) {
					if (m_StorageList.Add(storage)) {
						cout << "\n\t Item저장에 성공했습니다.\n";
						cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
					}
				}
			}
		}
		return false;
	}
	return false; 
}

// Item을 입력받아 ContainerId가 있으면 MasterList -1이면 TempList에 넣는다.
bool Application::AddItem(ItemType item) {
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1이면 TemptList에 저장
		if (m_TempList.EnQueue(item)) {
			cout << "\n\t Item저장에 성공했습니다\n";
			DisplayAllItemTempList();
			return true;
		}
		cout << "\n\tItem저장에 실패했습니다\n";
		return false;
	}
	else { // StorageId, ContainerList가 -1이 아니면
		StorageType storage; // StorageId를 가진 storage를 하나 생성
		storage.SetId(item.GetStorageId());
		if (m_MasterList.Add(item)) {
			if (m_StorageList.Retrieve_Binary(storage)) { // StorageId와 같은 storage가 존재하면
				ContainerType container;
				container.SetId(item.GetContainerId());
				if (storage.GetContainer(container)) { // containerId와 같은 container가 존재하면
					if (container.AddItem(item)) {
						storage.UpdateContainer(container);
						m_StorageList.Replace(storage);
						cout << "\n\t Item저장에 성공했습니다.\n";
						cout << "\n\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
						return true;
					}
				}
				else { // containerId와 같은 container가 없을 시
					cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " 생성=====================\n";
					container.SetLocationFromKB();
					container.AddItem(item);
					if (storage.AddContainer(container)) {
						if (m_StorageList.Replace(storage)) {
							cout << "\n\t Item저장에 성공했습니다.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
						else {
							cout << "\n\tItem저장에 실패했습니다\n";
							return false;
						}
					}
				}
			}
			else { // StorageId와 같은 storage가 존재하지 않을 때(container도 당연히 없다)
				int InMaxNum;
				cout << "\n\t=====================Storage:" << storage.GetId() << " 생성=====================\n";
				ContainerType container;
				cout << "\t해당하는 storage가 없어 새로 만듭니다.\n";
				cout << "\t최대 보관가능한 컨테이터의 개수를 입력하시오 : ";
				cin >> InMaxNum;
				storage.SetMaxNum(InMaxNum);
				cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << item.GetContainerId() << " 생성=====================\n";
				container.SetId(item.GetContainerId());
				container.SetLocationFromKB();
				container.AddItem(item);
				if (storage.AddContainer(container)) {
					if (m_StorageList.Add(storage)) {
						cout << "\n\t Item저장에 성공했습니다.\n";
						cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
						container.DisplayAllItem();
					}
				}
			}
		}
		return false;
	}
	return false;
}

// Id를 입력받아 MasterList와 Container에서 지워준다
bool Application::DeleteItemMasterList() {
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve(item)) {
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		if (container.DeleteItem(item)) {
			m_MasterList.Delete(item);
			cout << "\t=====================삭제 후 Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem 삭제에 실패했습니다\n";
	return false;

}

// Item을 입력받아 MasterList와 Container에서 수정한다
bool Application::ReplaceItemMasterList()
{
	ItemType item;
	ItemType temp;
	item.SetGoodsExceptStorageFromKB();
	temp.SetId(item.GetId());
	if (m_MasterList.Retrieve(temp)) {
		item.SetContainerId(temp.GetContainerId());
		item.SetStorageId(temp.GetStorageId());
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		if (container.UpdateItem(item)) {
			m_MasterList.Replace(item);
			cout << "\t=====================수정 후 Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem 수정에 실패했습니다\n";
	return false;
}

// Id을 입력받아 MasterList에서 검색한다
bool Application::RetrieveItemMasterList()
{
	ItemType item;
	item.SetIdFromKB();
	cout << "\n\t=====================Item ID:" << item.GetId() << "=====================\n";
	if (m_MasterList.Retrieve(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	cout << "\t찾는 item이 존재하지 않습니다.\n";
	return false;
}

// item 종류를 입력받아 MasterList에서 검색한다
bool Application::SearchByKindMasterList()
{
	DoublyIterator<ItemType> itor(m_MasterList);

	ItemType item;
	ItemType temp;
	bool found = false;
	item.SetKindFromKB();

	cout << "\n\t=====================Item Kind:" << item.GetKind() << "=====================\n";
	while (itor.NextNotNull()) {
		temp = itor.Next();
		if (temp.GetKind() == item.GetKind()) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
		
	}
	if (!found) {
		cout << "\t찾는 종류의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;

}

// item 이름을 입력받아 MasterList에서 검색한다
bool Application::SearchByNameMasterList()
{
	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType item;
	ItemType temp = itor.Next();
	bool found = false;
	item.SetNameFromKB();

	cout << "\n\t=====================Item Name:" << item.GetName() << "=====================\n";
	while (itor.NextNotNull()) {
		if (temp.GetName() == item.GetName()) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
		temp = itor.Next();
	}
	if (!found) {
		cout << "\t찾는 이름의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// item의 구매일을 입력받아 MasterList에서 검색한다
bool Application::SearchByPurchaseDayMasterList()
{
	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType item;
	ItemType temp = itor.Next();
	bool found = false;
	item.SetPurchaseDayFromKB();


	cout << "\n\t=====================Item PurchaseDay:" << item.GetPurchaseDay() << "=====================\n";
	while (itor.NextNotNull()) {
		if (temp.GetPurchaseDay() == item.GetPurchaseDay()) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
		temp = itor.Next();
	}
	if (!found) {
		cout << "\t찾는 구매일의 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// item의 구매일을 구간으로 입력받아 MasterList에서 검색한다
bool Application::SearchByPurchasePeriod()
{
	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType temp = itor.Next();
	bool found = false;
	int StartDay, EndDay;
	cout << "\n\t찾으려는 구간의 시작일을 입력하시오(예: 19970602 (1997년6월2일)) :";
	cin >> StartDay;
	cout << "\t찾으려는 구간의 종료일을 입력하시오(예: 19970602 (1997년6월2일)) :";
	cin >> EndDay;
	if (StartDay > EndDay) {
		cout << "\t구간을 잘못 설정했습니다\n";
		return false;
	}

	cout << "\n\t=====================Item PurchaseDay:" << StartDay << "~" << EndDay << "=====================\n";
	while (itor.NextNotNull()) {
		if (temp.GetPurchaseDay() >= StartDay && temp.GetPurchaseDay() <= EndDay) {
			temp.DisplayGoodsOnScreen();
			found = true;
		}
		temp = itor.Next();
	}
	if (!found) {
		cout << "\t찾는 구간에 구매한 item이 존재하지 않습니다.\n";
		return false;
	}
	return true;
}

// make MasterList, StorageList empty
void Application::MakeEmptyMasterList()
{
	m_MasterList.MakeEmpty();
	StorageType storage;
	m_StorageList.ResetList();
	for (int CurPos = 0; CurPos < m_StorageList.GetLength(); CurPos++) {
		m_StorageList.GetNextItem(storage);
		ContainerType container;
		storage.ResetList();
		for (int i = 0; i < storage.GetCurrentNum(); i++) {
			storage.GetNextContainer(container);
			container.MakeEmpty();
			storage.UpdateContainer(container);
		}
		m_StorageList.Replace(storage);
	}
}

// display all records in MasterList on screen
void Application::DisplayAllItemMasterList()
{
	ItemType item;
	DoublyIterator<ItemType> itor(m_MasterList);
	item = itor.Next();

	cout << "\t=====================MastserList=====================\n";
	while (itor.NextNotNull()) {
		item.DisplayGoodsOnScreen();
		item = itor.Next(); 
	}
}

// move item in MasterList to TempList
bool Application::MoveItemMasterToTemp()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_MasterList.Retrieve(item)) {
		StorageType storage;
		storage.SetId(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container;
		container.SetId(item.GetContainerId());
		storage.GetContainer(container);
		
		if (!m_TempList.IsFull()) {
			if (container.DeleteItem(item)) {
				item.SetContainerId(-1);
				m_TempList.EnQueue(item);
				m_MasterList.Delete(item);
				cout << "\t성공적으로 이동했습니다\n";
				return true;
			}
		}
		else {
			cout << "\t임시저장소가 가득 찼습니다\n";
			return false;
		}
	}

	cout << "\t이동시키려는 Item이 존재하지 않습니다\n";
	return false;
}

// RunContainer에 쓸 StorageId를 입력받음	
int Application::GetStorageId()
{
	int InStorageId;
	cout << "\t접근하고자 하는 저장소의 ID를 입력하시오 : ";
	cin >> InStorageId;
	return InStorageId;
}

// StorageId를 입력받아 그 안에 있는 container의 정보와 리스트를 출력함
void Application::DisplayAllContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t저장소의 ID를 입력하시오 : ";
	cin >> storageId;
	storage.SetId(storageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container 정보=====================\n";
		storage.DisplayAllContainer();
		cout << "\t-----------------------------------------------\n";
	}
	else {
		cout << "\t찾으려는 ID의 저장소가 없습니다.\n";
	}
}

// StorageId를 입력받아 그 안에 있는 container의 상세 정보와 리스트를 MasterList를 참조해 출력함
//void Application::DisPlayAllDetailsContainer()
//{
//	StorageType storage;
//	int storageId;
//	cout << "\t저장소의 ID를 입력하시오 : ";
//	cin >> storageId;
//	storage.SetId(storageId);
//	if (m_StorageList.Retrieve_Binary(storage)) {
//		cout << "\t=====================Storage:" << storage.GetId() << " Container 정보=====================\n";
//		storage.DisplayAllDetailsContainer(m_MasterList);
//		cout << "\t-----------------------------------------------\n";
//	}
//	else {
//		cout << "\t찾으려는 ID의 저장소가 없습니다.\n";
//	}
//}

// 저장소의 Container 목록을 출력한다
void Application::PrintContainerList(StorageType& storage)
{
	cout << "\t=====================Storage:" << storage.GetId() << " Container 정보=====================\n";
	storage.DisplayAllContainer();
}

// 저장소의 Container에 photo를 추가한다.
bool Application::AddPhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t추가할 Photo를 입력하시오 : ";
		cin >> photo;
		if (container.AddPhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto를 성공적으로 추가했습니다.\n";
			cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto저장에 실패했습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 입력받은 photo를 제거한다.
bool Application::DeletePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		cout << "\n\t제거할 Photo를 입력하시오 : ";
		cin >> photo;
		if (container.DeletePhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto를 성공적으로 제거했습니다.\n";
			cout << "\t=====================삭제 후 Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto삭제에 실패했습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 입력받은 photo를 수정한다.
bool Application::UpdatePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		cout << "\n\t수정할 Photo를 입력하시오 : \n";
		cin >> photo;
		if (container.UpdatePhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto를 성공적으로 수정했습니다.\n";
			cout << "\t=====================수정 후 Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto수정에 실패했습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container의 photolist를 출력한다
bool Application::PrintPhotoList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		return true;
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 item을 검색한다.
bool Application::RetrieveItemContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		item.SetIdFromKB();
		if (container.GetItem(item)) {
			item.DisplaySimpleItemOnScreen();
			return true;
		}
		else {
			cout << "\t찾으려는 item이 존재하지 않습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 item을 kind로 검색한다.
bool Application::SearchByKindContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	cout << "\n";
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		if (container.FindByKind(item)) {
			return true;
		}
		else {
			cout << "\t해당하는 종류의 물품이 없습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container에서 item을 Name으로 검색한다.
bool Application::SearchByNameContainerList(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		SimpleItemType item;
		if (container.FindByName(item)) {
			return true;
		}
		else {
			cout << "\t해당하는 이름의 물품이 없습니다\n";
			return false;
		}
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
		return false;
	}
}

// 저장소의 Container를 비운다.
void Application::MakeEmptyContainer(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		container.ResetSimpleList();
		SimpleItemType simpleitem;
		while (container.GetNextSimpleItem(simpleitem)) {
			ItemType item;
			item.SetId(simpleitem.GetId());
			m_MasterList.Delete(item);
		}
		container.MakeEmpty();
		cout << "\n\tContainer:" << container.GetId() << " 가 성공적으로 비워졌습니다\n\n";
	}
	else {
		cout << "\t찾으려는 container가 존재하지 않습니다\n";
	}
}

// 저장소의 container에 있는 모든 item을 출력한다.
void Application::DisplayAllItemContainer(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		container.DisplayAllItem();
	}
	else {
		cout << "\t찾으려는 containe가 존재하지 않습니다\n";
	}
}

// receive keynumber from keyboard and find item in TempList which same keynumber and delete that item
bool Application::DeleteItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_TempList.Delete(item)) {
		cout << "\t성공적으로 삭제했습니다\n\n";
		cout << "\t=====================삭제 후 TempList=====================\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\t찾고있는 item이 존재하지 않습니다\n";
		return false;
	}
}

// receive Goods record from keyboard and find item has same keynumber and replace the record with new record
bool Application::ReplaceItemTempList()
{
	ItemType item;
	item.SetKindFromKB();
	item.SetPurchaseDayFromKB();
	item.SetNameFromKB();
	item.SetPriceFromKB();
	item.SetIdFromKB();
	item.SetStorageId(-1);
	item.SetContainerId(-1);

	if (m_TempList.Replace(item)) {
		cout << "\n\t성공적으로 item을 수정했습니다.\n";
		return true;
	}
	else {
		cout << "\t찾으려는 item이 존재하지 않습니다.\n";
		return false;
	}
}

// receive ID from keyboard and find item which has same ID and display that record on screen
bool Application::RetrieveItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	cout << "\n\t=====================Item ID:" << item.GetId() << "=====================\n";
	if (m_TempList.Retrieve(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	else {
		cout << "\t찾으려는 item이 존재하지 않습니다\n";
		return false;
	}
}

// receive word from keyboard and display the kind of item Kind display that record on screen
bool Application::SearchByKindTempList()
{
	cout << "\t=====================Item=====================\n";
	return m_TempList.SearchByKind();
}

// receive Name from keyboard and find item which Name include the Name and display that record on screen
bool Application::SearchByNameTempList()
{
	cout << "\t=====================Item=====================\n";
	return m_TempList.SearchByName();
}

// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
bool Application::SearchByPurchaseDayTempList()
{
	cout << "\t=====================Item=====================\n";
	return m_TempList.SearchByPurchaseDay();
}

// make TempList empty
void Application::MakeEmptyTempList()
{
	m_TempList.MakeEmpty();
}

// display all records in list on screen
void Application::DisplayAllItemTempList()
{
	cout << "\t=====================TempList=====================\n";
	m_TempList.DisplayAllTempItems();
}

// move all items in TempList to MasterList
void Application::MoveItemTempToMaster()
{
	ItemType item;
	cout << "\t=====================TempList=====================\n";
	int length = m_TempList.GetNumOfItems();
	for (int i = 0; i < length; i++) {
		m_TempList.DeQueue(item);
		item.DisplayGoodsOnScreen();
		int ContainerId, StorageId;
		cout << "\t옮기고 싶은 StorageId를 입력하시오 : ";
		cin >> StorageId;
		cout << "\t옮기고 싶은 ContainerId를 입력하시오 : ";
		cin >> ContainerId;

		if (StorageId == -1 || ContainerId == -1) {
			cout << "\t임시저장소는 입력하면 안됩니다. 다시 임시저장소에 보관합니다.\n";
			m_TempList.EnQueue(item);
		}
		else {
			item.SetStorageId(StorageId);
			item.SetContainerId(ContainerId);
			if (AddItem(item)) {
				cout << "\t성공적으로 저장소를 옮겼습니다\n";
			}
			else {
				cout << "\t저장소를 옮기는데 실패했습니다. 다시 임시저장소에 보관합니다.\n";
				m_TempList.EnQueue(item);
			}
		}
	}
}
