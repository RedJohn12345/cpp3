//Односвязный циклический список (кольцо).

#include <iostream>
#include <vector>
using namespace std;
#include "CircleList.h"

int main()
{
	CircleList<int> *list = new CircleList<int>;

	list->add(1);
	list->add(2);
	list->add(3);
	//list->set(1, 10);
	

	CircleListIterator<int> it = list->begin();
	while (!(it == list->end()))
	{
		cout << *(++it) << endl;
	}

	CircleListIterator<int> it2 = list->begin();
	while (!(it2 == list->end()))
	{
		cout << *(it2++) << endl;
	}
	cout << *it2 << endl;

	delete list;

	CircleList<string>* listString = new CircleList<string>;

	listString->add("Hello");
	listString->add(", ");
	listString->add("World");

	listString->remove(", ");
	listString->set(1, "World!");
	CircleListIterator<string> it1 = listString->begin();
	
	while (!(it1 == listString->end()))
	{
		cout << *it1 << endl;

		it1++;
	}

	cout << *it1 << endl;

	delete listString;
}