#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	enum SEX {male, female};
protected:
	string m_name;
	int m_age;
	SEX m_sex;
public:
	Person();
	Person( string name, int age, SEX sex);
	void Print();
};

Person::Person(string name, int age, SEX sex) {
	m_name = name;
	m_age = age;
	m_sex = sex;
}

void Person::Print() {
	cout << "이름 : " << m_name << ", " << "나이 : " << m_age;
}

// Person 클래스로부터 public 으로 상속 받음
class Man : public Person {                                 // 빈칸
public:
	Man() {}
	Man( string name, int age);
	void Print();
};

// 파생 클래스 생성자 함수의 인수를 단순히 기본 클래스에게 전달만 한다. 전달하는
// 세 번째 인수에 주의 할 것
Man::Man( string name, int age) : Person(name, age, m_sex) {}        // 빈칸

void Man::Print() {
	Person::Print();                                // 빈칸
	cout << ", 성별 : M \n";
}

// Person 클래스로부터 public 으로 상속 받음
class Woman : public Person {                       // 빈칸
public:
	Woman() {}
	Woman( string name, int age);
	void Print();
};

// 파생 클래스 생성자 함수의 인수를 단순히 기본 클래스에게 전달만 한다. 전달하는
// 세 번쨰 인수에 주의 할 것
Woman::Woman( string name, int age) : Person(name, age, m_sex) {}    // 빈칸

void Woman::Print() {
	Person::Print();            // 상속받은 Print 함수 사용 (빈칸)
	cout << ", 성별 : F \n";
}

int main() {
	Man m1("정우성", 44);
	m1.Print();
	Woman w1("이효리", 38);
	w1.Print();
    system("PAUSE");
	return 0;
}
