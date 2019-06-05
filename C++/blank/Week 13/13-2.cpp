#include <iostream>
using namespace std;

int main(){
    cout.put('H');
    cout.put('i');
    cout.put(33);
    cout.put('\n');

    cout.put('C').put('+').put('+');
    cout << endl;

    cout << "문자열을 입력하세요 : ";
    char str[80];
    cin.getline(str, 80);
    cout << "입력한 문자의 개수는 : " << cin.gcount() - 1 << endl;
    cout.write(str, 6);
    cout << endl;

    return 0;
}
