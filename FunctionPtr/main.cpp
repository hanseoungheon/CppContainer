#include <iostream>

#include "Array_Func.h"

using namespace std;

//예를들어 가변배열에 있다 쳐보자.
//가변배열이 정렬를 한다 쳐볼때.
//내가 버블정렬을 만들었다 쳐보자.
//그럼 버블정렬을 쓴다.
//이런식으로 함수를 인자로 전달할 수는 없을까?
//그거에서 나온게 바로 함수포인터이다.

//왜 필요한가?
//만약 내가 Sort함수들을 만든다면?
//그렇다면 매번 버블정렬 퀵정렬 등등 여러가지 정렬을 일일히 그 헤더에 구현해야한다.
//그러지 말고 기능자체를 인자로 받는것이다.
//그러기 위해서 직접구현한 가변배열을 사용.

void BubbleSort(int* _pData, int _iCount);

int main()
{
	int iArr[10]{ 96, 655, 21, 55, 859, 659, 55, 131, };

	tArr s1;

	InitArr(&s1);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, 10 - i);
	}


	cout << "동적배열의 값 : ";
	for (int i = 0; i < s1.iCount; ++i)
	{
		cout << i << "번째 인덱스 값 => " << s1.pInt[i] << endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < s1.iCount; ++i)
	{
		cout << i << "번째 인덱스의 주소 => " << &s1.pInt[i] << endl;
	}

	cout << endl;

	Sort(&s1, BubbleSort);

	for (int i = 0; i < s1.iCount; ++i)
	{
		cout << i << "번째 인덱스 값 => " << s1.pInt[i] << endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < s1.iCount; ++i)
	{
		cout << i << "번째 인덱스의 주소 => " << &s1.pInt[i] << endl;
	}

	cout << endl;

	cout << "=======고정배열=======" << endl;

	cout << "정렬 전 값." << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << i << "번째 인덱스 값 => " << iArr[i] << endl;
	}

	for (int i = 0; i < 8; ++i)
	{
		cout << i << "번째 인덱스의 주소 => " << &iArr[i] << endl;
	}

	cout << endl;

	BubbleSort(iArr, 10);

	cout << "정렬 후 값." << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << i << "번째 인덱스 값 => " << iArr[i] << endl;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << i << "번째 인덱스의 주소 => " << &iArr[i] << endl;
	}




	ReeaseArr(&s1);

	return 0;
}

//_pData는 시작하는 데이터 iCount는 얼마나 채워져 있는지.
void BubbleSort(int* _pData, int _iCount)
{
	//버블정렬.

	//데이터가 1개 이하라면 정렬하지 않는다.
	if (_iCount <= 1)
	{
		return;
	}

	//오름차순 정렬.
	while (true)
	{
		bool bIsFin = true;

		int iLoop = _iCount - 1;

		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];

				_pData[i] = _pData[i + 1];

				_pData[i + 1] = iTemp;

				bIsFin = false;
			}
		}

		if (bIsFin == true)
		{
			break;
		}
	}
}