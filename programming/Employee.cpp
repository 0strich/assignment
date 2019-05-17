#include <iostream>
#include <string>
using namespace std;

// Employee 클래스의 정의 및 구현
class Employee {
	protected:
	    string m_name;
	int m_payRate;
	float m_hoursWorked;
	public:
	    Employee();
	Employee(string name, int payRate, float hoursWorked);
	void Set_Name(string name);
	string Get_Name();
	void Set_PayRate(int payRate);
	int Get_PayRate();
	void Set_HoursWorked(float hoursWorked);
	float Get_HoursWorked();
	float Compute_Salary();
	void Print_Info();
};

// Manager 클래스의 정의 및 구현 (Employee 클래스로부터 상속받음) [파생클래스]
class Manager : public Employee {
	bool m_fullTime;
	public:
        Manager();
	Manager(string name, int payRate, float hoursWorked, bool fullTime);
	bool Get_FullTime();
	void Set_FullTime(bool fullTime);
	float Compute_Salary();
	void Print_Info();
};

// Employee 클래스의 매개변수 없는 생성자
Employee::Employee() {
	m_name = "NONE";
	m_payRate = 0;
	m_hoursWorked = 0.0;
}

// Employee 클래스의 매개변수 있는 생성자
Employee::Employee(string name, int payRate, float hoursWorked) {
	m_name = name;
	m_payRate = payRate;
	m_hoursWorked = hoursWorked;
}

// Set_ 으로 시작하는 접근자 함수 정의
void Employee::Set_Name(string name) {
	m_name = name;
}
void Employee::Set_PayRate(int payRate) {
	m_payRate = payRate;
}
void Employee::Set_HoursWorked(float hoursWorked) {
	m_hoursWorked = hoursWorked;
}

// Get_ 으로 시작하는 접근함수 정의
string Employee::Get_Name() {
	return m_name;
}
int Employee::Get_PayRate() {
	return m_payRate;
}
float Employee::Get_HoursWorked() {
	return m_hoursWorked;
}

// Compute_Salary 함수 정의
float Employee::Compute_Salary() {
	return m_payRate * m_hoursWorked;
}

// Print_Info 함수 정의
void Employee::Print_Info() {
	cout << "이름 : " << m_name << endl;
	cout << "시간당 급여 : " << m_payRate << "원\n";
	cout << "근무 시간 : " << m_hoursWorked << "시간\n";
	cout << "총급여 : " << Compute_Salary() << "원\n";
}

// Manager 클래스의 매개변수 없는 생성자
Manager::Manager() {
	m_fullTime = true;
}

// Manager 클래스의 매개변수 있는 생성자
Manager::Manager(string name, int payRate, float hoursWorked, bool fullTime)
: Employee(name, payRate, hoursWorked) {
	m_fullTime = fullTime;
}

// 접근자 함수인 Get_FullTime 과 Set_FullTime 정의
bool Manager::Get_FullTime() {
	return m_fullTime;
}
void Manager::Set_FullTime(bool fullTime) {
	m_fullTime = fullTime;
}

// Employee 클래스로부터 상속받은 Compute_Salary() 재정의
float Manager::Compute_Salary() {
	if(m_fullTime) {
		return (m_payRate*1.5) * 40;
	} else {
		return Employee::Compute_Salary();
	}
}

// Employee 클래스로부터 상속받은 Print_Info() 재정의
void Manager::Print_Info() {
	cout << "이름 : " << m_name << endl;
	cout << "시간당 급여 : " << m_payRate << "원\n";
	if(m_fullTime) {
		cout << "정규직 매니저" << endl;
		cout << "근무시간 40시간 고정" << endl;
		cout << "총급여 : " << Compute_Salary() << "원\n";
	} else {
		cout << "비정규직 매니저" << endl;
		cout << "총급여 : " << Employee::Compute_Salary() << "원\n";
	}
}

int main() {
	Employee emp("장길산", 8000, 32.0);
	Manager mng1("홍길동", 12000, 32.0, true);
	Manager mng2;

	cout << "<종업원>" << endl;
	emp.Print_Info();
	cout << "\n***** 종업원 PayRate 및 hours 변경 *****" << endl;
	emp.Set_PayRate(8500);
	emp.Set_HoursWorked(40.0);
	cout << "시간당 급여 : " << emp.Get_PayRate() << "원\n";
	cout << "근무 시간 : " << emp.Get_HoursWorked() << "시간\n";
	cout << "총급여 : " << emp.Compute_Salary() << "원\n\n";

	cout << "<매니저1>" << endl;
	mng1.Print_Info();
	cout << "\n***** 매니저 PayRate 및 hours 변경 *****" << endl;
	mng1.Set_PayRate(13500);
	mng1.Set_HoursWorked(35.0);
	cout << "시간당 급여 : " << mng1.Get_PayRate() << "원\n";
	cout << "총급여 : " << mng1.Compute_Salary() << "원\n\n";

	cout << "<매니저2>" << endl;
	mng2.Print_Info();
	cout << "\n***** 매니저 이름. PayRate 및 hours 변경 *****" << endl;
	mng2.Set_Name("박문수");
	mng2.Set_PayRate(12000);
	mng2.Set_HoursWorked(25.5);
	mng2.Set_FullTime(false);
	mng2.Print_Info();

    system("PAUSE");
	return 0;
}
