#include <iostream>
#include <io.h>
using namespace std;


int main() {

	//stdio.h - ���������� ��� ������ � �������

	//rename - �������������� / ����������� �����
	//remove - �������� �����
	//_findfirst
	//_findnext
	//_findclose

	//�������������� �����
	/*const char* oldPath = "C:\\Users\\�������������\\Desktop\\demo.txt";
	const char* newPath = "C:\\Users\\�������������\\Desktop\\renamed-demo.txt";

	if (rename(oldPath, newPath) == 0) {
		cout << "Success renamed" << endl;
	}
	else {
		cout << "Error!" << endl;
	}*/

	//����������� �����
	/*const char* oldPath = "C:\\Users\\�������������\\Desktop\\renamed-demo.txt";
	const char* newPath = "C:\\Users\\�������������\\Desktop\\�� �� ����\\Lesson 08\\Project1\\Project1\\renamed-demo.txt";

	if (rename(oldPath, newPath) == 0) {
		cout << "Success moved" << endl;
	}
	else {
		cout << "Error!" << endl;
	}*/

	//����������� �����
	/*FILE* from, * to;

	fopen_s(&from, "C:\\Users\\�������������\\dbdemo.mdf", "rb");
	fopen_s(&to, "C:\\Users\\�������������\\Desktop\\�� �� ����\\Lesson 08\\Project1\\Project1\\dbdemo.mdf", "wb");

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

	//�������� �����
	/*if (remove("C:\\Users\\�������������\\Desktop\\renamed-demo.txt") == 0) {
		cout << "Success removed";
	}*/

	//io.h - ��� ������ ������

	//*.* - ��� �����
	_finddata_t* info = new _finddata_t;
	//����� ����������
	long findHandle = _findfirst("C:\\*.*", info);
	//��������� ���������� ��� ������� �� ����������
	long tmpHandle = findHandle;

	while (tmpHandle != -1) {
		cout << info->name << endl;
		//������� � ���������� �����
		tmpHandle = _findnext(findHandle, info);
	}

	delete info;
	//�������� �����������
	_findclose(findHandle);

	return 0;
}