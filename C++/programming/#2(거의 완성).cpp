#include <iostream>
using namespace std;

class Coin{
    int m_penny, m_nickel, m_dime, m_quarter;
    int m_dollar, m_cent;
public:
    Coin();
    Coin(int quarter, int dime, int nickel, int penny);
    Coin(int dollar, int cent);
    bool Set_Quarter(int quarter);
    bool Set_Dime(int dime);
    bool Set_Nickle(int nickel);
    bool Set_Penny(int penny);
    bool Set_Dollar(int dollar);
    bool Set_Cent(int cent);
    int Get_Penny();
    int Get_Nickle();
    int Get_Dime();
    int Get_Quarter();
    int Get_Dollar();
    int Get_Cent();
    void Exchange_Coin_To_Dollar();
    void Exchange_Dollar_To_Coin();
    void Print_Money();
};

Coin::Coin(){
    m_penny = m_nickel = m_dime = m_quarter = 1;
    m_dollar = 0;
    m_cent = 41;
}
Coin::Coin(int quarter, int dime, int nickel, int penny){
    m_penny = penny;
    m_nickel = nickel;
    m_dime = dime;
    m_quarter = quarter;
    Exchange_Coin_To_Dollar();
}
Coin::Coin(int dollar, int cent){
    m_dollar = dollar;
    m_cent = cent;
    Exchange_Dollar_To_Coin();
}

int Coin::Get_Penny(){
    return m_penny;
}
int Coin::Get_Nickle(){
    return m_nickel;
}
int Coin::Get_Dime(){
    return m_dime;
}
int Coin::Get_Quarter(){
    return m_quarter;
}
int Coin::Get_Dollar(){
    return m_dollar;
}
int Coin::Get_Cent(){
    return m_cent;
}

bool Coin::Set_Quarter(int quarter){
    if(quarter >= 0){
        m_quarter = quarter;
        return true;
    }else{
        return false;
    }
}
bool Coin::Set_Dime(int dime){
   if(dime >= 0){
        m_dime = dime;
        return true;
    }else{
        return false;
    }
}
bool Coin::Set_Nickle(int nickel){
   if(nickel >= 0){
        m_nickel = nickel;
        return true;
    }else{
        return false;
    }
}
bool Coin::Set_Penny(int penny){
   if(penny >= 0){
        m_penny = penny;
        return true;
    }else{
        return false;
    }
}
bool Coin::Set_Dollar(int dollar){
   if(dollar >= 0){
        m_dollar = dollar;
        return true;
    }else{
        return false;
    }
}
bool Coin::Set_Cent(int cent){
   if(cent >= 0){
        m_cent = cent;
        return true;
    }else{
        return false;
    }
}

void Coin::Exchange_Coin_To_Dollar(){
    int total = 0;
    total += m_quarter * 25;
    total += m_dime * 10;
    total += m_nickel * 5;
    total += m_penny;

    m_dollar /= 100;
    m_cent %= 100;
}
void Coin::Exchange_Dollar_To_Coin(){
    int total = 0;
    total += m_dollar * 100;
    total += m_cent;

    while(total > 0){
        if(total >= 25){
            m_quarter /= total;
            total -= m_quarter * 25;
        }else if(total >= 10){
            m_dime /= total;
            total -= m_dime * 10;
        }else if(total >= 5){
            m_nickel /= total;
            total -= m_nickel * 5;
        }else{
            m_penny /= total;
            total = 0;
        }
    }
}

void Coin::Print_Money(){
    cout << "코인의 갯수는 " << m_quarter << " 쿼러, " << m_dime << " 다임, " << m_nickel << " 니클, " << m_penny << " 페니 이고";
    cout << "달러로 환산하면 " << m_dollar << " 달러, " << m_cent << " 센트 입니다." << endl;
}

int main(){
    Coin ob1(4,5,2,6);
    Coin ob2(5,62);
    Coin ob3;

    ob1.Print_Money();
    ob2.Print_Money();
    ob3.Print_Money();

    ob1.Set_Quarter(7);
    ob1.Set_Nickle(23);
    ob1.Exchange_Coin_To_Dollar();

    cout << "코인의 갯수는 " << ob1.Get_Quarter() << " 쿼러, " << ob1.Get_Dime() << " 다임, " << ob1.Get_Nickle() << " 니클, " << ob1.Get_Penny() << " 페니 이고";
    cout << "달러로 환산하면 " << ob1.Get_Dollar() << " 달러, " << ob1.Get_Cent() << " 센트 입니다." << endl;

    ob2.Set_Dollar(2);
    ob2.Set_Cent(43);
    ob2.Exchange_Dollar_To_Coin();
    ob2.Print_Money();

    cout << "동전의 개수를 순서대로 입력하세요(쿼러, 다임, 니클, 페니) : ";
    while(1){
        int quarter, dime, nickel, penny;
        cin >> quarter >> dime >> nickel >> penny;
        if(ob3.Set_Quarter(quarter) >= 0 && ob3.Set_Dime(dime) >= 0 && ob3.Set_Nickle(nickel) >= 0 && ob3.Set_Penny(penny) != 0){
            break;
        }else{
            cout << "입력된 값 중에 음수가 있습니다." << endl;
            cout << "0 이상의 값으로 동전의 개수를 순서대로 입력하세요(쿼러, 다임, 니클, 페니 : " << endl;
        }
    }

    ob3.Exchange_Coin_To_Dollar();
    ob3.Print_Money();

    return 0;
}
