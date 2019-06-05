#include <iostream>
using namespace std;

int main(){
    int a,b;

    try{
        cin >> a >> b;

        if(a < 0) throw a;
        else if(b < 0) throw b;

        cout << "a = " << a << ", b = " << b << endl;
    }catch(int thrown){
        cout << "[error]" << endl;
        cout << "You Need To Input Only Plus Integer" << endl;
        cout << "you input this : " << thrown << endl;
    }

    return 0;
}
