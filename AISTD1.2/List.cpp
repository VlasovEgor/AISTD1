#include "List.h"
#include <iostream>
using namespace std;


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
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
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
int List<T>::at(const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}


}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::IsEmpty()
{
	if (head == nullptr)
		return 0;
}

template<typename T>
void List<T>::Set(T data, const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	cout << endl << endl;

	while (current != nullptr)
	{
		if (counter == index)
		{
			current->data = data;
		}
		current = current->pNext;
		counter++;
	}

}

template<typename T>
void List<T>::PrintToConsole()
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{

		cout << current->data;
		cout << endl;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::InsertList(List newList, int index)
{
	Node<T>* previous = head;
	int counter = index;
	if (index > Size - 1)
	{
		while (index > Size - 1)
		{
			cout << "enter index less";
			cin >> index;
		}
	}
	if (index < 0)
	{
		while (index < 0)
		{
			cout << "enter index more";
			cin >> index;
		}
	}
	while (counter > 0)
	{
		previous = previous->pNext;
		counter--;
	}
	int listsize= newList.GetSize();
	int temp = previous->pNext;
	previous->pNext= newList.head; 
	while (listsize > 0)
	{
		previous = previous->pNext;
		listsize--;
	}
	previous->pNext = temp;
	Size = Size + newList.GetSize();
	
}