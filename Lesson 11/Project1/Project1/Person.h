#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;

class Person
{
	string firstName;
	string lastName;
	int age;

public:
	Person();
	Person(string firstName, string lastName, int age);

	int getAge() const;
	string getFirstName() const;
	string getLastName() const;

	friend ostream& operator <<(ostream& os, const Person& obj);
};

