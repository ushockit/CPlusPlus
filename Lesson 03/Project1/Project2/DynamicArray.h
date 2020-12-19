#pragma once
#include <iostream>

class DynamicArray {
	int* arr;
	int capacity;		//общий размер
	int count;			//фактическое кол-во эл-ов
public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();

	void add(int item);
	void insert(int index, int item);
	void removeAt(int index);
	int firstIndexOf(int item);
	int lastIndexOf(int item);
	void resize(int size);
	int getCount() const {
		return count;
	}
	const int* getData() const {
		return arr;
	}
};