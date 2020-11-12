#pragma once
//list class description
template<typename T>
class List
{
public:
	List();
	~List();

	// remove the first item in the list
	void pop_front();

	// add an item to the end of the list
	void push_back(T data);

	// clear the list
	void clear();

	// get the number of items in the list
	int GetSize() { return Size; }

	// Getting an element by index
	int at(const int index);

	// add an item to the beginning of the list
	void push_front(T data);

	// add an item to the list at the specified index
	void insert(T data, int index);

	// deleting an element in the list at the specified index
	void removeAt(int index);

	// remove the last item in the list
	void pop_back();

	// check if the list is empty
	void IsEmpty();

	// replace the element by index with the passed element
	void Set(T data, int index);

	// output the list items to the console
	void PrintToConsole();

	// insert another list into the list, starting at the index
	void InsertList(List newList, int index);


private:

	template<typename T> //template class to avoid being bound to a single data type
	class Node
	{
	public:
		Node* pNext; //pointer to the next element
		T data; //data storage field

		Node(T data = T(), Node* pNext = nullptr) //the constructor accepts parameters from the public section of the class list
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};