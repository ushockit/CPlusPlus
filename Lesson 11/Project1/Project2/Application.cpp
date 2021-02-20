#include "Application.h"

void Application::menu()
{
	cout << "[1] Print all students" << endl
		<< "[2] Search student by last name" << endl
		<< "[3] Print students by date" << endl;
}

void Application::runMenuAction(int action)
{
	auto func = menuActions[(MenuAction)action];
	if (func != nullptr) {
		func();
	}
}


Application::Application()
{
	menuActions.insert(std::make_pair(MenuAction::PrintAllStudents, []() {
		//список студентов
		std::vector<Student> students = StudentsStorage::getInstance()->getStudents();

		//алгоритм вывода списка студентов
		std::for_each(students.begin(), students.end(), [](const Student& student) {
			cout << student;
		});
	}));
	menuActions.insert(std::make_pair(MenuAction::SearchByLastName, []() {
		string lastName;

		cout << "Last name: ";
		cin >> lastName;

		//список студентов
		StudentsStorage* storage = StudentsStorage::getInstance();
		Student* student = storage->searchStudentByLastName(lastName);
		if (student != nullptr) {
			cout << *student;
		}
		else {
			cout << "Student was not found" << endl;
		}
	}));
}

void Application::run()
{
	//выбранное действие в меню
	int action;
	//цикл приложения
	while (true) {
		system("cls");
		menu();
		cin >> action;
		runMenuAction(action);

		_getch();
	}
}

void Application::config()
{
	system("color 0f");
}
