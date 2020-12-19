#pragma once
#include <iostream>
#include <iomanip>

class PriorityQueue
{
	//�������
	int* arr;
	//����������
	int* priorities;
	//����������� ������
	int count;
	//����� ������
	int capacity;
public:
	PriorityQueue(int capacity);
	~PriorityQueue();

	void add(int item, int priority);
	int extract();
	void clear();
	bool isEmpty();
	bool isFull();
	int getCount();
	void show();
	void showByPriorities();
};

