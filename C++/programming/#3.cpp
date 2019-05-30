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
    Employee(string name, string position, int year);
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

string Employee::Get_Name(){
    return m_name;
}
string Employee::Get_Position(){
    return m_position;
}
int Employee::Get_Year(){
    return m_year;
}
int Employee::Get_Salary(){
    return m_gross_salary;
}
void Employee::Set_Name(string name){
    m_name = name;
}
bool Employee::Set_Position(string position){
    if(position == "사원")
        m_position_level = 0;
    else if(position = "대리")
        m_position_level = 1;
    else if(position = "과장")
        m_position_level = 2;
    else if(position = "차장")
        m_position_level = 3;
    else if(position = "부장")
        m_position_level = 4;
    else if(position = "이사")
        m_position_level = 5;
    else:
        m_position_level = -1;

    if(m_position_level < 0){
        return false;
    }else{
        m_position = m_position_level;
        return true;
    }
}
void Employee::Set_Year(int year){
    m_year = year;
}
Employee::Employee(){
    m_basic_salary[0] = 2000000;
    for(int i=1; i<6; i++){
        m_basic_salary[i] = m_basic_salary[i-1] + 500000;
    }
    m_allowance = 100000;
}
// 미완성
Employee::Employee(string name, string position, int year){
    m_name = name;
    m_position = Set_Position(position);
    m_year = year;
    m_basic_salary[0] = 2000000;

    for(int i=1; i<6; i++){
        m_basic_salary[i] = m_basic_salary[i-1] + 500000;
    }
    m_allowance = 100000;
}

void Employee::Compute_Salary(){
    if(m_year >= 5 && m_year < 10)
        m_gross_salary = m-m_basic_salary[m_position_level] + 50000 * m_year + m_allowance;
    if(m_year >= 10 && m_year < 20)
        m_gross_salary = m-m_basic_salary[m_position_level] + 50000 * m_year + m_allowance;
    if(m_year >= 20 && m_year < 30)
        m_gross_salary = m-m_basic_salary[m_position_level] + 50000 * m_year + m_allowance;
    if(m_year >= 30)
        m_gross_salary = m-m_basic_salary[m_position_level] + 50000 * m_year + m_allowance;
}

void Employee::Print_Result(){
    cout << m_name << ' ' << m_position << "의 총 근무 연수는 " << m_year << "년 입니다" << endl;
    cout << m_name << ' ' << m_position << "의 총 봉급은 " << m_gross_salary << "원 입니다" << endl;
}

int main(){
    Employee ob1("홍길동", "과장", 17);
    Employee ob2("장길산", "부장", 23);
    Employee ob3("임꺽정", "이사", 34);
    Employee *ob4 = new Employee;



    delete Employee;
    return 0;
}
