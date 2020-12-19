#include "Queue.h"

Queue::Queue(int capacity)
{
	this->capacity = capacity;
	count = 0;
	arr = new int[capacity];
}

Queue::~Queue()
{
	delete[] arr;
}

void Queue::add(int item)
{
	if (!isFull()) {
		arr[count++] = item;
	}
}

int Queue::extract()
{
	if (!isEmpty()) {
		int first = arr[0];

		//сдвиг влево
		memcpy(arr, arr + 1, sizeof(int) * (count - 1));
		count--;
		//кольцевая очередь
		//arr[count - 1] = first;
		return first;
	}
	return 0;
}

void Queue::clear()
{
	count = 0;
}

bool Queue::isEmpty()
{
	return count == 0;
}

bool Queue::isFull()
{
	return count == capacity;
}
