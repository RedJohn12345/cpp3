#pragma once
#include "CircleList.h"
#include "CircleListIterator.h"

template<typename T>
class CircleList;

template<typename T>
class CircleListIterator;

template<typename T>
class Node
{
	friend class CircleList<T>;
	friend class CircleListIterator<T>;

private: 

	Node<T>(T value)
	{
		this->value = value;
		next = nullptr;
	}

	T value;
	Node<T>* next;
};

