#include <iostream>
#include <io.h>
using namespace std;


struct Person {
	char firstname[20];
	char lastname[20];

	Person(char* firstname, char* lastname) {
		strcpy_s(this->firstname, firstname);
		strcpy_s(this->lastname, lastname);
	}
};

int main() {

	/*
		Дескриптор файла - уникальный номер, который присваивается операционной
		системой во время открытия файла
		Файловый указатель - переменная, которая ссылается на открытый файл.
		Содержит какую-то информацию об открытом файле (размер, позиция в файле и т.п.)
	*/

	//FILE - файловый указатель
	FILE* f;
	/*
		mode:
			r - чтение (если файла нет то ошибка)
			w - запись (если файла нет то он создается)
			a - добавление в конец (если файла нет то он создается)
			r+ - чтение + запись (файл должен существовать)
			w+ - чтение + запись (будет создан новый файл в случае, если его нет)
			a+ - добавление + чтение (будет создан новый файл в случае, если его нет)
	*/
	//fopen_s(&f, "demo.txt", "w");
	//if (f) {
	//	//получение дескриптора файла
	//	int handle = _fileno(f);
	//	//получение размера файла
	//	long size = _filelength(handle);
	//	//int res = _access("demo.txt", 2);
	//	//проверка файла на существования (0 - файл существует)
	//	int res = _access("demo.txt", 0);
	//	cout << "File handle = " << handle << endl;
	//	cout << "File size = " << size << endl;
	//	
	//		//fputc - чтение символа из файла
	//		//fgetc - запись символа в файл
	//		//fgets - чтение строки из файла
	//		//fputs - запись строки в файл
	//		//fread
	//		//fwrite
	//		//feof - проверка на конец файла
	//		//_fileno - получение дескриптора файла
	//		//fseek - изменение позиции
	//		//_access - проверка уровня доступа
	//		//_filelength - размер файла в байтах
	//		//_locking - блокировка определенных байт
	//	

	//	//запись символа в файл
	//	fputc('a', f);
	//	fputc('b', f);
	//	fputc('c', f);

	//	char buff[] = "Hello world\r\n";

	//	fputs(buff, f);
	//	//закрытие файла
	//	fclose(f);
	//}

	/*fopen_s(&f, "demo.txt", "r");


	if (f) {
		char buff[100];

		while (!feof(f)) {
			fgets(buff, 100, f);
			cout << buff;
		}

		fclose(f);
	}*/
	/*if (!f) {
		cout << "Error" << endl;
		return 0;
	}*/

	//const int COUNT = 3;
	//char words[][10] = {
	//	"First",
	//	"Second",
	//	"Third"
	//};

	//fopen_s(&f, "words.txt", "w");

	////файл был открыт
	//if (f) {
	//	for (int i = 0; i < COUNT; i++)
	//	{
	//		fwrite(words[i], sizeof(char), strlen(words[i]), f);
	//		if (i < COUNT - 1)
	//			fwrite("\n", sizeof(char), 1, f);
	//	}

	//	fclose(f);
	//}

	//fopen_s(&f, "words.txt", "r");

	//if (f) {
	//	//смещение на 3 байта влево относительно конца файла
	//	fseek(f, -3, SEEK_END);
	//	//смещение на 3 байта вправо относительно начала файла
	//	fseek(f, 3, SEEK_SET);
	//	//смещение на 3 байта вправо относительно текущей позиции
	//	fseek(f, 3, SEEK_CUR);
	//	while (!feof(f)) {
	//		char buff[20];
	//		fgets(buff, 20, f);
	//		cout << buff;
	//	}
	//	fclose(f);
	//}

	/*fopen_s(&f, "words.txt", "a");

	if (f) {
		fwrite("\n", sizeof(char), 1, f);
		fwrite("Fifth", sizeof(char), strlen("Fifth"), f);
		fclose(f);
	}*/


	//int count = 3;
	//Person** people = new Person * [count] {
	//	new Person((char*)"Vasya", (char*)"Pupkin"),
	//		new Person((char*)"Petya", (char*)"Ivanov"),
	//		new Person((char*)"Masha", (char*)"Stepanova"),
	//};

	//fopen_s(&f, "people.bin", "wb");

	//if (f) {
	//	char counfBuff[5];
	//	_itoa_s(count, counfBuff, 10);
	//	//запись кол-ва элементов
	//	fputs(counfBuff, f);
	//	fputc('\n', f);

	//	for (int i = 0; i < count; i++)
	//	{
	//		fputs(people[i]->firstname, f);
	//		fputc('\n', f);
	//		fputs(people[i]->lastname, f);
	//		if (i < count - 1)
	//			fputc('\n', f);
	//	}

	//	fclose(f);
	//}

	Person** people;
	fopen_s(&f, "people.bin", "rb");
	if (f) {
		int count;

		char countBuff[5];

		fgets(countBuff, 5, f);

		count = atoi(countBuff);
		people = new Person * [count];

		char firstnameBuff[30];
		char lastnameBuff[30];
		for (int i = 0; i < count; i++)
		{
			fgets(firstnameBuff, 30, f);
			fgets(lastnameBuff, 30, f);
			Person* person = new Person(firstnameBuff, lastnameBuff);
			people[i] = person;
		}

		fclose(f);
	}



	return 0;
}