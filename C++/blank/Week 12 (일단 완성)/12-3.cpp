#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(9);
    v.push_back(2);

    cout << "원래 데이터 : ";
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;

    v[0] = 13;
    v.at(2) = 4;

    cout << "값 변경 후 데이터 : ";
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;

    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++){
        int n = *it;
        n = n * 2;
        *it = n;
    }

    cout << "2 곱한 후 데이터 : ";
    for(it = v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << endl;

    cout << "소팅 후 데이터 : ";
    sort(v.begin(), v.end());
    for(it = v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
