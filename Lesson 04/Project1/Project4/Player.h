#pragma once
#include <iostream>
#include "Position.h"

class Game;
class Player
{
	char nickname[20];
	Position position;
public:
	Player(const char* nickname) {
		strcpy_s(this->nickname, nickname);
	}

	void toLeft() {
		position.x--;
	}
	void toRight() {
		position.x++;
	}
	void toUp() {
		position.y--;
	}
	void toDown() {
		position.y++;
	}

	friend class Game;
};

