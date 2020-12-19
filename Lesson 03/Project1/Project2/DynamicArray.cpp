#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	arr = nullptr;
	capacity = count = 0;
}

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	count = 0;
	arr = new int[capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
}

void DynamicArray::add(int item)
{
	//массив заполнен
	if (count == capacity) {
		resize(5);
	}
	arr[count++] = item;
}

void DynamicArray::insert(int index, int item)
{
}

void DynamicArray::removeAt(int index)
{
}

int DynamicArray::firstIndexOf(int item)
{
	return 0;
}

int DynamicArray::lastIndexOf(int item)
{
	return 0;
}

void DynamicArray::resize(int size)
{
	int newSize = capacity + size;
	int* tmp = new int[newSize];
	//копирование эл-ов
	std::copy(arr, tmp, capacity);
	delete[] arr;
	capacity = newSize;
	arr = tmp;
}
int DynamicArray::getCount() 
{
	return count;
}
const int * DynamicArray::getData() 
{
	return arr;
}