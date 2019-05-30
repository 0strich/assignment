#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Coord{
	int m_x, m_y;						// 두 좌표를 나타내는 비공개 변수
public:
	// 매개변수가 있는 생성자 함수 (두 매개변수의 디폴트 인수로 0을 사용)
	Coord(int x = 0, int y = 0){
		m_x = x;
		m_y = y;
	}
	int GetX() { return m_x; }
	int GetY() { return m_y; }
	double Length();
	void ShowPoint(string pnt);

	Coord operator-();					// 부호를 바꾸는 연산자 함수
	Coord operator*(int k);				// 정수를 곱하는 연산자 훔사
	double operator^(Coord &p);			// 두 점의 거리를 구하는 연산핮 함수
};

// 원점으로부터 객체의 거리를 구하는 함수
double Coord::Length(){
	return sqrt(double(m_x*m_x + m_y*m_y));
}

void Coord::ShowPoint(string pnt){
	cout << pnt << "= (" << m_x << ", " << m_y << ' ' << endl;
}

// Coord 클래스의 객체의 비공개 변수에 점수를 곱하는 기능을 가지도록 *를 중복한다
// 점수를 곱한 후에 원래 호출한 객체의 값이 변경되어서는 안 된다
Coord Coord::operator*(int k){
	Coord temp;
	temp.m_x = this->m_x * k;
	temp.m_y = this->m_y * k;
	return temp;
}

// Coord 클래스의 객체들의 거리를 구하는 기능을 가지도록 ^를 중복한다
double Coord::operator^(Coord &p){
	double length;
	length = ;
	return length;
}

// Coord 클래스의 객체의 비공개 변수 부호를 바꾸는 기능을 가지도록 -를 중복한다
// 부호를 바꾼 후에 원래 호출한 객체의 값이 변경되어서는 안된다
Coord Coord::operator-(){
	Coord temp;
	_____________________;
	_____________________;
	_____________________;
}

int main(){
	// origin 좌표는 원점 (0,0) 이 된다
	Coord origin, dju(3,4), cityhall(2,8);
	dju.ShowPoint("대전대 ");
	cityhall.ShowPoint("시청 ");

	// Length() 함수를 이용하여 원점에서 대전대까지의 거리를 구한다
	cout << "원점에서 대전대까지 거리 = " << ____________ << endl;

	// 연산자 함수 ^ 를 이용하여 원점에서 대전대까지의 거리를 구한다
	cout << "원점 - 대전대 거리 = " << (____________) << endl;

	// 연산자 함수 ^ 를 이용하여 대전대에서 시청까지의 거리를 구한다
	cout << "대전대 - 시청 거리 = " << (____________) << endl;

	// 연산자 함수 * 를 이용하여 대전대에서 3배되는 좌표를 구해 출력한다
	(____________).ShowPoint("대전대의 3개 좌표 ");

	// 연산자 함수 - 를 이용하여 대전대에서 원점에 대칭되는 좌표를 구해 출력한다
	(____________).ShowPoint("대전대 원점 대칭 ");

	return 0;
}
