#include <iostream>
using namespace std;

class Employee{
    string m_name, m_position;
    int m_position_level;
    int m_year;
    int m_allowance;
    int m_basic_salary[6], m_gross_salary;
public:
    Employee();
    Employee(string name,string position, int year);
    void Set_Name(string name);
    bool Set_Position(string position);
    void Set_Year(int year);
    string Get_Name();
    string Get_Position();
    int Get_Year();
    int Get_Salary();
    int Compute_Salary();
    void Print_Result();
};

int main(){
    string name, position;
    int year;
    Employee ob[3] = {
        Employee("홍길동", "과장", 17),
        Employee("장길산", "부장", 23),
        Employee("임꺽정", "이사", 34)};
    Employee *ptr = new Employee;

    ptr = &ob[0];

    for(int i=0; i<3; i++){
        ptr->Compute_Salary();
        ptr->Print_Result();
        ptr++;
    }

    cout << "종업원의 이름을 입력하세요 : ";
    getline(cin, name);
    ptr->Set_Name(name);

    while(1){
        cout << "종업원의 직급을 입력하세요 : ";
        cin >> position;
        if(ptr->Set_Position(position) == false)
            cout << "** 에러 발생. 사원, 대리, 과장, 차장, 부장, 이사 중에서 입력하세요 **" << endl << endl;
        else
            break;
    }

    cout << "종업원의 근무 연수를 입력하세요 : ";
    cin >> year;
    ptr->Set_Year(year);

    cout << "\n" << ptr->Get_Name() << ' ' << ptr->Get_Position() << "의 총 근무 연수는 " << ptr->Get_Year() << "년 입니다." << endl;
    cout << ptr->Get_Name() << ' ' << ptr->Get_Position() << "의 봉급은 " << ptr->Get_Salary() << "원 입니다." << endl;

    return 0;
}

Employee::Employee(){
    m_basic_salary[0] = 2000000;
    m_allowance = 100000;
    for(int i=1; i<6; i++)
        m_basic_salary[i] = m_basic_salary[i-1] + 500000;
}
Employee::Employee(string name,string position, int year){
    Set_Name(name);
    Set_Position(position);
    Set_Year(year);

    m_basic_salary[0] = 2000000;
    m_allowance = 100000;
    for(int i=1; i<6; i++)
        m_basic_salary[i] = m_basic_salary[i-1] + 500000;
}
string Employee::Get_Name(){return m_name;}
string Employee::Get_Position(){return m_position;}
int Employee:: Get_Year(){return m_year;}
int Employee:: Get_Salary(){return m_gross_salary;}
void Employee::Set_Name(string name){
    m_name = name;
}
bool Employee::Set_Position(string position){
    if(position == "사원") m_position_level = 0;
    else if(position == "대리") m_position_level = 1;
    else if(position == "과장") m_position_level = 2;
    else if(position == "차장") m_position_level = 3;
    else if(position == "부장") m_position_level = 4;
    else if(position == "이사") m_position_level = 5;
    else m_position_level = -1;

    if(m_position_level >= 0) return true;
    else return false;
}
void Employee::Set_Year(int year){
    m_year = year;
}
int Employee::Compute_Salary(){
    if(m_year >= 5 && m_year < 10) m_allowance *= 5;
    else if(m_year >= 10 && m_year < 20) m_allowance *= 10;
    else if(m_year >= 20 && m_year < 30) m_allowance *= 20;
    else if(m_year >= 30) m_allowance *= 30;

    m_gross_salary = m_basic_salary[m_position_level] + 50000 * m_year + m_allowance;
    return m_gross_salary;
}
void Employee::Print_Result(){
    cout << m_name << ' ' << m_position << "의 총 근무 연수는 " << m_year << "년 입니다." << endl;
    cout << m_name << ' ' << m_position << "의 봉급은 " << m_gross_salary << "원 입니다." << endl << endl;
}
