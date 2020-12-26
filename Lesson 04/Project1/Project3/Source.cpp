#include <iostream>

using namespace std;

template<typename T>
class Point2D {
	T x;
	T y;
public:
	Point2D(T x, T y) : x(x), y(y) {}

	void setX(T x);
	T getX() const;
};

int main() {

	Point2D<int> p(10, 20);
	Point2D<double> p2(10.3, 22.5);
	

	system("pause");
	return 0;
}

template<typename T>
void Point2D<T>::setX(T x)
{
	this->x = x;
}

template<typename T>
T Point2D<T>::getX() const
{
	return x;
}
