#include "Student.h"

Student::Student()
{
	firstName = lastName = middleName = "Unknown";
}

Student::Student(string firstName, string lastName, string middleName, Date birth)
	: firstName(firstName),
	lastName(lastName),
	middleName(middleName),
	birth(birth)
{
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

string Student::getMiddleName() const
{
	return middleName;
}
Date Student::getBirth() const {
	return birth;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	std::cout << "------------------------" << endl;
	cout << "Last name : " << obj.getLastName() << endl
		<< "First name : " << obj.getFirstName() << endl
		<< "Middle name: " << obj.getMiddleName() << endl
		<< "Birth      : " << obj.birth.year << "/" << obj.birth.month << "/" << obj.birth.day
		<< endl;
	cout << "------------------------" << endl;
	return os;
}
