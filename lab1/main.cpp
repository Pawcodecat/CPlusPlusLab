#include <iostream>

using namespace std;
class Array{
private:
    int data[10];
    string name = "table";
    static const int startValueFirst = 49;
    static constexpr  int startValueSecond =81;
protected:
    static int numberOfArray;

public:
    Array();

    Array(int *tab,int size);

    int getArray(int index) const;

    void setArray(int index, int value);

    void print() const;

     static int numberOfArrays(){
        return numberOfArray;
    }

   void scanf(istream& is);

   void printf(ostream& os);

   string getName(){
        return this->name;
    }

    int getStartValueFirst(){
        return startValueFirst;
    }

    int getStartValueSecond(){
        return startValueSecond;
    }

};

int Array::getArray(int index) const{
    if(index < 0 && index >10){
        string exception ="Index should be in range [0, 9]";
        throw exception;
    }
    return this->data[index];

}

void Array::setArray(int index, int value){
    if(index < 0 && index >10){
        string exception ="Index should be in range [0, 9]";
        throw exception;
    }
    this->data[index] = value;
}

void Array::print() const{
    for(int i=0; i<10; i++)
        cout<<"data["<<i<<"]="<<this->data[i]<<"  ";
    cout<<"\n";
}


void Array::scanf(istream& is) {
    int n;
    for (int i = 0; i < 10; i++) {
        is >> n;
        this->data[i] = n;
    }
}

void Array::printf(ostream& os){

    for(int i= 0; i<10; i++) {
        os<<this->data[i]<<" ";
    }
}

Array::Array(){
    numberOfArray++;
    for(int i=0; i<10; i++){
        data[i] = 0;
    }
}

Array::Array(int *tab,int size){
    numberOfArray++;
    for(int i=0; i<size && i<10; i++)
        data[i] = tab[i];
    for(int i=size; i<10; i++)
        data[i] = 0;
}

int Array::numberOfArray = -1;
int main() {
    Array arr = Array();
    arr.print();
    int tab[10] = {0,1,2,3,4,5,6,7};
    Array arr2 = Array(tab,8);
    int tab3[6] = {0,1,2,3,4,5};
    Array arr3 = Array(tab3,6);
    arr2.print();
    cout<<arr2.getArray(4);
    cout<<"\n";
    arr2.setArray(4, 15);
    cout<<arr2.getArray(4);
    cout<<"\n";
    arr2.scanf(cin);
    arr2.printf(cout);
    cout<<"\n";
    cout<<Array().numberOfArrays();
    cout<<"\n";
    cout<<arr2.getName();
    cout<<"\n";
    cout<<arr2.getStartValueFirst();
    cout<<"\n";
    cout<<arr2.getStartValueSecond();
    cout<<"\n";
    return 0;
}
