#pragma once
#include <iostream>
#include "Node.h"

class LinkedList
{
	Node* head;			//указатель на голову
	Node* tail;			//указатель на хвост
	int count;
public:
	LinkedList();
	~LinkedList();

	void addToTail(int value);
	void addToHead(int value);
	void removeFromTail();
	void removeFromHead();
	void insert(int value, int index);
	void removeAt(int index);
	bool isEmpty();
	void print();
	void clear();
};

