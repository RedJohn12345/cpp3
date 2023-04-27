#pragma once
#include "Node.h"
#include <stdexcept>

template<typename T>
class Node;

template<typename T>
class CircleListIterator;

template<typename T>
class CircleList
{
	friend class CircleListIterator<T>;
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

	Node<T>* getNodeByIndex(int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("");
		}

		if (index == 0)
		{
			return head;
		}

		int i = 1;
		Node<T>* tmp = head->next;
		while (tmp != head)
		{
			if (i == index)
			{
				return tmp;
			}

			tmp = tmp->next;
			i++;
		}

	};

	Node<T>* getCurrNode(T value)
	{
		if (value == head->value)
		{
			return head;
		}

		if (value == head->next->value)
		{
			return head;
		}

		Node<T>* temp = head->next;

		while (temp != head)
		{
			if (temp->next->value == value)
			{
				return temp;
			}

			temp = temp->next;
		}
	}

	Node<T>* getPrevNode(T value)
	{
		if (value == head->value)
		{
			return nullptr;
		}

		if (value == head->next->value)
		{
			return head;
		}

		Node<T>* temp = head->next;

		while (temp != head)
		{
			if (temp->next->value == value)
			{
				return temp;
			}

			temp = temp->next;
		}
	}

public:
	CircleList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~CircleList()
	{
		Node<T>* tmp = head;
		Node<T>* next;
		while (tmp->next != head)
		{
			next = tmp->next;
			delete tmp;
			tmp = next;
		}

		delete tail;

	}
		
	bool isEmpty()
	{
		return !size;
	}

	void add(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;

		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{	
			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}

	T get(int index)
	{
		return getNodeByIndex(index);
	}

	void insert(int index, T value)
	{
		if (index < 0 || index > size)
		{
			throw std::out_of_range("");
		}

		if (index == size)
		{
			add(value);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			Node<T>* curr = head;

			if (index == 0)
			{
				head = newNode;
				newNode->next = curr;
				tail->next = head;
			}
			else
			{
				int i = 1;
				curr = curr->next;
				Node<T>* prev = head;
				while (curr != head)
				{
					if (i == index)
					{
						prev->next = newNode;
						newNode->next = curr;
						break;
					}
					i++;
					prev = curr;
					curr = curr->next;
				}
			}

			size++;
		}
	}

	bool contain(T value)
	{
		if (isEmpty())
		{
			return false;
		}
		Node<T>* tmp = head;

		while (tmp->next != head)
		{
			if (tmp->value == value)
			{
				return true;
			}
			tmp = tmp->next;
		}

		return tail->value == value;
	}

	void remove(T value)
	{
		if (!contain(value))
		{
			return;
		}

		size--;

		if (size == 0) 
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}

		Node<T>* curr = head->next;
		Node<T>* prev = head;

		if (head->value == value)
		{
			head = head->next;
			delete prev;
			tail->next = head;
			return;
		}

		while (curr != tail)
		{
			if (curr->value == value)
			{
				prev->next = curr->next;
				delete curr;
				return;
			}

			prev = curr;
			curr = curr->next;
		}

		prev->next = curr->next;
		delete curr;
		tail = prev;
	}

	void removeAll(T value)
	{
		if (isEmpty)
		{
			return;
		}
		Node<T>* curr = head->next;
		Node<T>* prev = head;

		while (head->value == value)
		{
			size--;
			if (size == 0)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
				return;
			}
			head = head->next;
			delete prev;
			tail->next = head;
			prev = head;
			curr = prev->next;
		}

		while (curr != tail)
		{
			if (curr->value == value)
			{
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
				size--;
				continue;
			}
			prev = curr;
			curr = curr->next;
		}

		if (tail->value == value)
		{
			size--;
			prev->next = curr->next;
			delete curr;
			tail = prev;
		}
	}

	void set(int index, T value)
	{
		getNodeByIndex(index)->value = value;
	}

	CircleListIterator<T> begin()
	{
		return CircleListIterator<T>(head);
	}

	CircleListIterator<T> end()
	{
		return CircleListIterator<T>(tail);
	}

};

