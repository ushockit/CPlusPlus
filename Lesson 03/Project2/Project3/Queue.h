#pragma once
#include <iostream>

class Queue
{
	int* arr;
	int capacity;
	int count;
public:
	Queue(int capacity);
	~Queue();

	//����������
	void add(int item);
	//����������
	int extract();
	//�������
	void clear();
	//�������� �� �������
	bool isEmpty();
	//�������� �� ������������
	bool isFull();
};

