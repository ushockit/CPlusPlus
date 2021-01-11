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
		���������� ����� - ���������� �����, ������� ������������� ������������
		�������� �� ����� �������� �����
		�������� ��������� - ����������, ������� ��������� �� �������� ����.
		�������� �����-�� ���������� �� �������� ����� (������, ������� � ����� � �.�.)
	*/

	//FILE - �������� ���������
	FILE* f;
	/*
		mode:
			r - ������ (���� ����� ��� �� ������)
			w - ������ (���� ����� ��� �� �� ���������)
			a - ���������� � ����� (���� ����� ��� �� �� ���������)
			r+ - ������ + ������ (���� ������ ������������)
			w+ - ������ + ������ (����� ������ ����� ���� � ������, ���� ��� ���)
			a+ - ���������� + ������ (����� ������ ����� ���� � ������, ���� ��� ���)
	*/
	//fopen_s(&f, "demo.txt", "w");
	//if (f) {
	//	//��������� ����������� �����
	//	int handle = _fileno(f);
	//	//��������� ������� �����
	//	long size = _filelength(handle);
	//	//int res = _access("demo.txt", 2);
	//	//�������� ����� �� ������������� (0 - ���� ����������)
	//	int res = _access("demo.txt", 0);
	//	cout << "File handle = " << handle << endl;
	//	cout << "File size = " << size << endl;
	//	
	//		//fputc - ������ ������� �� �����
	//		//fgetc - ������ ������� � ����
	//		//fgets - ������ ������ �� �����
	//		//fputs - ������ ������ � ����
	//		//fread
	//		//fwrite
	//		//feof - �������� �� ����� �����
	//		//_fileno - ��������� ����������� �����
	//		//fseek - ��������� �������
	//		//_access - �������� ������ �������
	//		//_filelength - ������ ����� � ������
	//		//_locking - ���������� ������������ ����
	//	

	//	//������ ������� � ����
	//	fputc('a', f);
	//	fputc('b', f);
	//	fputc('c', f);

	//	char buff[] = "Hello world\r\n";

	//	fputs(buff, f);
	//	//�������� �����
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

	////���� ��� ������
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
	//	//�������� �� 3 ����� ����� ������������ ����� �����
	//	fseek(f, -3, SEEK_END);
	//	//�������� �� 3 ����� ������ ������������ ������ �����
	//	fseek(f, 3, SEEK_SET);
	//	//�������� �� 3 ����� ������ ������������ ������� �������
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
	//	//������ ���-�� ���������
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