#pragma once
#include <iostream>
#include <string>

class Address
{
	enum StreetType {
		Avenue,		//проспект
		Lane,		//переулок
		Boulevard	//бульвар
	};
	std::string street;		//название улицы
	int houseNum;			//номер дома
	int roomNum;			//номер квартиры
	StreetType type;		//тип улицы
public:
};