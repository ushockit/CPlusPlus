#include <iostream>

using namespace std;

/*
class Person {
protected:
	string firstName;
	string lastName;
public:
	Person(string firstName, string lastName)
		: firstName(firstName), lastName(lastName) {}
	virtual void run() {
		cout << "Run" << endl;
		cout << lastName << " " << firstName << endl;
	}
};

class Sportsmen : public Person {
protected:
	double speed;
public:
	Sportsmen(string firstName, string lastName, double speed) :
		Person(firstName, lastName)
	{
		this->speed = speed;
	}
	void run() override {
		Person::run();
		cout << "Sportsmen running" << endl;
		cout << "Speed = " << speed << endl;
	}
};
*/

/*
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
	virtual ~Person() {
		cout << "~Person()" << endl;
		system("pause");
	}
};

class Student : public Person {
	//string firstName;
	//string lastName;
	//int age;
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
	virtual ~Student() {
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
	virtual ~Aspirant() {
		cout << "~Aspirant()" << endl;
		system("pause");
	}
	void show() {
		//вызов метода базовго класса
		Student::show();
		cout << "Diplom: " << diplomName << endl;
	}
};
*/


class Weapon {
protected:
	string name;
	double weight;
public:
	Weapon(string name) {
		this->name = name;
	}
	void show() {
		cout << name << endl;
	}
	//чисто виртуальная функция
	virtual void attack() = 0;
};

class KnifeWeapon : public Weapon {
public:
	KnifeWeapon(string name) : Weapon(name) {

	}

	void attack() override {
		cout << "Knife attack" << endl;
	}
};

class Weapon1 : public Weapon {
public:
	Weapon1(string name) : Weapon(name) {

	}

	void attack() override {
		cout << "Weapon 1 attack" << endl;
	}
};

class Weapon2 : public Weapon {
public:
	Weapon2(string name) : Weapon(name) {

	}
	
	void attack() override {
		cout << "Weapon 2 attack" << endl;
	}
};

class Player {
	Weapon* weapon;
public:
	Player() {
		weapon = new KnifeWeapon("Some knife");
	}
	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}
	void show() {
		weapon->show();
	}

	void attack() {
		weapon->attack();
	}
};


int main() {
	/*Person person("Vasya", "Pupkin");
	Sportsmen sportsmen("Petya", "Ivanov", 25.3);

	//person.run();
	//sportsmen.run();

	Person* ptr = &sportsmen;
	ptr->run();*/

	/*Person** people = new Person * [5];

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
	*/

	Player player;

	player.setWeapon(new Weapon1("Some weapon 1"));
	//player.show();

	player.attack();

	player.setWeapon(new Weapon2("Some weapon 2"));
	player.attack();





	return 0;
}