#include <iostream>
using namespace std;

class coord{
    int m_x, m_y;
public:
    coord() {m_x = 0; m_y = 0;}
    coord(int x, int y) {m_x = x; m_y = y;}
    friend ostream& operator<<(ostream &os, coord ob);
    friend istream& operator>>(istream &is, coord &ob);
};

ostream& operator<<(ostream &os, coord ob){
    os << ob.m_x << ',' << ob.m_y << '\n';
    return os;
}
istream& operator>>(istream &is , coord &ob){
    cout << "Enter Coordinates : ";
    is >> ob.m_x >> ob.m_y;
    return is;
}

int main(){
    coord ob1(1,1), ob2(10,23);
    cout << ob1 << ob2;

    cin >> ob1 >> ob2;
    cout << ob1 << ob2;

    return 0;
}
