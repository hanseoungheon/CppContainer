#pragma once

template<typename T>
struct Node
{
	T Data;

	Node<T>* Next;
};

template<typename T>
inline Node<T>* Create(T data)
{
	Node<T>* node = new Node<T>();

	node->Data = data;

	node->Next = nullptr;

	return node;
}

template<typename T>
inline void Destroy(Node<T>* node)
{
	delete node;
	node = nullptr;
}

template<typename T>
inline void Push(Node<T>** head, Node<T>* node)
{
	//헤드가 없다면 헤드 추가.
	if ((*head) == nullptr)
	{
		*head = node;
	}
	//헤드가 있다면?
	else
	{
		Node<T>* tail = (*head);

		//꼬리가 아닐때까지 돌린다.
		while (tail->Next != nullptr)
		{
			tail = tail->Next;
		}

		tail->Next = node;
	}
}

template<typename T>
inline Node<T>* GetNode(Node<T>* head, int location)
{
	Node<T>* current = head;

	while (current != nullptr && --location >= 0)
	{
		current = current->Next;
	}

	return current;
}