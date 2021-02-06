#include <iostream>
#include <fstream>

using namespace std;

class Person {
	char firstName[30];
	char lastName[30];
	int age;
public:
	Person() {
		firstName[0] = lastName[0] = '\0';
		age = 0;
	}
	Person(const char* firstName, const char* lastName, int age) {
		this->age = age;
		strcpy_s(this->firstName, firstName);
		strcpy_s(this->lastName, lastName);
	}
	friend ostream& operator << (ostream& os, const Person& obj);
	friend istream& operator >> (istream& is, Person& obj);
};
ostream& operator << (ostream& os, const Person& obj) {
	os << obj.firstName << " " << obj.lastName << " " << obj.age;
	return os;
}
istream& operator >> (istream& is, Person& obj) {
	is >> obj.firstName;
	is >> obj.lastName;
	is >> obj.age;
	return is;
}

int main() {
	/*Person person;
	cin >> person;
	cout << person << endl;*/
	//cerr << "Some error" << endl;
	//clog << "Some error" << endl;

	//ofstream
	//ifstream
	//fstream

	/*ofstream out("demo.bin", ios::out | ios::binary);

	//файл открыт
	if (out.is_open()) {

		const char* str = "Hello world";
		out.write(str, strlen(str));

		//закрытие файла
		out.close();
	}*/

	/*ifstream in("demo.bin", ios::in | ios::binary);

	if (in.is_open()) {

		char buff[100];
		//in.read(buff, 100);
		while (!in.eof()) {
			in.getline(buff, 100);
			cout << buff;
		}
		in.close();
	}*/


	/*Person person("Vasya", "Pupkin", 23);
	ofstream out("person.bin", ios::out | ios::binary);

	if (out.is_open()) {

		out << person;

		out.close();
	}*/

	/*Person person;
	ifstream in("person.bin", ios::in | ios::binary);

	if (in.is_open()) {

		in >> person;
		cout << person << endl;

		in.close();
	}*/

	/*int size = 3;
	Person* people = new Person[size];

	people[0] = Person("Masha", "Ivanova", 20);
	people[1] = Person("Vasya", "Pupkin", 35);
	people[2] = Person("Petya", "Sidorov", 29);

	ofstream out("people.bin", ios::out | ios::binary);

	if (out.is_open()) {

		out << size << endl;
		for (int i = 0; i < size; i++)
		{
			out << people[i];
		}
		cout << "Success" << endl;
		out.close();
	}*/

	/*ifstream in("people.bin", ios::in | ios::binary);

	if (in.is_open()) {

		int size;
		in >> size;

		Person* people = new Person[size];
		for (int i = 0; i < size; i++)
		{
			Person p;
			in >> p;
			people[i] = p;
			cout << p << endl;
		}

		in.close();
	}*/

	/*const char* source = "Project1.rar";
	const char* destination = "../Project1.rar";

	ifstream in(source, ios::binary);
	ofstream out(destination, ios::binary);

	if (in.is_open() && out.is_open()) {
		out << in.rdbuf();
		cout << "Success" << endl;
		in.close();
		out.close();
	}*/
	

	return 0;
}