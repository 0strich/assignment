#include <iostream>
#include <string>
using namespace std;

class Point{
	int m_x, m_y;
	double Length(){
		return (sqrt(double(m_x * m_x + m_y * m_y)));
	}
public:
	____________{  // 매개변수가 두 개인 생성자 함수
		m_x = x;
		m_y = y;
	}
	void ShowPoint(){ 
		______ void ShowMe(Point &p); 		// friend 함수로 정의
	}
};

void Point::ShowPoint(Point &p){
	// Length 함수 호출
	cout << "객체 멤버함수로 (" << m_x  << ';' << m_y << ')' << "   Length = " << ________ << endl; 
}
void ShowMe(Point &p){			// friend 함수 구현(객체의 내용 출력)
	// length 함수 호출
	cou << "프렌드 함수로 (" << p.m_x << ';' << p.m_y << ')' << "    Length = " << ________ << endl;
}


int main(){
	________;	// Point 클래스로 obj 라는 객체 선언 (초기 값 4,5)
	________;	// 객체 멤버 함수를 사용하여 객체의 내용을 출력
	________;	// 프렌드 함수를 사용하여 객체의 내용을 출력

	return 0;
}

