#include "SmartPointer.h"

SmartPointer::SmartPointer()
{
	ptr = nullptr;
	copiesCounter++;
}

SmartPointer::SmartPointer(SmartPointer& obj)
{
	this->ptr = new int(*obj.ptr);
}

SmartPointer::SmartPointer(int value) : SmartPointer()
{
	ptr = new int(value);
}

SmartPointer::~SmartPointer()
{
	std::cout << "~SmartPointer()" << std::endl;
	std::cout << "Copies = " << copiesCounter << std::endl;
	if (ptr != nullptr && copiesCounter == 0) {
		std::cout << "Clear ptr" << std::endl;
		//������� ������
		delete ptr;
	}
	else {
		std::cout << "Copies--" << std::endl;
		//���������� �������� �����
		copiesCounter--;
	}
	system("pause");system("pause");
}

//������������� ������������ ����
int SmartPointer::copiesCounter = 0;