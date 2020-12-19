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
	int* tmp = new int[count - 1];
	if (count > index) {
		int idx = 0;
		for (int i = 0; i < count; i++)
		{
			if (i != index) {
				tmp[idx++] = arr[i];
			}
		}
		delete[] arr;
		arr = tmp;
		count--;
	}
}

int DynamicArray::firstIndexOf(int item)
{
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == item) {
			return i;
		}
	}
	return -1;
}

int DynamicArray::lastIndexOf(int item)
{
	for (int i = count - 1; i >= 0; i--)
	{
		if (arr[i] == item) {
			return i;
		}
	}
	return -1;
}

void DynamicArray::resize(int size)
{
	int newSize = capacity + size;
	int* tmp = new int[newSize];
	//копирование эл-ов
	//std::copy(arr, tmp, capacity);
	//memcpy_s(tmp, count, arr, count);
	for (int i = 0; i < count; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	capacity = newSize;
	arr = tmp;
}
int DynamicArray::getCount() const
{
	return count;
}
const int* DynamicArray::getData() const
{
	return arr;
}