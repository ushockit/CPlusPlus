#pragma once
struct Leaf {
	int value;		//�������� ����
	Leaf* parent;	//��������� �� ��������
	Leaf* left;		//��������� �� ������ �������
	Leaf* right;	//��������� �� ������� �������

	Leaf(int value = 0);
};