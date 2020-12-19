#pragma once
#include <iostream>
class Stack
{
	int* arr;
	int count;
	int capacity;
public:
	Stack();
	~Stack();

	void push(int item);
	int pop();
	int peek();
	int getCount() const;
	bool isFull();
	bool isEmpty();
};

