#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
    int x;
    int y;
    int xTo;
    int yTo;
public:
    Rectangle(int x, int y, int xTo, int yTo);
    ~Rectangle(){};
    int getX() const{return this->x;}
    int getXTo() const {return this->xTo;}
    int getY() const {return this->y;}
    int getYTo() const {return this->yTo;}
    virtual bool isIn(int x, int y) const ;

};
} // namespace Shapes

#endif // RECTANGLE_H
