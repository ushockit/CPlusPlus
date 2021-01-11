#pragma once
struct Leaf {
	int value;		//значение узла
	Leaf* parent;	//указатель на родителя
	Leaf* left;		//указатель на левого потомка
	Leaf* right;	//указатель на правого потомка

	Leaf(int value = 0);
};