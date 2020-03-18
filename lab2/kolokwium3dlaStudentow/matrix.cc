#include <iostream>
using namespace std;
#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix(){
    for(int i = 0; i < size; i++){
        for(int j =0; j < size; j++){
            this->matrixFromClass[i][j] = 0;
        }
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &matrix){
    for(int i = 0; i < size; i++){
        for(int j =0; j< size; j++){
            matrixFromClass[i][j] = matrix.matrixFromClass[i][j];
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix[size][size]){
    for(int i = 0; i < size; i++){
        for(int j =0; j< size; j++){
           this->matrixFromClass[i][j] = matrix[i][j];
        }
    }
}

MatrixElement TwoDimensionMatrix::get(int i,int j) const
{
    if(i >= 0 && i < size && j >= 0 && j< size)
        return this->matrixFromClass[i][j];

}

ostream & operator<< (ostream &exit,const TwoDimensionMatrix &m) {
    exit << "m[0][0]= " << m.get(0, 0) << " m[0][1]= " << m.get(0, 1) <<" m[1][0]= " << m.get(1, 0)<<" m[1][1]= " << m.get(1, 1) <<endl;
    return exit;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2)
{
    MatrixElement matrix[matrix1.getSize()][matrix1.getSize()];
     for(int i = 0; i < matrix1.getSize(); i++){
            for(int j =0; j< matrix1.getSize(); j++){
                matrix[i][j] = (int)matrix1.get(i, j) + (int)matrix2.get(i, j);
            }
     }
     TwoDimensionMatrix resultMatrix(matrix);
     return resultMatrix;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number){
    for(int i = 0; i < this->getSize(); i++){
        for(int j =0; j< this->getSize(); j++){
            this->matrixFromClass[i][j] = (this->matrixFromClass[i][j])*number;
        }
    }

}


TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix1) const
{
    MatrixElement matrix2[TwoDimensionMatrix::getSize()][TwoDimensionMatrix::getSize()];
    for(int i = 0; i < this->getSize(); i++){
        for(int j =0; j< this->getSize(); j++){
            matrix2[i][j] = (this->matrixFromClass[i][j]) && matrix1.matrixFromClass[i][j];
        }
    }
    return matrix2;
}

MatrixElement* TwoDimensionMatrix::operator[](size_t i){
    return this->matrixFromClass[i];
}

TwoDimensionMatrix::operator size_t() const
{
    return size_t(TwoDimensionMatrix::getSize());
}