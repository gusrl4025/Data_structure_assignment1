#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXSIZE 5
#define MAXQUEUE 31
#define MAXCONTAINER 10
#define MAXSTORAGE 5

#include "UnsortedList.h"
#include "SortedList.h"
#include "SingleLinkedList.h"
#include "CircularQueue.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"

#include "ItemType.h"
#include "SimpleItemType.h"
#include "TempType.h"
#include "StorageType.h"
#include "ContainerType.h"

#include "Application.h"

#endif // !PCH_H
