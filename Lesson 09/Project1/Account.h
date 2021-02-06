#pragma once
#include <iostream>
#include <string>

class Account
{
	std::string login;
	std::string password;
public:
	Account() {
		login = password = "";
	}
	Account(std::string login, std::string password) {
		this->login = login;
		this->password = password;
	}
	std::string getLogin() const {
		return login;
	}
	std::string getPassword() const {
		return password;
	}
};

