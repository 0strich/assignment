#include <iostream>
using namespace std;

class myclass{
    int n;
public:
    myclass(int i);
    void Set_n(int i);
    int Get_n();
};

myclass::myclass(int i){n = i;}
void myclass::Set_n(int i){n = i;}
int myclass::Get_n(){return n;}

void Sqr_It_Address(myclass *ob){
    ob->Set_n(ob->Get_n() * ob->Get_n());
    cout << "ob 복사본의 n 값은 " << ob->Get_n() << endl;
}
void Sqr_It_Reference(myclass &ob){
    ob.Set_n(ob.Get_n() * ob.Get_n());
    cout << "ob 복사본의 n 값은 " << ob.Get_n() << endl;
}
void Sqr_It_Value(myclass ob){
    ob.Set_n(ob.Get_n() * ob.Get_n());
    cout << "ob 복사본의 n 값은 " << ob.Get_n() << endl;
}

int main(){
    myclass ob(10);

    Sqr_It_Value(ob);
    cout << "값 인도 후 ob의 n 값은" << ob.Get_n() << endl;

    Sqr_It_Address(&ob);
    cout << "값 인도 후 ob의 n 값은" << ob.Get_n() << endl;

    ob.Set_n(10);
    Sqr_It_Reference(ob);
    cout << "값 인도 후 ob의 n 값은" << ob.Get_n() << endl;

    return 0;
}
