#include "Leaf.h"

Leaf::Leaf(int value)
{
	this->value = value;
	parent = left = right = nullptr;
}
