#include <iostream>
#include <string>

using namespace std;

class Person {
	string firstName;
	string lastName;
	int age;
public:
	Person(string firstName, string lastName, int age) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
	}
	friend ostream& operator << (ostream& os, const Person& obj);
};
ostream& operator << (ostream& os, const Person& obj) {
	os << obj.firstName << endl;
	os << obj.lastName << endl;
	os << obj.age << endl;
	return os;
}

int main() {

	/*string str = "Hello world";
	string str2 = "!!!";
	string str3 = str + str2;
	str3 += ")))";

	//cout << str3 << endl;

	char buff[50];

	strcpy_s(buff, str3.c_str());
	cout << buff << endl;*/

	string str = "Hello world";
	str.append("!!!");

	cout << str << endl;
	cout << str.at(0) << endl;
	cout << str[0] << endl;
	//������� ������
	//str.clear();

	//��������� ����� (������ strcmp)
	/*int res = str.compare("hello world!!!");
	cout << res << endl;*/

	//��������� ������ �� �������� �����
	/*string res = str.erase(5);

	cout << str << endl;
	cout << res << endl;*/

	//�������� �������� � �������� ���������
	/*str.erase(2, 6);
	cout << str << endl;*/

	/*string res;
	//����������� ������������ ������������������ ��������
	res.assign(str, 1, 5);
	cout << res << endl;*/

	//����� ���������
	/*size_t res = str.find("!ello");

	//��������� �������
	if (res != string::npos) {
		cout << "Success" << endl;
	}
	else {
		cout << "Not found" << endl;
	}*/

	//������� � �������� �������
	//������� � ������
	/*str.insert(0, "Hi!");
	str.insert(5, "@@");
	cout << str << endl;*/

	//�������� ������ �� �������
	//str.clear();
	/*if (str.empty()) {
		cout << "String is empty" << endl;
	}
	else {
		cout << "String has symbs" << endl;
	}*/
	
	//������ �����
	/*string s1 = "Hello";
	string s2 = "World";

	s1.swap(s2);

	cout << s1 << endl
		<< s2 << endl;*/

	//��������� ���������
	/*string sub = str.substr(0, 5);

	cout << str << endl
		<< sub << endl;*/

	/*Person p("Vasya", "Pupkin", 20);
	cout << p << endl;*/


	return 0;
}