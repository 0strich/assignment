#include <iostream>
using namespace std;

class MyTime{
    int m_hour;
    int m_min;
public:
    MyTime(int min = 0);
    MyTime(int hour, int min);
    MyTime operator+(MyTime t);
    friend MyTime operator+(MyTime t, int min);
    MyTime operator-(int min);
    friend MyTime operator-(MyTime t1, MyTime t2);
    MyTime operator*(double k);
    friend MyTime operator*(double k, MyTime t);
    MyTime operator=(MyTime t);
    friend int operator>(MyTime t1, MyTime t2);
    void Print_Time(string obj);
    friend int Compute_Total_Mins(MyTime t);
    MyTime Make_Time_Object(int min);
};

int main(){

    return 0;
}

MyTime::MyTime(int mim){
    m_hour = min / 60;
    m_min= min % 60;
}
MyTime::MyTime(int hour, int min){
    if(min >= 60){
        m_hour = hour + min / 60;
        m_min = min % 60;
    }else{
        m_hour = hour;
        m_min = min;
    }
}
MyTime MyTime::operator+(MyTime t){
    m_hour =
}
MyTime operator+(MyTime t, int min)
