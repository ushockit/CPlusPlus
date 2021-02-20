#pragma once
#include <iostream>
#include <map>
#include "StudentsStorage.h"
#include <algorithm>
#include "Student.h"
#include "DateConverter.h"
#include <conio.h>


using std::cout;
using std::endl;
using std::cin;

class Application
{
	enum class MenuAction {
		PrintAllStudents = 1,
		SearchByLastName
	};
public:
	Application();
	void run();
	//какие-то настройки приложения
	void config();
private:
	//действия меню
	std::map<MenuAction, void(*)()> menuActions;

	void menu();
	void runMenuAction(int action);
	void printStudents();
};

