#include <iostream>

#include "Array_Func.h"

void InitArr(tArr* _pArr)
{
	//원본의 주소를 받아서 맴버들을 초기화하는것이다.
	//2개 메모리 생성.
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void PushBack(tArr* _pArr, int _iData)
{
	//배열의 한계치.
	//힙 영역에 할당한 공간이 다 찼다.
	if (_pArr->iMaxCount >= _pArr->iCount)
	{
		//그러면 실시간으로 추가할당을 해야한다.
		//즉 이를 재할당이라고 부른다.
		//재할당 함수.
		Reallocate(_pArr);
	}

	//여기까지 왔으면 이제 데이터를 채워야함.
	//데이터 추가.
	_pArr->pInt[_pArr->iCount] = _iData; //객체의 힙 메모리를 들고 있다.

	//현재 카운트 증가.
	++_pArr->iCount;

}

void Reallocate(tArr* _pArr)
{
	//재할당하는 기능.
	//메모리를 추가하고 MaxCount을 늘린다.

	//malloc()은 내가 원하는 크기만큼의 메모리를 요청 그러면 동적으로 힙에 그만큼 메모리를 확보한다.
	//단 원하는 주소에 할당받을 수는 없다.
	//그렇기에 잘못된 메모리에 접근하는 경우가 발생할 수도 있다.
	//즉 4~10까지의 주소 공간을 할당받았는데 1이 아닌 100을 뛰어서 104의 주소로 가버리면 문제가 발생할 수도 있다.
	//할당하지 않은곳에 가서 데이터를 써버리면 문제가 될 수 있다.
	//또한 다른 포인터가 쓰는 할당구역에 써버려도 문제가 된다.
	//이를 힙 손상이라고 한다. Heap Corruption

	//그런데 이 상황에서 메모리를 할당하고 뒤로 계속 늘릴 수 있을까?
	//그래서 처음에 동적할당 받을 때 넉넉한 공간을 제공받아야한다.
	//그것이 vector가 추가공간을 확보하는 이유.

	//그렇다면?
	//1. 새로운 공간 할당받기.
	//현재 최대 공간의 2배만큼 확보하기.
	//_pArr->pInt에 할당하게 된다면 문제가 발생한다.
	//기존에 가리키던 메모리주소(이전에 malloc()한거)는 가리키지 않고 새로운 이 주소를 가리키게 된다.
	//그렇기에 새로운 지역변수로 받는다.
	int* pNew = (int*) malloc(2 *_pArr->iMaxCount * sizeof(int));

	//2. 그리고 새로운 확장한 공간에 기존 포인터를 옮기는게 제일 좋은 방식!
	//즉 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시키는것.
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}
	
	//3. 그러기 위해서 기존 공간은 메모리를 해제한다.
	free(_pArr->pInt);

	//4. 배열포인터가 새로 할당된 공간을 가리키게 한다.
	_pArr->pInt = pNew;

	//5. MaxCount 변경점 적용
	_pArr->iMaxCount *= 2;
}

void ReeaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr, void(*SortFunc)(int* /*pData*/, int /*iCount*/))
{
	_pArr;
	SortFunc(_pArr->pInt, _pArr->iCount);
}