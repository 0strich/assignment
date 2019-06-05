#include <iostream>
#include <string>
using namespace std;

class Student{
	static int m_count;
	string m_gender;
	int m_age;
public:
	Student(string gender = "NONE", int age = 20);
	~Student();
	Student(const Student &s);
	int Get_Age() {return m_age;}
	string Get_Gender() {return m_gender;}
};
void Show_Student(Student s, string str);

int main(){
	Student ob1("남학생", 22);
	Student ob2("여학생", 21);
	Student ob3;
	cout << "\n----- Main() 함수 시작 -----\n";

	cout << "ob1 객체의 성별은 (" << ob1.Get_Gender() << ")입니다.\n";
	Show_Student(ob1, "ob1");

	cout << "ob2 객체의 성별은 (" << ob2.Get_Gender() << ")입니다.\n";
	Show_Student(ob2, "ob2");

	Show_Student(ob3, "ob3");

	cout << "\n----- Main() 함수 종료 -----\n";

	return 0;
}

Student::Student(string gender, int age){
	m_count++;
	m_gender = gender;
	m_age = age;
	cout << m_gender << " 출력, 순번 : " << m_count << endl;
}
Student::Student(const Student &s){
	m_count++;
	m_gender = s.m_gender;
	m_age = s.m_age;
	cout << m_gender << "복사생성자 호출됨, 순번 : " << m_count << endl;
}
Student::~Student(){
	m_count--;
	cout << m_gender << " 소멸 : 남은 학생 수 : " << m_count << endl;
}
void Show_Student(Student s, string str){
	cout << "\n--- Show_Student() 함수 시작 ---\n";
	cout << str << " 객체는 (" << s.Get_Gender() << ") 입니다." << endl;
	cout << "나이는 " << s.Get_Age() << "살 입니다.\n";
	cout << "\n--- Show_Student() 함수 종료 ---\n";
}
int Student::m_count = 0;
