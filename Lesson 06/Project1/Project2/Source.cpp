#include <iostream>
#include <io.h>
using namespace std;


int main() {

	//stdio.h - библиотека для работы с файлами

	//rename - переименование / перемещение файла
	//remove - удаление файла
	//_findfirst
	//_findnext
	//_findclose

	//переименование файла
	/*const char* oldPath = "C:\\Users\\Администратор\\Desktop\\demo.txt";
	const char* newPath = "C:\\Users\\Администратор\\Desktop\\renamed-demo.txt";

	if (rename(oldPath, newPath) == 0) {
		cout << "Success renamed" << endl;
	}
	else {
		cout << "Error!" << endl;
	}*/

	//перемещение файла
	/*const char* oldPath = "C:\\Users\\Администратор\\Desktop\\renamed-demo.txt";
	const char* newPath = "C:\\Users\\Администратор\\Desktop\\ПС сб утро\\Lesson 08\\Project1\\Project1\\renamed-demo.txt";

	if (rename(oldPath, newPath) == 0) {
		cout << "Success moved" << endl;
	}
	else {
		cout << "Error!" << endl;
	}*/

	//копирование файла
	/*FILE* from, * to;

	fopen_s(&from, "C:\\Users\\Администратор\\dbdemo.mdf", "rb");
	fopen_s(&to, "C:\\Users\\Администратор\\Desktop\\ПС сб утро\\Lesson 08\\Project1\\Project1\\dbdemo.mdf", "wb");

	if (!from) {
		cout << "Error of reading" << endl;
		return 0;
	}
	if (!to) {
		cout << "Error of writing" << endl;
		return 0;
	}
	
	//TODO: copy
	*/

	//удаление файла
	/*if (remove("C:\\Users\\Администратор\\Desktop\\renamed-demo.txt") == 0) {
		cout << "Success removed";
	}*/

	//io.h - для поиска файлов

	//*.* - все файлы
	_finddata_t* info = new _finddata_t;
	//поиск директории
	long findHandle = _findfirst("C:\\*.*", info);
	//временный дескриптор для прохода по директории
	long tmpHandle = findHandle;

	while (tmpHandle != -1) {
		cout << info->name << endl;
		//переход к следующему файлу
		tmpHandle = _findnext(findHandle, info);
	}

	delete info;
	//закрытие дескриптора
	_findclose(findHandle);

	return 0;
}