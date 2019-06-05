#include <iostream>
using namespace std;

int main(){
    int arr[5];
    int i;
    int *p;

    for(i=0; i<5; i++)
        arr[i] = 3 * i;

    p = &arr[0];
    for(i=0; i<5; i++)
        cout << *(p + i) << ' ';
    cout << endl;

    for(i=0; i<5; i++){
        *p += 2;
        p++;
    }

    for(i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << "\n";

    return 0;
}
