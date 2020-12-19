#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum AccType {
	Admin = 1,
	User = 2,
	None = 0
};

class Car {
	char mark[30];
	char model[30];
public:
	Car() {
		strcpy_s(mark, "Unknown");
		strcpy_s(model, "Unknown");
	}
	Car(const char* mark, const char* model) {
		strcpy_s(this->mark, mark);
		strcpy_s(this->model, model);
	}

	const char* getMark() const {
		return mark;
	}
	const char* getModel() const {
		return model;
	}

	friend ostream& operator << (ostream& os, const Car& car);
};
ostream& operator << (ostream& os, const Car& car) {
	os << car.mark << " " << car.model << endl;
	return os;
}



//Singleton(��������) - ������������ �������� �������� ������� � ������������ ����������
/*
	1. ��������� �����������
	2. ����������� ����������, ������� ��������� �� ������ �����
	3. ����������� �����, ������� ������������� ������ � ����������� ����������
*/
class CarsStorage {
	static CarsStorage* instance;

	int capacity;		//����� ������
	int count;			//����������� ������
	Car* cars;			//������ �����

	CarsStorage() {
		capacity = 10;
		count = 0;
		cars = new Car[capacity];
	}
	CarsStorage(int capacity) {
		this->capacity = capacity;
		count = 0;
		cars = new Car[capacity];
	}
public:
	
	~CarsStorage() {
		//������� ���������� ������ ��� ������
		delete[] cars;
	}

	void addNewCar(const Car& car) {
		//TODO: car validation

		if (count < capacity) {
			cars[count++] = car;
		}
	}

	const Car* findByMark(char* mark) {
		for (int i = 0; i < count; i++)
		{
			//����� ���������
			if (_strcmpi(cars[i].getMark(), mark) == 0) {
				return &cars[i];
			}
		}
		return nullptr;
	}
	const Car* getCars() const {
		return cars;
	}
	int getCountCars() const {
		return count;
	}

	static CarsStorage* getInstance() {
		if (instance == nullptr) {
			instance = new CarsStorage();
		}
		return instance;
	}
};
//����������� ����������� ����������
CarsStorage* CarsStorage::instance = nullptr;

class UserApplication {
	CarsStorage* carsStorage = CarsStorage::getInstance();

	void menu() {
		cout << "[1] �������� ��� ������" << endl;
		cout << "[2] ����� ������ �� �����" << endl;
		cout << "[3] �����" << endl;
	}
public:
	void start() {
		int action;
		while (true) {
			system("cls");

			menu();
			cin >> action;

			if (!runAction(action)) {
				break;
			}

			Sleep(1000);
		}
	}
	bool runAction(int action) {
		switch (action) {
		case 1:
			showAllCars();
			break;
		case 2:

			break;
		case 3:
			return false;
			break;
		}
		return true;
	}
	void showAllCars() {
		cout << "������ ���� �����" << endl;

		const Car* cars = carsStorage->getCars();
		int countCars = carsStorage->getCountCars();

		if (countCars > 0) {
			for (int i = 0; i < countCars; i++)
			{
				cout << cars[i] << endl;
			}
		}
		else {
			cout << "������ ����� ����" << endl;
		}
	}
};

class AdminApplication {
	CarsStorage* carsStorage = CarsStorage::getInstance();

	void menu() {
		cout << "[1] �������� ����� ������" << endl;
		cout << "[2] �������������� ������" << endl;
		cout << "[3] �������� ������" << endl;
		cout << "[4] �����" << endl;
	}
	void addNewCar() {
		cin.ignore();
		cout << "���������� ����� ������" << endl;

		char mark[30];
		char model[30];

		//���� ������ � ����������
		cout << "Mark: ";
		cin.getline(mark, 30);

		cout << "Model: ";
		cin.getline(model, 30);

		Car newCar(mark, model);

		//���������� ������ � ���������
		carsStorage->addNewCar(newCar);
	}
	bool runAction(int action) {
		switch (action) {
		case 1:
			addNewCar();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			return false;
			break;
		}
		return true;
	}
public:
	void start() {
		int action;
		while (true) {
			system("cls");

			menu();
			cin >> action;
			if (!runAction(action)) {
				break;
			}

			Sleep(1000);
		}
	}
	
};

class Application {
	enum MenuAction {
		Login = 1,
		Exit = 2
	};
private:
	void menu() {
		cout << "[1] ����" << endl;
		cout << "[2] �����" << endl;
	}
	void runAction(int menuAction) {
		switch (menuAction) {
		case Login: {
			//����
			AccType type = login();

			switch (type) {
			case Admin: {
				AdminApplication adminApp;
				adminApp.start();
				break;
			}
			case User: {
				UserApplication userApp;
				userApp.start();
				break;
			}
			}
			break;
		}
		case Exit:
			exit(0);
			break;
		}
	}

	
	
	//void editCar() {

	//}
	//void removeCar() {

	//}
	//void findByMark() {
	//	cout << "����� ������ �� �����" << endl;
	//	//����� ���� ��� ������
	//	char srchMark[] = "mark 1";

	//	//��������� ������
	//	const Car* srchCar = carsStorage.findByMark(srchMark);

	//	//������ �������
	//	if (srchCar != nullptr) {
	//		cout << *srchCar << endl;
	//	}
	//	else {
	//		cout << "������ �� �������" << endl;
	//	}
	//}

	AccType login() {

		int type;

		cout << "[1] Admin" << endl;
		cout << "[2] User" << endl;
		cin >> type;

		return type == Admin ? Admin : User;
	}
public:
	Application() {

	}
	void start() {
		int action;
		while (true) {
			system("cls");

			//����������� �������� ����
			menu();
			//���� �������� � ����
			cin >> action;
			runAction(action);

			Sleep(2500);
		}
	}
};

enum Color {
	Red = 1,
	Blue = 2,
	Green = 3
};

int main() {
	//���. ��������� ����������
	system("color 0F");
	setlocale(LC_ALL, "rus");


	Application app;
	app.start();


	return 0;
}