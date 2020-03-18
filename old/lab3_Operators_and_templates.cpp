#include <vector>
#include <iostream>
#include <array>
#include <cmath>

using namespace std;

//////////////////////////////////////////////////////////
///       Zaimplementuj szablon klasy Vector3<T>       ///
/// z podstawowymi operatorami i ponizszymi operacjami ///
//////////////////////////////////////////////////////////

template<typename Scalar>
class Vector3{
    public:
        Vector3(Scalar _x=0, Scalar _y=0, Scalar _z=0) : x{_x}, z{_z}, y{_y}{}
        Vector3(const Vector3& other){
            Vector3(other.x, other.y, other.z);
        }
        Vector3 operator + (const Vector3& other) const{
            return Vector3(other.x + this->x, other.x + this->, other.z + this->z);
        } 
        

    private:
        Scalar x,y,z;
        
};

friend operator << (std::ostream& out, const Vector3& vector){
    cout<< "[" << vector.x << "," << vector.y << "," << vector.z <<"]";
    return out;

    }

int dot(const array<int,3>& left, const array<int,3>& right) {
    return left[0] * right[0] + left[1] *  right[1] + left[2] * right[2];
}

array<int,3> cross(const array<int,3>& left, const array<int,3>& right) {
    int i = left[1] * right[2] - left[2] * right[1];
    int j = left[0] * right[2] - left[2] * right[0];
    int k = left[0] * right[1] - left[1] * right[0];
    return {i,j,k};
}


void normalize(array<int,3>& vector) {
    int sum = vector[0] * vector[0] + vector[1] *  vector[1] + vector[2] * vector[2];
    if(sum != 0) {
        vector[0] /= sqrt(sum);
        vector[1] /= sqrt(sum);
        vector[2] /= sqrt(sum);
    }
}


void print(const array<int,3>& vector) {
    cout << "[" << vector[0] << ", " << vector[1] << ", " << vector[2] << "]";
}


int main() {
    Vector3<int> v(5,6,8);
    Vector3<int> vx2 = v + v;

    std::cout << v << std ::endl;
    std::cout << vx2 << "kot" <<std ::endl;
}
//friend operator nie korzysta z thisa