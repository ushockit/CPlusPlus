#include <iostream>
#include "DynamicArray.h"

//-= ������������ ��������� ������ =-
/*
	�������
	������
	�������
	�������
	����

	������������ ��������� ������ ������������ �� ���� ����� � ������� �������
*/

int main() {

	DynamicArray arr(3);

	arr.add(10);
	arr.add(20);
	arr.add(30);
	arr.add(40);
	arr.add(50);

	const int* tmp = arr.getData();
	for (int i = 0; i < arr.getCount(); i++)
	{
		std::cout << tmp[i] << std::endl;
	}

	return 0;
}