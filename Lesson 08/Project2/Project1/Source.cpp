#include <iostream>
#include <string>

using namespace std;


/*
	Person (базовый класс или класс родитель)
	Student - дочерний класс
	Worker - дочерний класс

	protected
*/

class Person {
protected:
	string firstName;
	string lastName;
	int age;
	double weight;
public:
	Person() {
		firstName = lastName = "";
		age = 0;
		cout << "Person()" << endl;
	}
	Person(string firstName, string lastName, int age) :
		firstName(firstName), lastName(lastName), age(age) {
		cout << "Person(params)" << endl;
	}

	void show() {
		cout << firstName << " " << lastName << " " << age << "y.o." << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
		system("pause");
	}
};

class Student : public Person {
	/*string firstName;
	string lastName;
	int age;*/
protected:
	string specialization;
	int course;
public:
	Student() {
		specialization = "";
		course = 1;
		cout << "Student()" << endl;
	}
	Student(string firstName, string lastName, int age, string specialization, int course)
		: Person(firstName, lastName, age) {
		this->specialization = specialization;
		this->course = course;
		cout << "Student(params)" << endl;
	}
	~Student() {
		cout << "~Student()" << endl;
		system("pause");
	}

	void show() {
		//вызов метода базовго класса
		Person::show();
		cout << "Specialization: " << specialization << " Course: " << course << endl;
	}
};

class Aspirant : public Student {
	string diplomName;
public:
	Aspirant() {
		diplomName = "";
		cout << "Aspirant()" << endl;
	}
	Aspirant(string firstName, string lastName,
		int age, string specialization, int course,
		string diplomName) : Student(firstName, lastName, age, specialization, course) {
		this->diplomName = diplomName;
		cout << "Aspirant(params)" << endl;
	}
	~Aspirant() {
		cout << "~Aspirant()" << endl;
		system("pause");
	}
	void show() {
		//вызов метода базовго класса
		Student::show();
		cout << "Diplom: " << diplomName << endl;
	}
};

class Vehicle {
protected:
	double volume;
	int year;
public:
};

class Cyborg : Person, Vehicle {
public:
	Cyborg() : Person(), Vehicle() {
		this->weight = 10.5;
	}
};

template<typename T>
class Point2D {
protected:
	T x;
	T y;
public:
	Point2D(T x, T y) : x(x), y(y) {}
};

template<typename T>
class Point3D : public Point2D<T> {
	T z;
public:
	Point3D(T x, T y, T z) : Point2D(x, y) {
		this->z = z;
	}
};


int main() {

	Person** people = new Person * [5];

	people[0] = new Student("Vasya", "Pupkin", 25, "Specialization 1", 2);
	people[1] = new Aspirant("Petya", "Ivanov", 36, "Specialization 2", 5, "Diplom 1");

	for (int i = 0; i < 2; i++) {
		people[i]->show();
	}

	//Student* st = (Student*)people[0];

	for (int i = 0; i < 2; i++) {
		delete people[i];
	}
	delete[] people;

	Point3D<double> point(10, 10, -1);



	return 0;
}