#include "Stack.h"

Stack::Stack()
{
	capacity = 10;
	arr = new int[capacity];
	count = 0;
}

Stack::~Stack()
{
	delete[] arr;
}

void Stack::push(int item)
{
	arr[count++] = item;
}

int Stack::pop()
{
	int item = peek();
	memcpy(arr, arr, sizeof(int) * (count - 1));
	count--;
	return item;
}

int Stack::peek()
{
	return arr[count - 1];
}

int Stack::getCount() const
{
	return count;
}

bool Stack::isFull()
{
	return count == capacity;
}

bool Stack::isEmpty()
{
	return count == 0;
}
