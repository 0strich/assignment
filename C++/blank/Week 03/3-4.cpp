#include <iostream>
using namespace std;

int main(){
    int arr[5];
    int i;
    int *p;

    for(i=0; i<5; i++){
        arr[i] = i*3;
    }

    p = &arr[0];

    for(i=0; i<5; i++){
        cout << arr[i] << ' ';
    }

    cout << endl;

    for(i=0; i<5; i++){
        arr[i] = *p+2;
        p += 1;
    }

    for(i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
