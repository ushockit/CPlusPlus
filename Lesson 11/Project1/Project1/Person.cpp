#include "Person.h"

Person::Person()
{
	firstName = lastName = "";
	age = 0;
}

Person::Person(string firstName, string lastName, int age)
	: firstName(firstName), lastName(lastName), age(age) {}

int Person::getAge() const
{
	return age;
}

string Person::getFirstName() const
{
	return firstName;
}

string Person::getLastName() const
{
	return lastName;
}

ostream& operator<<(ostream& os, const Person& obj)
{
	cout << obj.lastName << " " << obj.firstName << " " << obj.age << "y.o.";
	return os;
}
