#pragma once

//가변배열 컨테이너.
//int형.
typedef struct _tagArr
{
	_tagArr()
	{

	}

	~_tagArr()
	{
		//예외처리.
		if (pInt)
		{
			free(pInt);

			pInt = nullptr;

			iCount = 0;

			iMaxCount = 0;
		}
	}

	//뭐가 필요할까?
	//연산자 오버로딩?

	//동적할당을 위한 포인터 변수.
	int* pInt = nullptr;

	//즉 현재까지 들어온 데이터가 몇개 들어왔는지를 나타내는 정수형 변수.
	int iCount = 0;
	//저장할 수 있는 최대 갯수
	int iMaxCount = 0;

	int* data = nullptr;

}tArr;

//함수로 만들기.

//초기화 함수.
void InitArr(tArr* _pArr);

//데이터 추가 함수.
void PushBack(tArr* _pArr, int _iData);

//공간을 추가로 확장하는 함수.
void Reallocate(tArr* _pArr);

//배열 메모리 해제.
void ReeaseArr(tArr* _pArr);
