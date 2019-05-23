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
	Person(string name, int age, SEX sex);
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

class Man : public Person {
public:
	Man() {}
	Man(string name, int age);
	void Print();
};

Man::Man(string name, int age) : Person(name, age, m_sex) {}

void Man::Print() {
	Person::Print();
	cout << ", 성별 : M \n";
}

class Woman : public Person {
public:
	Woman() {}
	Woman(string name, int age);
	void Print();
};

Woman::Woman(string name, int age) : Person(name, age, m_sex) {}

void Woman::Print() {
	Person::Print();
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
