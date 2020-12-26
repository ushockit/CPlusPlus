#pragma once
#include <iostream>
#include "Node.h"

class List
{
	Node* head;		//������ ������
	Node* tail;		//����� ������
	int count;		//���������� ��������� � ������
public:
	List();
	~List();

	void addToTail(int value);
	void addToHead(int value);
	void removeFromTail();
	void removeFromHead();
	void insert(int value);
	void removeAt(int index);
	bool isEmpty();
	void print();
	void clear();
};