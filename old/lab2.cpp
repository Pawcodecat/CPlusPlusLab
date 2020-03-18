#include<iostream>
#include<vector>
using namespace std;
int identity(a) {return a}
int cube(a){return a*a*a}
int sumfromTo(int a, int b, std :: int f){
    int sum=o;
    for (int i = a; i < b; i++)
    {
        sum+=f(i);
    }
    return sum;
}

int main(){
    std::vector<int> a;
    for(int i=0; i<100; i++){
    a.push_back(i);
    cout<<a.pop_back(i)<<endl;
    
    }
//any_of(v.begin(),v.end,f)
cout<<sumfromto(0,10,identity)<<endl;
std :: sort(v.begin(), v.end())
// std :: sort(v.begin(), v.end(),f) f ma zwracać bool'a

auto f = [](int a){return a*2};


[](){}();
[]<>(){}(); c++20

sort(v.b(),v.e(),[](int a,int b){return a < b})

template<typename T>
T min(T a, T b){
    if(a<b){
        return a;
    }
    return b;
}
min<int>(10,8);
min<float>(10.32,3.14158)
min<vector<int>>
min<string>

template<typename T, typename U, typename R=T>
 R min(T a, U b){
    if(a<b){
        return a;
    }
    return b;
}
min<int,float>(10,8.5)


std :: variant 
std :: optioanal
std :: pair
        struct {
            optional<T>
            optional<U>
        };

bool foo(int a, int b)
bool(int,int)

template <typename T>
vector <T> filter(vector<T> v, function<bool<(T)> f){
    std::vector<T> dest;
    std::copy_if(source.begin(), source.end(), std::back_inserter(dest), [&](int T) { return f(T); });
    return dest;
}

template <typename T, typename U>
Vector<U>map(Vector<T> v, function<U(T)>)      kolejny etap to zastąpienie vectora template(array,list)
    return 0;

}