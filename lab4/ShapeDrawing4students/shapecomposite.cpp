#include "shapecomposite.h"
#include <iostream>

Shapes::ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                                       Shapes::ShapeOperation operation) {

   this->shape1 = shape1;
   this->shape2 = shape2;
   this->operation = operation;
}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
    switch(operation)
    {
        case ShapeOperation::INTERSECTION:
            return shape1->isIn(x, y) && shape2->isIn(x, y);
        case ShapeOperation::SUM:
            return shape1->isIn(x, y) || shape2->isIn(x, y);
        case ShapeOperation::DIFFERENCE:
            return shape1->isIn(x, y) && !shape2->isIn(x, y);
        default:
            throw std::invalid_argument("operation should be: INTERSECTION or SUM or DIFFERENCE");
    }
}
