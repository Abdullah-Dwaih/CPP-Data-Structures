#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue 

{

protected:

	clsDblLinkedList<T> _LinkedList;
public:
	
	void push(T value)
	{
		_LinkedList.InsertAtEnd(value);
		
	}

	void pop()
	{
		_LinkedList.DeleteFirstNode();
	}

	int size()
	{
		return _LinkedList.Size();
	}

	int front()
	{
		return _LinkedList.GetIteam(0);
	}
	int back()
	{
		return _LinkedList.GetIteam(size()-1);
	}

	bool isEmpty()
	{
		return _LinkedList.isEmpty();
	}
	void Print()
	{
		_LinkedList.PrintList();
	}

};

