#include <iostream>

using namespace std;

class PassportInfo {
	char series[5];
	int number;
public:
	PassportInfo() {
		series[0] = '\0';
		number = 0;
	}
	PassportInfo(const char* series, int number) {
		strcpy_s(this->series, series);
		this->number = number;
	}
	const char* getSeries() const { return series; }
	int getNumber() const { return number; }
	void copy(const PassportInfo& info) {
		strcpy_s(series, info.getSeries());
		number = info.number;
	}
};

class Person {
	char firstName[30];
	char lastName[30];
	int age;
	PassportInfo passport;
public:
	Person() {
		firstName[0] = lastName[0] = '\0';
		age = 0;
	}
	Person(const char* firstName,
		const char* lastName,
		int age,
		PassportInfo* passport = nullptr)
	{
		this->age = age;
		strcpy_s(this->firstName, firstName);
		strcpy_s(this->lastName, lastName);
		if (passport != nullptr) {
			this->passport.copy(*passport);
		}
	}
};

struct Point {
	char name[30];
	int x;
	int y;

	Point() {
		name[0] = '\0';
		x = y = 0;
	}
	Point(const char* name, int x, int y) {
		strcpy_s(this->name, name);
		this->x = x;
		this->y = y;
	}
};

int main() {

	//-= ���������� �������� � ���� =-
	/*Point p("Point 1", 10, 2);

	FILE* f;

	//�������� �����
	fopen_s(&f, "point.bin", "wb");
	//���� ������
	if (f) {
		//������ ������� � ����
		fwrite(&p, sizeof(Point), 1, f);
		cout << "Success" << endl;
		//�������� �����
		fclose(f);
	}*/

	/*FILE* f;
	Point p;
	//�������� �����
	fopen_s(&f, "point.bin", "rb");
	//���� ������
	if (f) {
		//������ ������� �� �����
		fread(&p, sizeof(Point), 1, f);
		cout << "Success" << endl;
		//�������� �����
		fclose(f);
	}*/

	/*PassportInfo pi("AE", 65432);
	Person p("First name 1", "Last name 1", 2, &pi);

	FILE* f;

	//�������� �����
	fopen_s(&f, "person.bin", "wb");
	//���� ������
	if (f) {
		//������ ������� � ����
		fwrite(&p, sizeof(Person), 1, f);
		cout << "Success" << endl;
		//�������� �����
		fclose(f);
	}*/

	FILE* f;
	Person p;
	//�������� �����
	fopen_s(&f, "person.bin", "rb");
	//���� ������
	if (f) {
		//������ ������� �� �����
		fread(&p, sizeof(Person), 1, f);
		cout << "Success" << endl;
		//�������� �����
		fclose(f);
	}

	return 0;
}