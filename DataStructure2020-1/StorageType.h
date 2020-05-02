#pragma once

class ContainerType;

class StorageType
{
public:
	/*
		constructor
	*/
	StorageType();
	StorageType(int max);
	/*
		Destructor
	*/
	~StorageType();
		
	/*
		@brief	Id를 반환한다
		@pre	none
		@post	none
		@return	return m_sId
	*/
	int GetId() const;

	/*
		@brief	현재 컨테이너 개수를 반환한다
		@pre	none
		@post	none
		@return	return CurrentNum
	*/
	int GetCurrentNum() const;

	/*
		@brief	최대 컨테이너 개수를 반환한다
		@pre	none
		@post	none
		@return	return MaxNum
	*/
	int GetMaxNum() const;

	/*
		@brief	Id를 설정한다
		@pre	none
		@post	none
	*/
	void SetId(int InId);

	/*
		@brief	MaxNum을 설정한다
		@pre	none
		@post	none
	*/
	void SetMaxNum(int InMaxNum);

	/*
		@brief	컨테이너리스트가 꽉 찼는지 확인
		@pre	list가 초기화돼야한다
		@post	none
		@return	list가 full 이면 return true, 아니면 return false
	*/
	bool IsFull() const;

	/*
		@brief	컨테이너리스트를 비운다
		@pre	none
		@post	컨테이너리스트가 비워진다
	*/
	void MakeEmpty();

	/*
		@brief	포인터를 초기화시킨다.
		@pre	none
		@post	포인터가 초기화된다.
	*/
	void ResetList();

	/*
		@brief	원하는 container를 찾아서 parameter에 참조한다
		@pre	list가 초기화돼야한다
		@post	찾은 container가 parameter에 참조된다
		@param	container	찾은 container를 참조함
		@return	원하는 container를 찾았으면 return true, 아니면 return false
	*/
	bool GetContainer(ContainerType& container);

	/*
		@brief	container를 list가 추가한다
		@pre	list가 초기화돼야한다
		@post	new container가 list가 추가됨
		@param	container	추가할 container
		@return	container가 추가됐으면 return true, 아니면 return false
	*/
	bool AddContainer(const ContainerType& container);

	/*
		@brief	container를 list에서 제거한다
		@pre	list가 초기화돼야한다
		@post	list에서 container가 제거됨
		@param	container	제거될 container
		@return	container가 제거됐으면 return true, 아니면 return false
	*/
	bool DeleteContainer(ContainerType& container);

	/*
		@brief	원하는 container를 list에 수정한다
		@pre	list가 초기화돼야한다
		@post	container가 list에서 수정됨
		@param	container	수정할 container
		@return	container가 추가됐으면 return true, 아니면 return false
	*/
	bool UpdateContainer(const ContainerType& container);

	/*
		@brief	다음 container를 불러온다
		@pre	containerList가 초기화돼야한다.
		@post	parameter가 다음 container를 참조함
		@param	container	다음 container를 참조함
		@return 다음 container가 있으면 return true, 아니면 return false
	*/
	bool GetNextContainer(ContainerType& container);

	/*
		@brief	container목록을 출력한다
		@pre	containerlist가 초기화돼야한다
		@post	container목록이 출력된다
	*/
	void DisplayAllContainer();

	bool operator==(const StorageType& storage) {
		if (GetId() == storage.GetId()) return true;
		return false;
	}

	bool operator>(const StorageType& storage) {
		if (GetId() > storage.GetId()) return true;
		return false;
	}

	bool operator<(const StorageType& storage) {
		if (GetId() < storage.GetId()) return true;
		return false;
	}

	void operator=(const StorageType& storage) {
		m_sId = storage.GetId();
		CurrentNum = storage.GetCurrentNum();
		MaxNum = storage.GetMaxNum();
		ContainerList = storage.ContainerList;
	}
private:
	int m_sId;
	int CurrentNum;
	int MaxNum;
	SingleLinkedList<ContainerType> ContainerList;
};