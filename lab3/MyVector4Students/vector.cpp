#include "vector.h"
#include<iostream>
Vector::Vector(int capacity)
{
    setSize(0);
    this->data = new Fraction[capacity];
    setCapcity(capacity);
}

Vector::~Vector()
{
    delete [] this->data;
}

Vector::Vector(const Vector &copyVector)
{
    setSize(copyVector.size());
    setCapcity(copyVector.capacity());


    data = new Fraction[copyVector.capacity()];
    for(int i = 0; i < copyVector.size(); i++)
     this->data[i] = copyVector.data[i];
}

Vector::Vector(Vector &&carryVector)
{
    setSize(carryVector.size());
    setCapcity(carryVector.capacity());
    setData(carryVector.getData());

    carryVector.setData(nullptr);
    carryVector.setCapcity(0);
    carryVector.setSize(0);
//    data = new Fraction[carryVector.capacity()];
//
//    data = new Fraction[sizeVec];
//    for(int i = 0; i < sizeVec; i++)
//        this->data[i] = arr[i];
}

Vector& Vector::operator=(const Vector &copyVector)
{
    if(&copyVector != this)
    {
        this->setSize(copyVector.size());
        this->setCapcity(copyVector.capacity());
        delete [] data;




        data = new Fraction[capacityF];
        for(int i=0; i<capacityF; i++)
            data[i] = copyVector.data[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector &&diffVector)
{
    if(&diffVector != this)
    {
        delete [] data;

        sizeF = diffVector.size();
        capacityF = diffVector.capacity();
        data = diffVector.data;

        diffVector.data = nullptr;
    }
    return *this;
}

void Vector::push_back(Fraction fraction)
{
    if(this->capacity() > this->size())
    {
        data[sizeF] = fraction;
        sizeF++;
    } else
    {
        data = (Fraction *)realloc(data, capacityF);
        sizeF++;
        capacityF++;
    }
}

Fraction Vector::operator[](size_t i)
{
    if(i >= this->size())throw std::out_of_range("Denominator must not be 0.");
    return data[i];
}
