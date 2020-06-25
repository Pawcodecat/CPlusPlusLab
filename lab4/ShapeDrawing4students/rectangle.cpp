#include "rectangle.h"
#include <iostream>


Shapes::Rectangle::Rectangle(int x, int y, int xTo, int yTo)
{
    this->x = x;
    this->y = y;
    this->xTo = xTo;
    this->yTo = yTo;
}

bool Shapes::Rectangle::isIn(int x, int y) const {
    return x >= this->x && x <= this -> xTo && y >= this->y && y <= this->yTo;
}



