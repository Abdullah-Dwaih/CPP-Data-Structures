#pragma once
#include <iostream>
using namespace std;


 template <class T>
class clsDblLinkedList
{

protected:

	int _Size;

public:

	class Node {
	public:
		T value;
		Node* prev;
		Node* next;
	};

	Node* head = NULL;

	void PrintList()

	{
		Node* Current = head;

		while (Current != NULL) 
		{
			cout << Current->value << " ";
			Current = Current->next;
		}

		cout << "\n";

		delete Current;
	}

	void InsertAtBeginning(T Value)
	{
		
		Node* new_node = new Node();

		new_node->value = Value;
		new_node->next = head;
		new_node->prev = NULL;

		if (head != NULL)
		{
			head->prev = new_node;
		}

		head = new_node;
		_Size++;
	}

	Node* Find( T value)

	{
		Node* Current = head;
		while (Current != NULL)
		{
			if (Current->value == value)
				return Current;
			else
				Current = Current->next;
		}

		return NULL;

	}

	void InsertAfter(Node* prevNode, T value)
	{
		Node* newNode = new Node();

		newNode->value = value;
		newNode->prev = prevNode;
		newNode->next = prevNode->next;

		if (newNode->next != NULL)
		{
			newNode->next->prev = newNode;
		}

		prevNode->next = newNode;

		_Size++;
	}

	bool InertAfter(int Index, T value)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		else {
			return false;
		}
	}

	void InsertAtEnd( T value)
	{
		Node* new_node = new Node();

		new_node->value = value;
		new_node->next = NULL;

		if (head == NULL)
		{
			new_node->prev = NULL;
			head = new_node;
		}
		else
		{
			Node* LastNode = head;

			while (LastNode->next != NULL)
			{
				LastNode = LastNode->next;
			}

			LastNode->next = new_node;
			new_node->prev = LastNode;
		}

		_Size++;
	}

	void DeleteNode( Node * &NodeToDelete)
	{

		if (head == NULL || NodeToDelete == NULL) {
			return;
		}

		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{

		if (head == NULL)
			return;


		Node* NodeToDelete = head;
		head = head->next;


		if (head != NULL)
			head->prev = NULL;


		delete NodeToDelete;
		_Size--;
	}

	void DeleteLastNode()
	{

		if (head == NULL)
			return;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}

		Node* Current = head;

		while (Current->next->next != NULL)

		{
			Current = Current->next;
		}

		Node* LastNode = Current->next;

		Current->next = NULL;
		delete LastNode;

		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool isEmpty()
	{
		return (_Size == 0);
	}

	void Clear()
	{
		while (_Size != 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = head;
		Node* swap = NULL;

		if (Current == NULL || Current->next == NULL)
		{
			return;
		}

		while (Current != NULL)
		{
			swap = Current->prev;
			Current->prev = Current->next;
			Current->next = swap;

			Current = Current->prev;
		}

		head = swap->prev;
	}

	Node *GetNode(int Index)
	{
		int Counter = 0;
		Node* Current = head;

		if (Index <0 || Index > _Size - 1)
			return NULL;


		while (Current != NULL && (Current->next != NULL))
		{
			if (Counter == Index)
			{
				break;
			}

			Counter++;
			Current = Current->next;
		}

		return Current;
		
	}

	T GetIteam(int Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;

		else
			return ItemNode->value;
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}		
		else 
		{
			return false;
		}			
	}
};

