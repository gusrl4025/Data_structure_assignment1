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
		case 1:		// ��ǰ ������ �Է� �޾� ����Ʈ�� �߰�					
			AddItem();
			break;
		case 2:		// ��ǰ�� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
			RunMaster();
			break;
		case 3:		// ��ǰ ������ �Է� �޾Ƽ� ����Ʈ���� �ش� ��ǰ ������ ����			
			RunStorage();
			break;
		case 4:		// �Էµ� ������ ��� ��ǰ�� ȭ�鿡 ���
			RunTemp();
			break;
		case 5:
			RunAccountBook();
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
		case 1:		// Item�� �Է¹޾� ContainerId�� ������ MasterList -1�̸� TempList�� �ִ´�.					
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
			SearchByPurchasePeriodMasterList();
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
			DisPlayAllDetailsContainer();
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
			case 1:		// ��ǰ ������ �Է� �޾� ����Ʈ�� �߰�					
				AddItem();
				break;
			case 2:		// ��ǰ�� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
				PrintContainerList(storage);
				break;
			case 3:		// ��ǰ ������ �Է� �޾Ƽ� ����Ʈ���� �ش� ��ǰ ������ ����			
				AddPhoto(storage);
				break;
			case 4:		// �Էµ� ������ ��� ��ǰ�� ȭ�鿡 ���
				DeletePhoto(storage);
				break;
			case 5:		// ��ǰ�� �Էµ� �ܾ ���Ե� ��� ��ǰ�� ȭ�鿡 ���
				UpdatePhoto(storage);
				break;
			case 6:		// �Էµ� ������ ����Ʈ���� ��ǰ�� ã�Ƽ� ȭ�鿡 ���				
				PrintPhotoList(storage);
				break;
			case 7:		// ����Ʈ�� ����� ��� ��ǰ�� ȭ�鿡 ���
				RetrieveItemContainerList(storage);
				break;
			case 8: 	// ����Ʈ�� �Էµ� ��� ��ǰ�� ����
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
		cout << "\tã������ ����Ұ� �������� �ʽ��ϴ�.\n";
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
		case 1:		// ��ǰ ������ �Է� �޾� ����Ʈ�� �߰�					
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

