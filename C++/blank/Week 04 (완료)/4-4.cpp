#include <iostream>
#include <string>
using namespace std;

class Dogs{
    int m_year;
    string m_breed;
public:
    Dogs(string breed, int year);
    int Get_Yaar();
    void Print_Breed();
};

Dogs::Dogs(string breed, int year){
    m_breed = breed;
    m_year = year;
}

inline int Dogs::Get_Yaar(){
    return m_year;
}

inline void Dogs::Print_Breed(){
    cout << "품종 : " << m_breed << endl;
}

int main(){
    Dogs toto("저먼 세퍼드", 4), chito("그레이 하운드", 2);

    toto.Print_Breed();
    cout << "저먼 세퍼드의 나이 = " << toto.Get_Yaar() << endl;

    chito.Print_Breed();
    cout << "그레이 하운드의 나이 = " << chito.Get_Yaar() << endl;

    return 0;
}
