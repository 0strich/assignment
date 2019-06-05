#include <iostream>
using namespace std;

void Input_Data(int *money, int *type, int *num);
int Compute_Total(int type, int num);
char Check_Money(int total, int *money);
void Print_Result(char selection, int total, int money, int type, int num);

int main(){
    int money, type, num, total;
    char selection;

    do{
        cout << "==========================================================" << endl;
        cout << " 1.생수 : 500원   2.사이다 : 800원    3.옥수수차 : 1200원" << endl;
        cout << "==========================================================" << endl;

        Input_Data(&money, &type, &num);
        total = Compute_Total(type, num);
        selection = Check_Money(total, &money);
        Print_Result(selection, total, money, type, num);

        cout << "\n음료수를 더 뽑겠습니까? (Y/N) : ";
        cin >> selection;

        while(selection != 'Y' && selection != 'y' && selection != 'N' && selection != 'n'){
            cout << "오직 Y, y, N, n 만 입력하시오. : ";
            cin >> selection;
        }
    }while(selection == 'Y' || selection == 'y');

    return 0;
}

void Input_Data(int *money, int *type, int *num){
    cout << "돈을 넣어 주세요 : ";
    cin >> *money;
    cout << "음료 선택 및 수량 : ";
    cin >> *type >> *num;
}

int Compute_Total(int type, int num){
    switch(type){
        case 1: return 500 * num; break;
        case 2: return 800 * num; break;
        case 3: return 1200 * num; break;
        default: return -1; break;
    }
}

char Check_Money(int total, int *money){
    char selection = 'Y';
    int add_money;

    while(*money < total){
        if(*money < total){
            cout << "금액이 " << total - *money << "원 부족합니다. 돈을 더 투입하시겠습니까? (Y/N) ";
            cin >> selection;
            while(selection != 'Y' && selection != 'y' && selection != 'N' && selection != 'n'){
                cout << "오직 Y, y, N, n 만 입력하시오. : ";
                cin >> selection;
            }
            if(selection == 'Y' || selection == 'y'){
                cout << "추가 투입금 : ";
                cin >> add_money;
                *money += add_money;
            }else{
                break;
            }
        }
    }
    return selection;
}

void Print_Result(char selection, int total, int money, int type, int num){
    string name;

    switch(type){
        case 1: name = "생수"; break;
        case 2: name = "사이다"; break;
        case 3: name = "옥수수차"; break;
        default: break;
    }

    if(selection == 'Y' || selection == 'y'){
        cout << "현재 금액 : " << money << "원 입니다.";
        cout << name << ' ' << num << "개와 잔돈 " << money - total << "원을 받으십시요." << endl;
    }else{
        cout << "투입하신 금액이 부족하여 판매가 취소되었습니다." << endl;
        cout << "투입하신 돈 " << money << "원을 받으십시요." << endl;
    }
}
