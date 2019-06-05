#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

ostream &setup(ostream &stream){
    cout << setw(10);
    cout << setprecision(6);
    cout << setfill('#');
    return stream;
}

istream &getpass(istream &stream){
    cout << "\007";
    cout << "Enter password : ";
    return stream;
}

int main(){
    string pw;
    do{
        cin >> getpass >> pw;
    }while(pw != "password");

    cout << "Login complete\n";
    cout << setup << 123.123456 << "\n";


    return 0;
}
