#pragma once
#include <iostream>

template<typename T>
class Vector
{
	T* items;				//данные
	int count;				//фактическое кол-во
	int capacity;			//общий размер
public:
	Vector() {
		items = nullptr;
		count = capacity = 0;
	}
	Vector(int capacity) : Vector() {
		this->capacity = capacity;
		items = new T[capacity];
	}


	//добавление в конец
	void pushBack(T item);
	//добавление в начало
	void pushFront(T item);
	//добаление в заданную позицию
	void pushAt(T item, int position);
	//получение элемента по заданной позиции
	T getAt(int position);
	//удаление заданного элемента
	void remove(T item);
	//удаление всех заданных элементов
	void removeAll(T item);
	//удаление по индексу
	void removeAt(int position);
	//перераспределение памяти
	void resize(int count);
	//очистка
	void clear();
	//получение подпоследовательности (передается позиция начала + кол-во выбираемых эл-ов)
	//возвращается новая последовательности размером в 'count' с элементами, которые начинаются
	//с переданной позиции 
	T* subItems(int position, int count);

	int size();
	bool isEmpty();


	//Реализовать исключения
	/*
	*	  (SequenceDoesNotContainItemException)
		- последовательность не содержит заданного элемента

		  (SequenceIsEmptyException)
		- последовательность пуста

		  (IndexOutOfRangeException)
		- индекс вне диапазона

		  (OutOfMemoryException)
		- недостаточно места
		- остальное, на свое усмотрение

	*/
};

