#include "DateConverter.h"

std::string DateConverter::dateToString(const Date& date)
{
    std::string result = std::string() + std::string("/" + date.month) + std::string("/" + date.day);
    return date.year + "/" + date.month + std::string("/" + date.day);
}
