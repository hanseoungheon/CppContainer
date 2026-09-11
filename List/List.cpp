#include <iostream>

#include "List.h"

void InItList(tLinkedList* _pList)
{
	//처음에 들어왔으면 노드만 생성한다.
	//그 다음에 굳이 값을 채울 이유는 없다.
	//리스트는 채워나가는 방식이니깐.
	//현재 컨테이너의 요소의 갯수도 0개다.
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushFront(tLinkedList* _pList, int _idata)
{
	//데이터를 어떻게 앞에 넣어야할까?
	//새로운 데이터를 만든다.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	pNewNode->iData = _idata;
	pNewNode->pNextNode = _pList->pHeadNode;

	_pList->pHeadNode = pNewNode;

	++_pList->iCount;
}

void PushBack(tLinkedList* _pList, int _idata)
{
	//데이터를 어떻게 넣어야할까?
	//새로운 노드를 만든다.
	//이때 tNode형에 tNode의 크기를 가진 데이터를 힙에 할당한다.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	//Push Back이므로 가장 마지막에 들어가게된다.
	//즉 pNode가 가장 마지막 노드임.
	
	pNode->iData = _idata;
	pNode->pNextNode = nullptr;
	

	//지금 들어온 데이터가 첫번째 일경우.
	if (_pList->iCount == 0)
	{
		//리스트의 헤더노트가 지금 이 pNode 즉 할당한 저 메모리의 주소를 저장하고 있으면 됨.
		_pList->pHeadNode = pNode;

	}
	//지금 들어온 데이터가 첫번째 데이터가 아닐 경우.
	else
	{
		//현재 가장 마지막 노드를 찾아서 해당 노드의 pNext노드의 주소로 간다.
		tNode* pCurrentNode = _pList->pHeadNode;

		//시작하자마자 찾은 노드가 끝인 노드였을 경우.


		//다음 노드가 nullptr이면 끝인 노드일것이다.
		while (pCurrentNode->pNextNode != nullptr)
		{
			//다음 노드로 갱신하며 루프.
			pCurrentNode = pCurrentNode->pNextNode;
		}

		//끝인 노드를 찾았으면 새로 생성한 노드를 넣는다.
		pCurrentNode->pNextNode = pNode;
	}

	++_pList->iCount;
}

//메모리 해제.
void Release(tNode* _pNode)
{
	//단 이런 재귀함수방식은 스택 오버플로우 가능성이 있다.
	//수천개 데이터를 넣으면 데이터가 수천개 실행되기 때문에!
	if (_pNode == nullptr)
	{
		return;
	}

	Release(_pNode->pNextNode);

	free(_pNode);
}

void ReleaseList(tLinkedList* _pList)
{
	//그렇기에 재귀방식보단 반복문을 사용한다.
	
	//0. 헤드노드를 가져온다.
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode != nullptr)
	{
		//1. 다음 노드를 저장한다.
		tNode* pNext = pDeleteNode->pNextNode;

		//2. 기존에 저장된 pDeleteNode를 삭제한다.
		free(pDeleteNode);

		//3.다음노드를 pDeleteNode에 저장한다.
		pDeleteNode = pNext;
	}

	_pList->iCount = 0;
}


