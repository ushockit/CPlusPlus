#pragma once
#include "Account.h"

class PeopleStorage
{
	static PeopleStorage* instance;
	Account* accounts;
	int count;
	int capacity;
	PeopleStorage() {
		capacity = 5;
		accounts = new Account[capacity];
		init();
	}
	void init() {
		addAccount("vasya", "123456");
		addAccount("petya", "pe_2020");
		addAccount("masha", "m_mas_ha");
	}
public:
	static PeopleStorage* getInstance() {
		if (instance == nullptr) {
			instance = new PeopleStorage();
		}
		return instance;
	}
	void addAccount(std::string login, std::string password) {
		accounts[count++] = Account(login, password);
	}
	const Account* searchAccount(std::string login, std::string password) {
		for (int i = 0; i < count; i++) {
			if (login == accounts[i].getLogin() &&
				password == accounts[i].getPassword()) {
				return &accounts[i];
			}
		}
		return nullptr;
	}
};

