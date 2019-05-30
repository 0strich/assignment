#include <iostream>
using namespace std;

class Point{
	int m_x, m_y;
public:
	// 매개변수가 있는 생성자 함수 (두 매개변수의 디폴트 인수로 0을 사용)
	Point(int x=0, int y=0);
	void Get_XY(int &a, int &b);
	Point operator+(Point ob2);
	Point operator=(Point ob2);
};

Point::Point(int x, int y){
	m_x = x;
	m_y = y;
}

void Point::Get_XY(int &a, int &b){
	a = m_x;
	b = m_y;
}

// Point 클래스의 비공개 변수들을 더하는 기능을 가지도록 + 연산자를 중복
Point Point::operator+(Point ob2){
	Point temp;
	temp.m_x = this->m_x + ob2.m_x;
	temp.m_y = this->m_y + ob2.m_y;
	return temp;
}

// Point 클래스의 비공개 변수들을 치환하는 기능을 가지도록 = 연산자를 중복
Point Point::operator=(Point ob2){
	m_x = ob2.m_x;
	m_y = ob2.m_y;
	return ob2;
}

int main(){
	Point ob1(5,4), ob2(4,7), ob3, ob4;
	int x,y;

	ob3 = ob1 + ob2;		// ob1 과 ob2를 더해서 ob3 에 치환
	ob3.Get_XY(x, y);		// Get_XY() 함수를 이용하여 ob3의 x,y 값을 얻어온다
	cout << "ob4 의 x 는 " << x << " y 는 " << y << "\n";

	ob4 = ob3 = ob2 = ob1; 	// ob1 을 ob2에 ob2 를 ob3에 ob3 을 ob4 에 연속적으로 치환 (한 줄로 구현)
	ob4.Get_XY(x, y);				// Get_XY() 함수를 이용하여 ob4 의 x,y 값을 얻어온다
	cout << "ob4 의 x 는 " << x << " y 는 " << y << "\n";

	return 0;
}
