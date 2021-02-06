#include <iostream>

using namespace std;

class Weapon {
protected:
	string name;
	double weight;
public:
	Weapon(string name) {
		this->name = name;
	}
	void show() {
		cout << name << endl;
	}
};

class KnifeWeapon : public Weapon {
public:
	KnifeWeapon(string name) : Weapon(name) {

	}
};

class Weapon1 : public Weapon {
public:
	Weapon1(string name) : Weapon(name) {

	}
};

class Weapon2 : public Weapon {
public:
	Weapon2() : Weapon(name) {

	}
};

class Player {
	Weapon* weapon;
public:
	Player() {
		weapon = new KnifeWeapon("Some knife");
	}
	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}
	void show() {
		weapon->show();
	}
};


int main() {

	Player player;

	player.show();
	player.setWeapon(new Weapon1("Some weapon 1"));
	player.show();

	return 0;
}