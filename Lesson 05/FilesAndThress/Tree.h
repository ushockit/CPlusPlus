#pragma once
#include <iostream>
#include "Leaf.h"

class Tree
{
	Leaf* root;		//корень
public:
	//конструктор
	Tree();
	//деструктор
	~Tree();

	//вывод дерева относительно переданного узла
	void print(const Leaf* leaf);
	//поиск минимального
	Leaf* min();
	//поиск максимального
	Leaf* max();
	//вставка нового узла
	void insert(int value);
	//получение корня
	const Leaf* getRoot() const;
	//очистка дерева
	void clear(Leaf* leaf);
	//поиск
	Leaf* search(const Leaf* leaf, int value);
};

