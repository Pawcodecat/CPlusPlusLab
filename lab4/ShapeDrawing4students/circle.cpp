#include <cmath>
#include <math.h>
#include "circle.h"


Shapes::Circle::Circle(int x, int y, int radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
}

bool Shapes::Circle::isIn(int x, int y) const {
    return sqrt(pow((this->x - x), 2) + pow((this->y - y), 2)) <= this->radius;
}