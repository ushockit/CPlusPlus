#pragma once
#include <iostream>
#include <string>

class Address
{
	enum StreetType {
		Avenue,		//��������
		Lane,		//��������
		Boulevard	//�������
	};
	std::string street;		//�������� �����
	int houseNum;			//����� ����
	int roomNum;			//����� ��������
	StreetType type;		//��� �����
public:
};