// run program(receive the command and execute the function)
void Application::RunAccountBook()
{
	while (1)
	{
		m_Command = GetCommandAccountBook();

		switch (m_Command)
		{
		case 1:
			DisplayDayExpenseRecord();
			break;
		case 2:		
			DisplayMonthExpenseRecord();
			break;
		case 3:		
			DisplayYearExpenseRecord();
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
	cout << "\t|���ȹ�ǰ ���� ���α׷��� �����Ͻ� ���� ȯ���մϴ�|\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Add Item\n";
	cout << "\t 2 : MasterList�� �����ϱ�\n";
	cout << "\t 3 : StorageList�� �����ϱ�\n";
	cout << "\t 4 : TempList�� �����ϱ�\n";
	cout << "\t 5 : AccountBook�� �����ϱ�\n";
	cout << "\t 0 : ���α׷� ����" << endl;
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
	cout << "\tMasterList���� ������ command�� �Է��ϼ���\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item �߰��ϱ�\n";
	cout << "\t 2 : Item �����ϱ�\n";
	cout << "\t 3 : Item ������Ʈ\n";
	cout << "\t 4 : Item �˻��ϱ�\n";
	cout << "\t 5 : ������ Item �˻��ϱ�\n";
	cout << "\t 6 : �̸����� Item �˻��ϱ�\n";
	cout << "\t 7 : �����Ϸ� Item �˻��ϱ�\n";
	cout << "\t 8 : �����Ⱓ �ȿ� ������ Item �˻��ϱ�\n";
	cout << "\t 9 : MasterList ����\n";
	cout << "\t 10 : ��� Item ����ϱ�\n";
	cout << "\t 11 : TempList�� Item �ű�� \n";
	cout << "\t 0 : ������� ���ư���\n" << endl;
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
	cout << "\tStorageList���� ������ command�� �Է��ϼ���\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : ������ Storage �Է�\n";
	cout << "\t 2 : Storage �ϳ��� �����̳ʵ��� ���� ���\n";
	cout << "\t 3 : Storage �ϳ��� �����̳ʵ��� �� ���� ���\n";
	cout << "\t 0 : ������� ���ư���\n";
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
	cout << "\tContainerList���� ������ command�� �Է��ϼ���\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item �߰��ϱ�\n";
	cout << "\t 2 : Container ��� ����ϱ�\n";
	cout << "\t 3 : ���� �����ϱ�\n";
	cout << "\t 4 : ���� �����ϱ�\n";
	cout << "\t 5 : ���� ������Ʈ�ϱ�\n";
	cout << "\t 6 : ���� ��� ���\n";
	cout << "\t 7 : Item �˻��ϱ�\n";
	cout << "\t 8 : ������ Item �˻��ϱ�\n";
	cout << "\t 9 : �̸����� Item �˻��ϱ�\n";
	cout << "\t 10 : Container �ϳ� ����\n";
	cout << "\t 11 : Container �ϳ��� ��� Item ����ϱ�\n";
	cout << "\t 0 : ������� ���ư���\n";
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
	cout << "\tTempList���� ������ command�� �Է��ϼ���\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : Item �߰��ϱ�\n";
	cout << "\t 2 : Item �����ϱ� \n";
	cout << "\t 3 : Item ������Ʈ�ϱ�\n";
	cout << "\t 4 :	Item �˻��ϱ�\n";
	cout << "\t 5 : ������ Item �˻��ϱ�\n";
	cout << "\t 6 : �̸����� Item �˻��ϱ�\n";
	cout << "\t 7 : �����Ϸ� Item �˻��ϱ�\n";
	cout << "\t 8 : TempList ����\n";
	cout << "\t 9 : ��� Item ����ϱ�\n";
	cout << "\t 10 : MasterList�� Item �ű�� \n";
	cout << "\t 0 : ������� ���ư���\n" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// shows menu and receive the command from keyboard
int Application::GetCommandAccountBook()
{
	int command;
	cout << endl << endl;
	cout << "\tAccountBook���� ������ command�� �Է��ϼ���\n";
	cout << "\t=ID ================= Command =====================\n";
	cout << "\t 1 : ���ϴ� ��¥ �Һ� ���� ����\n";
	cout << "\t 2 : ���ϴ� �� �Һ� ���� �м�\n";
	cout << "\t 3 : ���ϴ� �⵵ �Һ� ���� �м�\n";
	cout << "\t 0 :	������� ���ư���\n";
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// receive Goods record from keyboard and add to list
bool Application::AddItem() {
	cout << "\t=====================Add item=====================\n";
	ItemType item;
	item.SetGoodsFromKB(); // item�� �Է¹޴´�
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1�̸� TemptList�� ����
		if (!m_MasterList.Retrieve(item)) {
			if (m_TempList.EnQueue(item)) {
				cout << "\n\t Item���忡 �����߽��ϴ�\n";
				DisplayAllItemTempList();
				return true;
			}
			return false;
		}
		else {
			cout << "\n\t�ߺ��� ID�� �����մϴ�\n";
			return false;
		}
	}
	else { // StorageId, ContainerList�� -1�� �ƴϸ�
		StorageType storage; // StorageId�� ���� storage�� �ϳ� ����
		storage.SetId(item.GetStorageId());
		if (!m_TempList.Retrieve(item)) {
			if (m_MasterList.Add(item)) {
				if (m_StorageList.Retrieve_Binary(storage)) { // StorageId�� ���� storage�� �����ϸ�
					ContainerType container;
					container.SetId(item.GetContainerId());
					if (storage.GetContainer(container)) { // containerId�� ���� container�� �����ϸ�
						if (container.AddItem(item)) {
							storage.UpdateContainer(container);
							m_StorageList.Replace(storage);
							cout << "\n\t Item���忡 �����߽��ϴ�.\n";
							cout << "\n\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
					else { // containerId�� ���� container�� ���� ��
						cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " ����=====================\n";
						container.SetLocationFromKB();
						container.AddItem(item);
						if (storage.AddContainer(container)) {
							if (m_StorageList.Replace(storage)) {
								cout << "\n\t Item���忡 �����߽��ϴ�.\n";
								cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
								container.DisplayAllItem();
								return true;
							}
							else {
								cout << "\n\tItem���忡 �����߽��ϴ�\n";
								return false;
							}
						}
					}
				}
				else { // StorageId�� ���� storage�� �������� ���� ��(container�� �翬�� ����)
					int InMaxNum;
					cout << "\n\t=====================Storage:" << storage.GetId() << " ����=====================\n";
					ContainerType container;
					cout << "\t�ش��ϴ� storage�� ���� ���� ����ϴ�.\n";
					cout << "\t�ִ� ���������� ���������� ������ �Է��Ͻÿ� : ";
					cin >> InMaxNum;
					storage.SetMaxNum(InMaxNum);
					cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << item.GetContainerId() << " ����=====================\n";
					container.SetId(item.GetContainerId());
					container.SetLocationFromKB();
					container.AddItem(item);
					if (storage.AddContainer(container)) {
						if (m_StorageList.Add(storage)) {
							cout << "\n\t Item���忡 �����߽��ϴ�.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
				}
			}
			return false;
		}
		return false;
	}
	return false;
}

// Item�� �Է¹޾� ContainerId�� ������ MasterList -1�̸� TempList�� �ִ´�.
bool Application::AddItem(ItemType item) {
	if (item.GetContainerId() == -1 || item.GetStorageId() == -1) {	// ContainerId == -1�̸� TemptList�� ����
		if (!m_MasterList.Retrieve(item)) {
			if (m_TempList.EnQueue(item)) {
				cout << "\n\t Item���忡 �����߽��ϴ�\n";
				DisplayAllItemTempList();
				return true;
			}
			return false;
		}
		else return false;
	}
	else { // StorageId, ContainerList�� -1�� �ƴϸ�
		StorageType storage; // StorageId�� ���� storage�� �ϳ� ����
		storage.SetId(item.GetStorageId());
		if (!m_TempList.Retrieve(item)) {
			if (m_MasterList.Add(item)) {
				if (m_StorageList.Retrieve_Binary(storage)) { // StorageId�� ���� storage�� �����ϸ�
					ContainerType container;
					container.SetId(item.GetContainerId());
					if (storage.GetContainer(container)) { // containerId�� ���� container�� �����ϸ�
						if (container.AddItem(item)) {
							storage.UpdateContainer(container);
							m_StorageList.Replace(storage);
							cout << "\n\t Item���忡 �����߽��ϴ�.\n";
							cout << "\n\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
					else { // containerId�� ���� container�� ���� ��
						cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " ����=====================\n";
						container.SetLocationFromKB();
						container.AddItem(item);
						if (storage.AddContainer(container)) {
							if (m_StorageList.Replace(storage)) {
								cout << "\n\t Item���忡 �����߽��ϴ�.\n";
								cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
								container.DisplayAllItem();
								return true;
							}
							else {
								cout << "\n\tItem���忡 �����߽��ϴ�\n";
								return false;
							}
						}
					}
				}
				else { // StorageId�� ���� storage�� �������� ���� ��(container�� �翬�� ����)
					int InMaxNum;
					cout << "\n\t=====================Storage:" << storage.GetId() << " ����=====================\n";
					ContainerType container;
					cout << "\t�ش��ϴ� storage�� ���� ���� ����ϴ�.\n";
					cout << "\t�ִ� ���������� ���������� ������ �Է��Ͻÿ� : ";
					cin >> InMaxNum;
					storage.SetMaxNum(InMaxNum);
					cout << "\n\t=====================Storage:" << storage.GetId() << " Container:" << item.GetContainerId() << " ����=====================\n";
					container.SetId(item.GetContainerId());
					container.SetLocationFromKB();
					container.AddItem(item);
					if (storage.AddContainer(container)) {
						if (m_StorageList.Add(storage)) {
							cout << "\n\t Item���忡 �����߽��ϴ�.\n";
							cout << "\t=====================Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
							container.DisplayAllItem();
							return true;
						}
					}
				}
			}
			return false;
		}
		return false;
	}
	return false;
}

// Id�� �Է¹޾� MasterList�� Container���� �����ش�
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
			cout << "\t=====================���� �� Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem ������ �����߽��ϴ�\n";
	return false;

}

// Item�� �Է¹޾� MasterList�� Container���� �����Ѵ�
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
			cout << "\t=====================���� �� Storage:" << item.GetStorageId() << " Container:" << item.GetContainerId() << "=====================\n";
			container.DisplayAllItem();
			return true;
		}
	}
	cout << "\tItem ������ �����߽��ϴ�\n";
	return false;
}

// Id�� �Է¹޾� MasterList���� �˻��Ѵ�
bool Application::RetrieveItemMasterList()
{
	ItemType item;
	item.SetIdFromKB();
	cout << "\n\t=====================Item ID:" << item.GetId() << "=====================\n";
	if (m_MasterList.Retrieve(item)) {
		item.DisplayGoodsOnScreen();
		return true;
	}
	cout << "\tã�� item�� �������� �ʽ��ϴ�.\n";
	return false;
}

// item ������ �Է¹޾� MasterList���� �˻��Ѵ�
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
		cout << "\tã�� ������ item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;

}

// item �̸��� �Է¹޾� MasterList���� �˻��Ѵ�
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
		cout << "\tã�� �̸��� item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;
}

// item�� �������� �Է¹޾� MasterList���� �˻��Ѵ�
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
		cout << "\tã�� �������� item�� �������� �ʽ��ϴ�.\n";
		return false;
	}
	return true;
}

// item�� �������� �������� �Է¹޾� MasterList���� �˻��Ѵ�
bool Application::SearchByPurchasePeriodMasterList()
{
	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType temp = itor.Next();
	bool found = false;
	int StartDay, EndDay;
	cout << "\n\tã������ ������ �������� �Է��Ͻÿ�(��: 19970602 (1997��6��2��)) :";
	cin >> StartDay;
	cout << "\tã������ ������ �������� �Է��Ͻÿ�(��: 19970602 (1997��6��2��)) :";
	cin >> EndDay;
	if (StartDay > EndDay) {
		cout << "\t������ �߸� �����߽��ϴ�\n";
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
		cout << "\tã�� ������ ������ item�� �������� �ʽ��ϴ�.\n";
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
		StorageType storage(item.GetStorageId());
		m_StorageList.Retrieve_Binary(storage);
		ContainerType container(item.GetContainerId());
		storage.GetContainer(container);
		container.DeleteItem(item);
		storage.UpdateContainer(container);

		item.SetContainerId(-1);
		item.SetStorageId(-1);
		m_TempList.EnQueue(item);
		m_MasterList.Delete(item);
		cout << "\t���������� �̵��߽��ϴ�\n";
		return true;
	}
	cout << "\t�̵���Ű���� Item�� �������� �ʽ��ϴ�\n";
	return false;
}

// RunContainer�� �� StorageId�� �Է¹���	
int Application::GetStorageId()
{
	int InStorageId;
	cout << "\t�����ϰ��� �ϴ� ������� ID�� �Է��Ͻÿ� : ";
	cin >> InStorageId;
	return InStorageId;
}

// StorageId�� �Է¹޾� �� �ȿ� �ִ� container�� ������ ����Ʈ�� �����
void Application::DisplayAllContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t������� ID�� �Է��Ͻÿ� : ";
	cin >> storageId;
	storage.SetId(storageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container ����=====================\n";
		storage.DisplayAllContainer();
		cout << "\t-----------------------------------------------\n";
	}
	else {
		cout << "\tã������ ID�� ����Ұ� �����ϴ�.\n";
	}
}

