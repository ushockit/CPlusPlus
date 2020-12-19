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

	//добавление
	void add(int item);
	//извлечение
	int extract();
	//очистка
	void clear();
	//проверка на пустоту
	bool isEmpty();
	//проверка на заполненость
	bool isFull();
};

