#include "Application.h"

void Application::start()
{
	int action;
	while (true) {
		system("cls");
		menu();
		std::cin >> action;
		runMenuAction(action);
	}
}