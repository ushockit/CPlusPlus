#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Person
{
private:
	std::string firstName;
	std::string lastName;
	int age;
public:
	Person(std::string first_name, std::string last_name, int age)
		: firstName(std::move(first_name)),
		  lastName(std::move(last_name)),
		  age(age)
	{
	}
	std::string getFirstName() const
	{
		return firstName;
	}

	std::string getLastName() const
	{
		return lastName;
	}

	int getAge() const
	{
		return age;
	}
};

typedef std::vector<std::vector<Person>> PeopleMatrix;

int main()
{
	/*std::shared_ptr<Person> ptr(new Person("Vasya", "Pupkin", 20));
	std::shared_ptr<Person> ptr2;
	ptr2 = ptr;
	
	if (ptr2)
	{
		std::cout << ptr.get()->getFirstName() << std::endl;
		std::cout << ptr2.get()->getFirstName() << std::endl;
	}*/

	//std::vector<std::vector<Person>> arr;
	//PeopleMatrix arr;

	std::unique_ptr<int> ptr(new int(10));
	std::unique_ptr<int> ptr2;

	//ptr2 = ptr;		//Нельзя

	return 0;
}
