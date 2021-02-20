#include "Date.h"

Date::Date()
{
	year = month = day = 0;
}

Date::Date(int year, int month, int day)
	: month(month), year(year), day(day)
{
}
