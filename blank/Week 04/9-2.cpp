#include <iostream>
using namespace std;

class Point{
	int m_x, m_y;
public:
	// 매개변수가 있는 생성자 함수 (두 매개변수의 디폴트 인수로 0을 사용)
	___________________;
	void Get_xy(int &a, int &b);
	Point operator+(Point ob2);
	Point operator=(Point ob2);
};

Point:Point(int x, int y){
	m_x = x;
	m_y = y;
}

void Point::Get_XY(int &a, int &b){
	a = m_x;
	b = m_Y;
}

// Point 클래스의 비공개 변수들을 더하는 기능을 가지도록 + 연산자를 중복
___________________{
	Point temp;
	___________________;
	___________________;
	___________________;
}

// Point 클래스의 비공개 변수들을 치환하는 기능을 가지도록 = 연산자를 중복
___________________{
	___________________;
	___________________;
	___________________;
}

int main(){
	Point ob1(5,4), ob(4,7), ob3, ob4;
	int x,y;

	___________________;		// ob1 과 ob2를 더해서 ob3 에 치환
	___________________;		// Get_XY() 함수를 이용하여 ob3의 x,y 값을 얻어온다
	cout << "ob4 의 x 는 " << x << " y 는 " << y << "\n";

	return 0;
}

