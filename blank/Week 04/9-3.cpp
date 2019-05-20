#include <iostream>
using namespace std;

class Point{
	int m_x, m_y;
public:
	// 매개변수가 있는 생성자 함수 (두 매개변수의 디폴트 인수로 0을 사용)
	Point(int x = 0, int y = 0);
	void Get_XY(int &a, int &b);
	friend Point operator+(Point ob1, Point ob2);
	friend Point operator+(Point ob1, int i);
	friend Point operator+(int i, Point ob1);
};

Point::Point(int x,int y){
	m_x = x;
	m_y = y;
}

void Point::Get_XY(int &a, int &b){
	a = m_x;
	b = m_y;
}

// Point 클래스의 객체들을 더하는 기능을 가지도록 +를 중복한다 (객체 + 객체)
Point operator+(Point ob1, Point ob2){
	Point temp;
	temp.m_x = ob1.m_x + ob2.m_x;
	temp.m_y = ob1.m_y + ob2.m_y;
	return temp;
}

// Point 클래스의 객체에 int 변수(값)을 더하는 기능을 가지도록 + 를 중복한다 (객체 + int)
Point operator+(Point ob1, int i){
	Point temp;
	temp.m_x = ob1.m_x + i;
	temp.m_y = ob1.m_y + i;
	return temp;
}

// Point 클래스의 객체에 int 변수(값)을 더하는 기능을 가지도록 + 를 중복한다 (int + 객체)
Point  operator+(int i, Point ob1){
	Point temp;
	temp.m_x = i + ob1.m_x;
	temp.m_y = i + ob1.m_y;
	return temp;
}

int main(){
	Point ob1(5,4), ob2(4,7), ob3, ob4, ob5;
	int x, y;
	ob3 = ob1 + ob2;	// ob1 과 ob2 를 더해서 ob3 에 치환한다
	ob3.Get_XY(x, y);	// Get_XY() 함수를 이용하여 ob3 의 x, y 값을 얻어온다
	cout << "ob3 의 x는 " << x << " y 는 " << y << "\n";

	ob4 = ob3 + 6;	// ob3 에 6을 더해 ob4 에 치환한다 (객체 + int)
	ob4.Get_XY(x, y);	// Get_XY() 함수를 이용하여 ob4 의 x, y 값을 얻어온다
	cout << "ob4 의 x는 " << x << " y 는 " << y << "\n";

	ob5 = ob3 + 3;	// ob3에 3을 더해 ob5에 치환한다 (int + 객체))
	ob5.Get_XY(x, y);	// Get_XY() 함수를 이용하여 ob5 의 x, y 값을 얻어온다
	cout << "ob5 의 x는 " << x << " y 는 " << y << "\n";

	return 0;
}
