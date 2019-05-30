#include <iostream>
using namespace std;

class myclass{
    int data;
public:
    myclass(int x);
    int get_data();
};

myclass::myclass(int x){
    data = x;
}

int myclass::get_data(){
    return data;
}

int main(){
    myclass ob(120);
    myclass *p;
    p = &ob;

    cout << ob.get_data() << endl;
    cout << p->get_data() << endl;

    return 0;
}
