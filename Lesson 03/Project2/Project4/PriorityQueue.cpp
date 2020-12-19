#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity)
{
	this->capacity = capacity;
	count = 0;
	arr = new int[capacity];
	priorities = new int[capacity];
}

PriorityQueue::~PriorityQueue()
{
	delete[] arr;
	delete[] priorities;
}

void PriorityQueue::add(int item, int priority)
{
	if (!isFull()) {
		arr[count] = item;
		priorities[count] = priority;
		count++;
	}
}


int PriorityQueue::extract()
{
	if (!isEmpty()) {
		int maxPriority = priorities[0];
		int maxPriorityidx = 0;

		//поиск максимального приоритета
		for (int i = 1; i < count; i++)
		{
			if (maxPriority < priorities[i]) {
				maxPriority = priorities[i];
				maxPriorityidx = i;
			}
		}

		//получение максимального элемента
		int maxElmt = arr[maxPriorityidx];

		//сдвиг элементов
		for (int i = maxPriorityidx; i < count - 1; i++)
		{
			arr[i] = arr[i + 1];
			priorities[i] = priorities[i + 1];
		}
		count--;
		return maxElmt;

	}
	return 0;
}

void PriorityQueue::clear()
{
	count = 0;
}

bool PriorityQueue::isEmpty()
{
	return count == 0;
}

bool PriorityQueue::isFull()
{
	return count == capacity;
}

int PriorityQueue::getCount()
{
	return count;
}

void PriorityQueue::show()
{
	std::cout << "-= Elements =-" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(3) << arr[i];
	}
	std::cout << std::endl;

	std::cout << "-= Priorities =-" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(3) << priorities[i];
	}
	std::cout << std::endl;
}

void PriorityQueue::showByPriorities()
{
	std::cout << "-= Elements =-" << std::endl;
	while (!isEmpty()) {
		std::cout << std::setw(3) << extract();
	}
	std::cout << std::endl;
}