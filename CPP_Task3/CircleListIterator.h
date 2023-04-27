#pragma once
#include "CircleList.h"
#include "Node.h"

template<typename T>
class CircleList;

template<typename T>
class Node;

template<typename T>
class CircleListIterator
{
	friend class CircleList<T>;

private:
	Node<T>* curr;

	CircleListIterator(Node<T>* node)
	{
		curr = node;
	};

public:

	CircleListIterator<T> operator++()
	{
		curr = curr->next;
		return *this;
	}

	CircleListIterator<T> operator++(int)
	{
		CircleListIterator<T> copy = CircleListIterator<T>(curr);
		curr = curr->next;
		return copy;
	}

	bool operator==(const CircleListIterator<T> it) const
	{
		return it.curr == curr;
	}

	T operator*()
	{
		return curr->value;
	}
};

