#include "MainApplication.h"
#include "AdminApplication.h"

void MainApplication::menu()
{
	std::cout << "[1] User application" << std::endl
		<< "[2] Action 2" << std::endl
		<< "[3] Action 3" << std::endl;
}

//void MainApplication::start()
//{
//	int action;
//	while (true) {
//		system("cls");
//		menu();
//		std::cin >> action;
//		runMenuAction(action);
//	}
//}

void MainApplication::runMenuAction(int action)
{
	switch (action) {
	case 1: {
		active = new UserApplication();
		active->start();
		break;
	}
	case 2: {
		active = new AdminApplication();
		active->start();
		break;
	}
	}
}
