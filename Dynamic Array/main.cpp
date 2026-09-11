#include <iostream>

#include "Array.h"

using namespace std;

int main()
{
	//10개만큼 할당하기 위해 40바이트를 할당함.
	//s.pInt = (int*) malloc(40);

	////현재 인덱스 갯수.
	//s.iCount = 0;
	////최대 인덱스 갯수.
	//s.iMaxCount = 10;
	//매번 이럴 순 없으니 함수 혹은 메소드로 만들기.

	//가변배열 선언.
	tArr s1;

	InitArr(&s1);



	//이 경우에는
	//재할당이 어떻게 이루어지냐면
	//처음에는 2만큼
	//또 2에서 4로 증가하고
	//4에서 8로
	//그리고 8에서 16으로 증가한다.
	//즉 크기는 16이 된다.

	
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}


	cout << "동적배열의 값 : ";
	for(int i = 0; i < s1.iCount; ++i)
	{
		cout << i << "번째 인덱스 값 => " << s1.pInt[i] << endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < s1.iCount; ++i)
	{
		cout << i << "번째 인덱스의 주소 => " << &s1.pInt[i] << endl;
	}


	ReeaseArr(&s1);

	return 0;
}