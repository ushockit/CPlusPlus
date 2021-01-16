#include <iostream>
#include <direct.h>
#include <io.h>
#include <Windows.h>

using namespace std;


void removeDir(const char* path) {
	int size = strlen(path) + 50;
	char* _tmpPath = new char[size];// { '\0' };
	strcpy_s(_tmpPath, size, path);
	strcat_s(_tmpPath, size, "\\*.*");
	
	_finddata_t* info = new _finddata_t;
	long findHandle = _findfirst(_tmpPath, info);
	long tmpHandle = findHandle;

	//пока есть содержимое папки
	while (tmpHandle != -1) {
		if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0) {
			char* newPath = new char[size];
			//копирование пути к текущей директории
			strcpy_s(newPath, size, path);
			//формирование пути к новой директории
			strcat_s(newPath, size, "\\");
			strcat_s(newPath, size, info->name);
			//директория
			//_A_RDONLY - только для чтения
			if (info->attrib & _A_SUBDIR) {
				
				//cout << "DIR: " << info->name << endl;
				//вызов рекурсии (переход в дочернюю директорию)
				removeDir(newPath);
			}
			//файл
			else {
				//cout << "FILE: " << info->name << endl;
				//удаление файла
				remove(newPath);
				cout << "Removed FILE: " << newPath << endl;
			}
			delete[] newPath;
		}
		//переход к следующему файлу/папке
		tmpHandle = _findnext(findHandle, info);
	}
	//удаление папки
	_rmdir(path);
	cout << "Removed DIR: " << path << endl;
	delete info;
	_findclose(findHandle);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
		_mkdir - создание директории
		_rmdir - удаление директории
	*/

	//создание 
	/*if (_mkdir("Some directory") != -1) {
		cout << "Success created" << endl;
	}
	else {
		cout << "Error!" << endl;
	}*/

	//переименование
	//rename("Some directory", "Some renamed directory");

	/*if (_rmdir("Some renamed directory") != -1) {
		cout << "Success" << endl;
	}
	else {
		cout << "Error!" << endl;
	}*/

	//рекурсивное удаление директории
	removeDir("C:\\Users\\Администратор\\Desktop\\Demo");
	return 0;
}