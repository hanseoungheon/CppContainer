#pragma once

//연결형 리스트는 동적배열과는 다르다!
//동적배열은 힙 메모리에 연속적인 공간을 마련해서 데이터를 저장한다.
//하지만 연결형 리스트는 힙메모리에 매 데이터 선언마다 데이터를 선언한다. 
//즉 힙에 랜덤한 위치에 매 요소가 저장된다.
//그리고 그 요소에 번호를 새기고 다음 번호의 노드를 가르킨다.

//즉 그렇기에 노드가 필요하다.
typedef struct _tagNode
{
	//저장할 데이터.
	int iData;

	//다음 노드를 가리켜야하므로
	//다음 포인터가 필요하다.
	struct _tagNode* pNextNode = nullptr;



}tNode;


//int
typedef struct _tagList
{



	//객체에 데이터를 넣으면 몇개를 넣어야할지가 필요한다.
	int iCount;

	//그리고 매번 할당해서 데이터를 넣는 구조이기에 MaxCount는 존재하지 않는다.
	//int iMaxCount;

	//하지만 연결리스트이므로 본인은 첫 번째 노드의 위치를 알아야한다.
	//이를 헤드노드라고 부른다.
	tNode* pHeadNode;
}tLinkedList;

//리스트를 최초로 초기화하는 함수가 필요하다.
void InItList(tLinkedList* _pList);

void PushFront(tLinkedList* _pList, int _idata);

//리스트 맨 뒤에 데이터 넣기.
void PushBack(tLinkedList* _pList, int _idata);

//연결형 리스트 메모리 해제.
void Release(tNode* _pNode);

void ReleaseList(tLinkedList* _pList);
