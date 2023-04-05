#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template<typename T>
class MyList:public Node<T>
{
private:
	Node<T> *head;
	int Size;
public:
	MyList();
	MyList(std::initializer_list<T> init);
	void push_back(T data);
	int size(){return Size}
	T& operator[](const int index);
};
template<typename T>
MyList<T>::MyList()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
void MyList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}
template<typename T>
T& MyList<T>::operator[](const int index)
{
	Node<T>* current = this->head;
	int count=0;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}
