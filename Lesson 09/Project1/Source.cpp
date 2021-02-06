#include <iostream>
#include "DivisionByZeroException.h"
#include "IncorrectFieldException.h"
#include "AccountNotFoundException.h"
#include <string>
#include "PeopleStorage.h"

using namespace std;

int division(int a, int b) {
	if (b == 0) {
		//return 0;
		//генерирование исключительной ситуации
		//throw 0;
		throw new DivisionByZeroException();
	}
	return a / b;
}

void validate(string login, string password) {
	if (login.size() < 4) {
		throw new IncorrectFieldException("Login must be > 4");
	}
	if (password.size() < 6) {
		throw new IncorrectFieldException("Password must be > 6");
	}
}

void authenticate(string login, string password) {
	//поиск аккаунта
	const Account* acc = PeopleStorage::getInstance()->searchAccount(login, password);
	if (acc == nullptr) {
		throw new AccountNotFoundException("Account doesn`t exists");
	}
}

void start() {

}

int main() {
	// -= Исключительные ситуации =-
	/*
		Синтаксис (try/catch/throw)
		try {
			...потенционально опасный код, который может вызвать
			исключительную ситуацию
		}
		catch(тип исключительной ситуации) {
			
		}
		catch(...) {
		
		}
	*/
	int a = 10, b = 0, c;

	
	/*if (b == 0) {
		cout << "Division by zero" << endl;
	}
	else {
		c = a / b;
	}*/

	/*try {
		if (b == 0) {
			//throw 0;
			throw "Division by zero";
		}
		c = a / b;
	}
	catch (int val) {
		cout << "int" << endl;
		cout << "Division by zero" << endl;
	}
	catch (const char* msg) {
		cout << "const char*" << endl;
		cout << msg << endl;
	}*/


	/*try {
		c = division(a, b);
		cout << "c = " << c << endl;
	}
	//catch (int val) {
	//	cout << "Division by zero" << endl;
	//}
	catch (DivisionByZeroException* ex) {
		cout << ex->what() << endl;
	}*/


	string login, password;


	cout << "Login: ";
	cin >> login;

	cout << "Password: ";
	cin >> password;

	try {
		validate(login, password);
		authenticate(login, password);
		start();
		//TODO: Login in system
	}
	catch (IncorrectFieldException* ex) {
		cout << ex->what() << endl;
		//TODO: input login or password
	}
	catch (AccountNotFoundException* ex) {
		cout << ex->what() << endl;
		//TODO: register a new account
	}
	catch (...) {

	}



	return 0;
}