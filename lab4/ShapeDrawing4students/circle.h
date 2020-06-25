#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
class Circle : public Shape
{
    int x;
    int y;
    int radius;
public:
    Circle(int x, int y, int radius);
    ~Circle(){};
    int getX() const {return this->x;};
    int getY() const {return this->y;};
    int getRadius() const {return this->radius;};
    virtual bool isIn(int x, int y) const ;
};
} // namespace Shapes

#endif // CIRCLE_H
