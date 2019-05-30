#include <iostream>
using namespace std;

class Person{
protected:
    string m_name;
    int m_age;
public:
    Person(){m_age = 0;}
    Person(string name, int age);
    void Print();
    virtual bool IsMale() = 0;
    virtual char GetCode() = 0;
};

Person::Person(string name, int age){
    m_name = name;
    m_age = age;
}

void Person::Print(){
    cout << "이름 : " << m_name << ", 나이 : " << m_age << ", 성별 : " << GetCode();
}

class Man : public Person{
public:
    Man(){}
    Man(string name, int age) : Person(name, age){}
    bool IsMale();
    char GetCode();
};

bool Man::IsMale(){
    return true;
}
char Man::GetCode(){
    return 'M';
}

class Woman : public Person{
public:
    Woman() {}
    Woman(string name, int age) : Person(name, age){}
    bool IsMale();
    char GetCode();
};

bool Woman::IsMale(){
    return false;
}
char Woman::GetCode(){
    return 'F';
}

int main(){
    Person *arr[] = {
        new Man("정우성", 45),
        new Woman("한가인", 36),
        new Man("장철수", 32),
        new Man("최민수", 56),
        new Woman("이효리", 49)};

    int size = sizeof(arr) / sizeof(arr[0]);
    int manCount = 0;

    for(int i=0; i<size; i++){
        arr[i]->Print();
        cout << "\n";
        if(arr[i]->GetCode() == 'M')
            manCount++;
    }

    cout << "총인원 남자 : " << manCount << "명, 여자 : " << size - manCount << "명\n";

    return 0;
}
