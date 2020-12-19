#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "x = " << p.x << " y = " << p.y;
	return os;
}
