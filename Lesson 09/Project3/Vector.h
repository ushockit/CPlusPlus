#pragma once
#include <iostream>

template<typename T>
class Vector
{
	T* items;				//������
	int count;				//����������� ���-��
	int capacity;			//����� ������
public:
	Vector() {
		items = nullptr;
		count = capacity = 0;
	}
	Vector(int capacity) : Vector() {
		this->capacity = capacity;
		items = new T[capacity];
	}


	//���������� � �����
	void pushBack(T item);
	//���������� � ������
	void pushFront(T item);
	//��������� � �������� �������
	void pushAt(T item, int position);
	//��������� �������� �� �������� �������
	T getAt(int position);
	//�������� ��������� ��������
	void remove(T item);
	//�������� ���� �������� ���������
	void removeAll(T item);
	//�������� �� �������
	void removeAt(int position);
	//����������������� ������
	void resize(int count);
	//�������
	void clear();
	//��������� ��������������������� (���������� ������� ������ + ���-�� ���������� ��-��)
	//������������ ����� ������������������ �������� � 'count' � ����������, ������� ����������
	//� ���������� ������� 
	T* subItems(int position, int count);

	int size();
	bool isEmpty();


	//����������� ����������
	/*
	*	  (SequenceDoesNotContainItemException)
		- ������������������ �� �������� ��������� ��������

		  (SequenceIsEmptyException)
		- ������������������ �����

		  (IndexOutOfRangeException)
		- ������ ��� ���������

		  (OutOfMemoryException)
		- ������������ �����
		- ���������, �� ���� ����������

	*/
};

