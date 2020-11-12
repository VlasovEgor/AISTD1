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
void List<T>::pop_front()// we delete the first element and assign the next element to the head	 
{
	Node<T>* temp = head; //temporary object that stores the head

	head = head->pNext; //passing the head to the next element

	delete temp; //remove temp 

	Size--;

}

template<typename T>//adding a new item to the end of the list
void List<T>::push_back(T data)
{
	if (head == nullptr) //if the list is empty, a new element is created and data is passed to it
	{
		head = new Node<T>(data);
	}
	else //if the list is not empty a new element is created and the address of this element is assigned to the most recent address
	{
		Node<T>* current = this->head; //temporary variable current

		while (current->pNext != nullptr) //we move through the list until we find the last element
		{
			current = current->pNext; //passing a pointer to the next element to the current
		}
		current->pNext = new Node<T>(data); //create a new elementand assign its address instead of nullptr

	}
	Size++;
}

template<typename T>
void List<T>::clear() //clearing the list
{
	while (Size) //пока в списке есть элементы  удаляем их сначала
	{
		pop_front();
	}
}

template<typename T> // find data from index
int List<T>::at(const int index)
{
	int counter = 0; //counter to find out which element we are currently on

	Node<T>* current = this->head;//temporary variable current

	while (current != nullptr) //we move through the list until we find the last element
	{
		if (counter == index) //when we have reached the desired element we output its value
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T> // add in the beginning 
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head); //create an element, assign it a head, and specify the address of the previous head in the address field
	Size++;
}

template<typename T> //adding by index
void List<T>::insert(T data, int index)
{

	if (index == 0) //if we want to add to the beginning
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head; //a temporary pointer

		for (int i = 0; i < index - 1; i++) //moving through the list to the place where you want to insert the element
		{
			previous = previous->pNext; //pointer to the next node
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext); //create a new node, pass the necessary data to it, and take the pointer field from the previous node

		previous->pNext = newNode; //передаём прошлому узлу указатель на новый узел

		Size++;
	}


}

template<typename T>
void List<T>::removeAt(int index) //deleting by index
{
	if (index == 0) //if we want to delete the first element
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head; //a temporary pointer
		for (int i = 0; i < index - 1; i++) //moving through the list to the place where you want to remove the element
		{
			previous = previous->pNext; //pointer to the next node
		}


		Node<T>* toDelete = previous->pNext; //in this variable, we store the node that we want to delete

		previous->pNext = toDelete->pNext; //passing the pointer to the next node to the previous node

		delete toDelete; //deleting a node

		Size--;
	}

}

template<typename T> // delete last
void List<T>::pop_back()
{
	removeAt(Size - 1); //Size - 1 since the counter starts with 1 and the list starts with 0
}

template<typename T>
void List<T>::IsEmpty()//if the list is empty return 0
{
	if (head == nullptr)
		return 0;
}

template<typename T>
void List<T>::Set(T data, const int index) //replacing an element by index
{
	int counter = 0; //counter to find out which element we are currently on
	 
	Node<T>* current = this->head; //temporary variable current

	while (current != nullptr) //we move through the list until we find the last element
	{
		if (counter == index) //when we reach the desired element, we will replace its data
		{
			current->data = data; //passing the necessary data to the node
		}
		current = current->pNext;
		counter++;
	}

}

template<typename T>
void List<T>::PrintToConsole()
{
	int counter = 0; //counter to find out which element we are currently on

	Node<T>* current = this->head; //temporary variable current

	while (current != nullptr) //temporary variable current
	{

		cout << current->data; //output data in turn
		cout << endl;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::InsertList(List newList, int index) //вставка одного списка в другой список
{
	Node<T>* previous = head;
	int counter = index; //counter to find out which element we are currently on
	if (index > Size - 1)//if the index is larger than the list size
	{
		while (index > Size - 1) 
		{
			cout << "enter index less";
			cin >> index;
		}
	}
	if (index < 0) //if the index is smaller than the list size
	{
		while (index < 0) 
		{
			cout << "enter index more";
			cin >> index;
		}
	}
	while (counter > 0) //moving through the list to the desired index
	{
		previous = previous->pNext;
		counter--;
	}
	int listsize= newList.GetSize(); //memorizing the size of the second list
	int temp = previous->pNext; //remember the link to the next node
	previous->pNext= newList.head; //passing the node pointer to the beginning of the second list
	while (listsize > 0) //moving on to the second list
	{
		previous = previous->pNext; 
		listsize--;
	}
	previous->pNext = temp;//passing the last node of the second list a pointer to the next element
	Size = Size + newList.GetSize();
	
}