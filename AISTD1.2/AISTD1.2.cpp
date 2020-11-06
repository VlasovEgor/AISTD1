#include <iostream>
#include "List.h"
using namespace std;


int main()
{

	List<int> lst;
	List<int>* test1 = new List<int>;
	test1->push_front(0);
	test1->push_back(12);
	test1->push_back(45);
	test1->push_back(21);
	test1->PrintToConsole();
	List<int> test;
	test.push_front(130);
	test.push_back(69);
	test.push_back(228);
	test.insert(12, 3);
	test.push_front(0);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.removeAt(2);
	test.removeAt(3);
	test.removeAt((int)test.GetSize() - 1);
	test.PrintToConsole();
	test.clear();
	test.PrintToConsole();
	return 0;
}

