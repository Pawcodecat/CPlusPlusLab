#include <iostream>
#include <vector>
#include<array>

// Przepisz ponizszy kod uzywajac archetypów enum i struct 
enum plec{
    Kobieta,
    Mezczyzna
}
struct PESEL{
    PESEL() = default;
    PESEL(const std::string& s)
      {
            int i=0;
            for(char c: maybe_pesel){
                pesel.pesel_digits[i++] = c- '0';
            }
            is_correct=pesel.iscorrect();
        }

    std::array<char,11>pesel_digits;
    bool iscorrect(){
        const static std::array<int,10>multipliers;
        int sum = 0;
        for(int i=0; i<11; i++){
            sum+=pesel_digits[i]*multipliers[i];
        }
        return pesel_digits[11] == (sum % 10);
    }
};

enum A{};
struct B{};
struct Person{
    PESEL pesel;
   // plec plec;
    std :: string imie;
    std :: string nazwisko;
    Plec pleckobieta() const{
        return pesel.pesel_digits[9] % 2 == 0; 
    }
};
class Vector3 {
    int x,y,z;
};




using namespace std;

int main () {

    int peopleCount;
    cin >> peopleCount;
    vector<Person> people,
    // vector<int> pesele;
    // vector<char> plci;
    // vector<string> imiona;
    // vector<string> nazwiska;

    for (int i = 0; i < peopleCount; i++){
        Person person
        std::string maybe_pesel;
        PESEL pesel;
        bool is_correct = true;

        cin>>maybe_pesel;
        if(maybe_pesel.size()!=11){
            is_correct = false;
        }
        else{
            person.pesel = PESEL(maybe_pesel)
            is 
        }
        cin>>person.imie;
        cin>>person.nazwisko;   
        if(is_correct){
            people.push_back<person>;
        }   

        // char tmpplec;
        // if(tmpplec ='k')
        // {
        //     person.plec = Kobieta;
        // }
        // else
        // {
        //     person.plec = Mezczyzna;
        // }
        
     

        // pesele.emplace_back();
        // plci.emplace_back();
        // imiona.emplace_back();
        // nazwiska.emplace_back();
        // cin >> pesele.back();
        // cin >> plci.back();
        // cin >> imiona.back();
        // cin >> nazwiska.back();
    }

    // for (int i = 0; i < peopleCount; i++){
    //     if(plci[i] == 'K') 
    //        // std::cout << "Pani " << imiona[i][0] << ". " << nazwiska[i] << std::endl;
    //        std::cout<<"Pani"<<people[i].imie<<" "<<people[0].nazwisko<<"Pesel"<<people[i].pesel<<" Plec: "<<people[i].plec;
    // }

}


//RAII pobranie zasobu jest inicjalizacją
//o.disconnect
//o.connect
//o.cleanup