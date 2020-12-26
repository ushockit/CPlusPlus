#pragma once
#include <Windows.h>
class ColorConfig
{
public:
	static enum ConsoleColor {
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
	static void setColor(int foreground) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		/*���� ����� ���� - �����. ���� ����� ������ - ������*/
		//system("color F0");
		/*���� �������� - ������. ���� ���� - �����-�����*/
		SetConsoleTextAttribute(hConsole, (WORD)((DarkGray << 4) | foreground));
	}
};

