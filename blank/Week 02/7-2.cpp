#include <iostream>
#include <math.h>
using namespace std;

class Point{
	int m_x, m_y;
public:
	___________________________;			// 디폴트 매개변수를 가진 생성자 함수
											// (디폴트 매개변수 2개 모두 0으로 셋팅)
	void SetX(int x);						// 점근자 함수
	void SetY(int y);						// 접근자 함수
	void ShowPoint(char *)
	int GetX(){ return m_x; }				// 접근자 함수
	int GetY(){ return m_y; }				// 접근자 함수
	double Length();
};

Point::Point(int x, int y){			// 인수로 들어온 값으로 초기화
	_______________;
	_______________;
}

void Point::SetX(int x){
	m_x = x;
}

void Point::SetY(int y){
	m_y = y;
}

void Point::ShowPoint(char* pnt){
	cout << pnt << " = (" << m_x << ", " << m_y << ')' << endl;
}

double Point::Length(){
	return sqrt( double(m_x*m_x + m_y*m_y));
}

int main(){
	_______________;						// Point 클래스로 객체 p1 생성(초기화 없음)
	_______________;						// Point 클래스로 객체 p2 생성(초기화 4,7)
	_______________;						// Point 클래스로 객체 p3 생성(초기화 5, -8)
	cout << "p2.x = " << _______________ << endl;			// 접근자 함수로 p2의 m_x 출력
	cout << "p2.y = " << _______________ << endl;			// 접근자 함수로 p2의 m_y 출력
	cout << "p2 Length = " << _______________ << endl;		// p2 의 길이 출력
	_______________;										// p1 의 m_x 값을 3으로 변경
	p1.ShowPoint("점 p1");
	cout << "p1 Length = " << _______________ << endl;		// p1 의 길이 출력
	_______________;										// p2 의 m_y 값을 9으로 변경
	p2.ShowPoint("점 p2");
	cout << "p2 Length = " << _______________ << endl;		// p2 의 길이 출력

	p3.ShowPoint("점 p3");
	cout << "p3 Length = " << _______________ << endl;		// p3 의 길이 출력

	return 0;
}