// StorageId�� �Է¹޾� �� �ȿ� �ִ� container�� �� ������ ����Ʈ�� MasterList�� ������ �����
void Application::DisPlayAllDetailsContainer()
{
	StorageType storage;
	int storageId;
	cout << "\t������� ID�� �Է��Ͻÿ� : ";
	cin >> storageId;
	storage.SetId(storageId);
	if (m_StorageList.Retrieve_Binary(storage)) {
		cout << "\t=====================Storage:" << storage.GetId() << " Container ����=====================\n";
		storage.DisplayAllDetailsContainer(m_MasterList);
	}
	else {
		cout << "\tã������ ID�� ����Ұ� �����ϴ�.\n";
	}
}

// ������� Container ����� ����Ѵ�
void Application::PrintContainerList(StorageType& storage)
{
	cout << "\t=====================Storage:" << storage.GetId() << " Container ����=====================\n";
	storage.DisplayAllContainer();
}

// ������� Container�� photo�� �߰��Ѵ�.
bool Application::AddPhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t�߰��� Photo�� �Է��Ͻÿ� : ";
		cin >> photo;
		if (container.AddPhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto�� ���������� �߰��߽��ϴ�.\n";
			cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto���忡 �����߽��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container���� �Է¹��� photo�� �����Ѵ�.
bool Application::DeletePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		cout << "\n\t������ Photo�� �Է��Ͻÿ� : ";
		cin >> photo;
		if (container.DeletePhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto�� ���������� �����߽��ϴ�.\n";
			cout << "\t=====================���� �� Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto������ �����߽��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container���� �Է¹��� photo�� �����Ѵ�.
bool Application::UpdatePhoto(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		string photo;
		cout << "\t=====================Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
		container.DisplayAllPhoto();
		cout << "\n\t������ Photo�� �Է��Ͻÿ� : \n";
		cin >> photo;
		if (container.UpdatePhoto(photo)) {
			storage.UpdateContainer(container);
			cout << "\tPhoto�� ���������� �����߽��ϴ�.\n";
			cout << "\t=====================���� �� Storage:" << storage.GetId() << " Container:" << container.GetId() << " PhotoList=====================\n";
			container.DisplayAllPhoto();
			return true;
		}
		else {
			cout << "\tPhoto������ �����߽��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container�� photolist�� ����Ѵ�
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
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container���� item�� �˻��Ѵ�.
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
			cout << "\tã������ item�� �������� �ʽ��ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container���� item�� kind�� �˻��Ѵ�.
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
			cout << "\t�ش��ϴ� ������ ��ǰ�� �����ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container���� item�� Name���� �˻��Ѵ�.
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
			cout << "\t�ش��ϴ� �̸��� ��ǰ�� �����ϴ�\n";
			return false;
		}
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// ������� Container�� ����.
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
		cout << "\n\tContainer:" << container.GetId() << " �� ���������� ��������ϴ�\n\n";
	}
	else {
		cout << "\tã������ container�� �������� �ʽ��ϴ�\n";
	}
}

// ������� container�� �ִ� ��� item�� ����Ѵ�.
void Application::DisplayAllItemContainer(StorageType& storage)
{
	ContainerType container;
	container.SetIdFromKB();
	if (storage.GetContainer(container)) {
		container.DisplayAllItem();
	}
	else {
		cout << "\tã������ containe�� �������� �ʽ��ϴ�\n";
	}
}

// receive keynumber from keyboard and find item in TempList which same keynumber and delete that item
bool Application::DeleteItemTempList()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_TempList.Delete(item)) {
		cout << "\t���������� �����߽��ϴ�\n\n";
		cout << "\t=====================���� �� TempList=====================\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\tã���ִ� item�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// receive Goods record from keyboard and find item has same keynumber and replace the record with new record
bool Application::ReplaceItemTempList()
{
	ItemType item;
	item.SetGoodsExceptStorageFromKB();
	item.SetContainerId(-1);
	item.SetStorageId(-1);

	if (m_TempList.Replace(item)) {
		cout << "\n\t���������� item�� �����߽��ϴ�.\n";
		cout << "\t=====================���� �� TempList=====================\n";
		m_TempList.DisplayAllTempItems();
		return true;
	}
	else {
		cout << "\tã������ item�� �������� �ʽ��ϴ�.\n";
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
		cout << "\tã������ item�� �������� �ʽ��ϴ�\n";
		return false;
	}
}

// receive word from keyboard and display the kind of item Kind display that record on screen
bool Application::SearchByKindTempList()
{
	return m_TempList.SearchByKind();
}

// receive Name from keyboard and find item which Name include the Name and display that record on screen
bool Application::SearchByNameTempList()
{
	return m_TempList.SearchByName();
}

// receive PurchaseDay from keyboard and find item which Name include the PurchaseDay and display that record on screen
bool Application::SearchByPurchaseDayTempList()
{
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
	while (m_TempList.DeQueue(item)) {
		cout << "\n\t=====================TempList NextItem=====================\n";
		item.DisplayGoodsExceptStorageOnScreen();
		int ContainerId, StorageId;
		cout << "\t�ű�� ���� StorageId�� �Է��Ͻÿ� : ";
		cin >> StorageId;
		cout << "\t�ű�� ���� ContainerId�� �Է��Ͻÿ� : ";
		cin >> ContainerId;

		if (StorageId == -1 || ContainerId == -1) {
			cout << "\t�ӽ�����Ҵ� �Է��ϸ� �ȵ˴ϴ�. �ٽ� �ӽ�����ҿ� �����մϴ�.\n";
			m_TempList.EnQueue(item);
		}
		else {
			item.SetStorageId(StorageId);
			item.SetContainerId(ContainerId);
			if (AddItem(item)) {
				cout << "\t���������� ����Ҹ� �Ű���ϴ�\n";
			}
			else {
				cout << "\t����Ҹ� �ű�µ� �����߽��ϴ�. �ٽ� �ӽ�����ҿ� �����մϴ�.\n";
				m_TempList.EnQueue(item);
			}
		}
	}
}

void Application::DisplayDayExpenseRecord()
{
	int m_Sum = 0;
	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType item;
	ItemType temp = itor.Next();
	bool found = false;
	item.SetPurchaseDayFromKB();


	cout << "\n\t=====================Item PurchaseDay:" << item.GetPurchaseDay() << "=====================\n";
	while (itor.NextNotNull()) {
		if (temp.GetPurchaseDay() == item.GetPurchaseDay()) {
			temp.DisplayNameOnScreen();
			temp.DisplayKindOnScreen();
			temp.DisplayNameOnScreen();
			temp.DisplayIdOnScreen();
			cout << "\n";
			found = true;
			m_Sum += temp.GetPrice();
		}
		temp = itor.Next();
	}



	if (!found) {
		cout << "\t�ش��ϴ� ���� ������ item�� �������� �ʽ��ϴ�.\n";
		return;
	}
	cout << "\n\t===================" << item.GetPurchaseDay() << " �� ���� �Ѿ� : " << m_Sum << "��===================\n";
}

// ���� �Է¹޾� �� ���� �Һ� �м� ����� ��µȴ�.
void Application::DisplayMonthExpenseRecord()
{
	int* ExpenseSumPerKind = new int[5]();
	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType temp = itor.Next();
	bool found = false;
	int m_Month;
	cout << "\n\t�Һ� ������ �˰� ���� ���� �Է��Ͻÿ� (��: 202005 (2020�� 5��)) :";
	cin >> m_Month;
	while (m_Month < 190000 || m_Month > 210000 || m_Month % 100 == 0 || m_Month % 100 > 12) {
		cout << "\n\t�߸� �Է��Ͽ����ϴ�. �Һ� ������ �˰� ���� ���� �ٽ� �Է��Ͻÿ� (��: 202005 (2020�� 5��)) :";
	}

	cout << "\n\t=====================Item PurchaseMonth:" << m_Month << "=====================\n";
	while (itor.NextNotNull()) {
		if (temp.GetPurchaseDay() / 100 == m_Month) {
			temp.DisplayNameOnScreen();
			temp.DisplayPriceOnScreen();
			temp.DisplayKindOnScreen();
			temp.DisplayIdOnScreen();
			cout << "\n";
			found = true;
			ExpenseSumPerKind[temp.GetKind()] += temp.GetPrice();
		}
		temp = itor.Next();
	}

	if (!found) {
		cout << "\t�ش��ϴ� �޿� ������ item�� �������� �ʽ��ϴ�.\n";
		delete[] ExpenseSumPerKind;
	}
	else {
		int MaxExpenseKind = 0;
		for (int i = 1; i < 5; i++) {
			if (ExpenseSumPerKind[MaxExpenseKind] < ExpenseSumPerKind[i])
				MaxExpenseKind = i;
		}
		int PricePerBlock = ExpenseSumPerKind[MaxExpenseKind] / 25;

		int m_Sum = 0;

		cout << "\n\t=========================" << m_Month << " �� �Һ� �м�==========================\n";
		cout << "\t--------------------- ���� ���� �� �Һ� ������Ʈ ---------------------\n\n";
		cout << "\t         ��\n";
		for (int i = 0; i < 5; i++) {
			m_Sum += ExpenseSumPerKind[i];
			cout << "\tKind : " << i << " �� ";
			for (int BlockCount = 0; BlockCount < ExpenseSumPerKind[i] / PricePerBlock; BlockCount++) {
				cout << "��";
			}
			cout << " (" << ExpenseSumPerKind[i] << "��)\n";
			cout << "\t         ��\n";
		}
		cout << "\n\t====================" << m_Month << " �� ���� �Ѿ� : " << m_Sum << "��====================\n";

		delete[] ExpenseSumPerKind;
	}
}

// �ظ� �Է¹޾� �� ���� �Һ� �м� ����� ��µȴ�.
void Application::DisplayYearExpenseRecord()
{
	int* ExpenseSumPerKind = new int[5]();
	int* ExpenseSumPerMonth = new int[12]();

	DoublyIterator<ItemType> itor(m_MasterList);
	ItemType temp = itor.Next();
	bool found = false;
	int m_Year;
	int m_Month;
	cout << "\n\t�Һ� ������ �˰� ���� �⵵�� �Է��Ͻÿ� (��: 2020 (2020��)) :";
	cin >> m_Year;
	while (m_Year < 1900 || m_Year > 2100) {
		cout << "\t�߸� �Է��Ͽ����ϴ�. �Һ� ������ �˰� ���� �⵵�� �Է��Ͻÿ� (��: 2020 (2020��)) :";
		cin >> m_Year;
	}

	cout << "\n\t=====================Item PurchaseYear:" << m_Year << "=====================\n";
	while (itor.NextNotNull()) {
		if (temp.GetPurchaseDay() / 10000 == m_Year) {
			m_Month = temp.GetPurchaseDay() / 100;
			temp.DisplayNameOnScreen();
			temp.DisplayPriceOnScreen();
			temp.DisplayIdOnScreen();
			cout << "\n";
			found = true;
			ExpenseSumPerKind[temp.GetKind()] += temp.GetPrice();
			ExpenseSumPerMonth[m_Month % 100 - 1] += temp.GetPrice();
		}
		temp = itor.Next();
	}

	if (!found) {
		cout << "\t�ش��ϴ� �ؿ� ������ item�� �������� �ʽ��ϴ�.\n";
		delete[] ExpenseSumPerKind;
		delete[] ExpenseSumPerMonth;
	}
	else {
		int MaxExpenseKind = 0;
		for (int i = 1; i < 5; i++) {
			if (ExpenseSumPerKind[MaxExpenseKind] < ExpenseSumPerKind[i])
				MaxExpenseKind = i;
		}
		int PricePerBlock = ExpenseSumPerKind[MaxExpenseKind] / 25;

		int m_Sum = 0;

		cout << "\n\t==========================" << m_Year << " �� �Һ� �м�===========================\n";
		cout << "\t--------------------- ���� ���� �� �Һ� ������Ʈ ---------------------\n\n";
		cout << "\t         ��\n";
		for (int i = 0; i < 5; i++) {
			m_Sum += ExpenseSumPerKind[i];
			cout << "\tKind : " << i << " �� ";
			for (int BlockCount = 0; BlockCount < ExpenseSumPerKind[i] / PricePerBlock; BlockCount++) {
				cout << "��";
			}
			cout << " (" << ExpenseSumPerKind[i] << "��)\n";
			cout << "\t         ��\n";
		}

		int MaxExpenseMonth = 0;
		for (int i = 1; i < 12; i++) {
			if (ExpenseSumPerMonth[MaxExpenseMonth] < ExpenseSumPerMonth[i])
				MaxExpenseMonth = i;
		}
		PricePerBlock = ExpenseSumPerMonth[MaxExpenseMonth] / 25;

		cout << "\n\t----------------------- ���� �Һ� ������Ʈ -----------------------\n\n";
		cout << "\t         ��\n";
		for (int i = 0; i < 12; i++) {
			cout << "\tMonth : ";
			if (i < 9) cout << "0";
			cout << i + 1 << " �� ";
			for (int BlockCount = 0; BlockCount < ExpenseSumPerMonth[i] / PricePerBlock; BlockCount++) {
				cout << "��";
			}
			cout << " (" << ExpenseSumPerMonth[i] << "��)\n";
			cout << "\t         ��\n";
		}
		cout << "\n\t=====================" << m_Year << " �� ���� �Ѿ� : " << m_Sum << "��=====================\n";

		delete[] ExpenseSumPerKind;
		delete[] ExpenseSumPerMonth;
	}
}
