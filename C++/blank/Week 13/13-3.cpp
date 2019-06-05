#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    cout << setprecision(4);
    cout <<  "      x   sqrt(x)   x^2\n";
    for(int x = 2; x <= 10; x++){
        cout << setw(7);
        cout << x << ' ';
        cout << setw(7);
        cout << sqrt(x);
        cout << setw(7);
        cout << x*x << ' ' << endl;
    }

    return 0;
}
