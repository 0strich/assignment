#include <iostream>
#include <string>
using namespace std;

class Student{
	static int m_count;							// 정적 멤버 변수 m_count 를 int형으로 선언
	string m_gender;
	int m_age;
public:
	// 매개변수들의 디폴트 인수 값을 gender 는 NONE, age 는 20으로 세팅
	Student(string gender="NONE", int age=20);
	~Student();									// 소멸자 함수
	Student(const Student &s);					// 복사 생성자 함수
	int Get_Age() { return m_age; }
	string Get_Gender() { return m_gender; }
};

Student::Student(string gender, int age){
	m_count++;
	m_gender = gender;
	m_age = age;
	cout << m_gender << "출석, 순번 : " << m_count << endl;
}

Student::Student(const Student &s){
	m_count++;
	m_gender = s.m_gender;
	m_age = s.m_age;
	cout << m_gender <<  "복사 생성자 호출됨, 순번 : " << m_count << endl;
}

Student::~Student(){
	m_count--;
	cout << m_gender << " 소멸 : 남은 학생 수 : " << m_count << endl;
}

void Show_Student(Student s, string str){
	cout << "\n--- Show_Student() 함수 시작 ---\n";
	// ob1 의 객체의 성별 출력
	cout << str << "객체는 (" << s.Get_Gender() << ")입니다.\n";
	// ob2 의 객체의 성별 출력
	cout << "나이는 " << s.Get_Gender() << "살 입니다.\n";
	cout << "--- Show_Student() 함수 종료 ---\n\n";
}

int Student::m_count = 0;// 정적 멤버 변수(m_count) 메모리 할당(0으로 초기화)

int main(){
	Student ob1("남학생", 22);						// Student 클래스로 ob1 객체 생성(초기화 "남학생", 22)
	Student ob2("여학생", 21);						// Student 클래스로 ob2 객체 생성(초기화 "여학생", 21)
	Student ob3;						// Student 클래스로 ob3 객체 생성(초기화 없음)
	cout << "\n------ Main() 함수 시작 ------\n";
	// ob1 객체의 성별 출력
	cout << "ob1 객체의 성별은 (" << ob1.Get_Gender() << ")입니다.\n";
	Show_Student(ob1, "ob1");

	// ob2 객체의 성별 출력
	cout << "ob2 객체의 성별은 (" << ob2.Get_Gender() << ")입니다\n";
	Show_Student(ob2, "ob2");

	Show_Student(ob3, "ob3");

	cout << "------ main() 함수 끝 ------\n";

	return 0;
}
