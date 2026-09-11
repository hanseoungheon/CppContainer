#include <iostream>

#include "List.h"

int main()
{
	tLinkedList list = {};

	InItList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);
	PushFront(&list, 50);

	ReleaseList(&list);

	return 0;
}