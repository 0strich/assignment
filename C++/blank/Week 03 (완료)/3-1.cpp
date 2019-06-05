#include <iostream>
using namespace std;

const int Arrsize = 20;

int main(){
    cout << "거꾸로 출력할 단어를 입력하세요 : ";
    char word[Arrsize];
    cin >> word;

    for(int i=strlen(word); i >= 0; i--)
        cout << word[i];
    cout << endl;

    return 0;
}
