#pragma once
//함수 포인터용 가변배열 실습자료.



//가변배열 컨테이너.
//int형.
typedef struct _tagArr
{

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

//함수포인터.
//퀵정렬 버블정렬 다 구현하기는 싫다.
//그래서 함수포인터라는 것을 쓴다.
//이것은 인자로 함수를 받는다!
//그러면 main에서 기능을 구현하고 그 함수를 인자로 넣는것.
//main에서 BubbleSort함수를 만들고 그 Bubble함수식으로 정렬해주세요가 된다.

//받을때는 어떻게 하나?
//void Test()를 받고 싶다?
//void(*pFunc)(void) 라고 하면 된다.
//함수안에서 선언시 void(*pFunc)(void) = nullptr; 라고 한다.
//그리고 pFunc = Test
//이는 즉 void형에 *pFunc라는 포인터를 스택에 할당하고 Test()함수를 가르키는데. 인자는 아무것도 받지않으니 void
//호출시는 pFunc()호출시 Test가 호출된다.
//마치 언리얼의 델리게이트방식.

//Sort함수가 필요한거는? int*인 시작부분데이터와 int인 현재 배열에 담겨있는 수.

void Sort(tArr* _pArr, void(*SortFunc)(int* /*pData*/ ,int /*iCount*/));
