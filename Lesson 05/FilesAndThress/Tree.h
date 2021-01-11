#pragma once
#include <iostream>
#include "Leaf.h"

class Tree
{
	Leaf* root;		//������
public:
	//�����������
	Tree();
	//����������
	~Tree();

	//����� ������ ������������ ����������� ����
	void print(const Leaf* leaf);
	//����� ������������
	Leaf* min();
	//����� �������������
	Leaf* max();
	//������� ������ ����
	void insert(int value);
	//��������� �����
	const Leaf* getRoot() const;
	//������� ������
	void clear(Leaf* leaf);
	//�����
	Leaf* search(const Leaf* leaf, int value);
};

