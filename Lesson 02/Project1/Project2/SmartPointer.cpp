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
		//очистка памяти
		delete ptr;
	}
	else {
		std::cout << "Copies--" << std::endl;
		//уменьшение счетчика копий
		copiesCounter--;
	}
	system("pause");system("pause");
}

//инициализация статического поля
int SmartPointer::copiesCounter = 0;