#pragma once
template<typename T>
class Node
{
protected:
	Node* pNext;
	T data;
	Node(T data = T(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

