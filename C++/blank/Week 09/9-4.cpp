#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Coord{
	int m_x, m_y;
public:
	Coord(int x = 0,int y = 0){
		m_x = x;
		m_y = y;
	}
	int GetX() {return m_x;}
	int GetY() {return m_y;}
	double Length();
	void ShowPoint(string pnt);

	Coord operator-();
	Coord operator*(int k);
	double operator^(Coord &p);
};

int main(){
	Coord origin, dju(3, 4), cityhall(2, 8);
	dju.ShowPoint("대전대 ");
	cityhall.ShowPoint("시청 ");

	cout << "원점에서 대전대까지 거리 = " << dju.Length() << endl;

	cout << "원점 - 대전대 거리 = " << origin ^ dju << endl;

	cout << "대전대 - 시청 거리 = " << dju ^ cityhall << endl;

	dju*3.ShowPoint("대전대의 3배 좌표 ");
	-dju.ShowPoint("대전대 원점 대칭 ");

	return 0;
}

double Coord::Length(){
	return sqrt(double(m_x*m_x + m_y*m_y));
}
void Coord::ShowPoint(string pnt){
	cout << pnt << "= (" << m_x << ", " << m_y << ")" << endl;
}
Coord Coord::operator*(int k){
	Coord temp;
	temp.m_x = m_x + k;
	temp.m_y = m_y + k;
	return temp;
}
double Coord::operator^(Coord &p){
	double length;
	length = p.length();
	return length;
}
Coord Coord::operator-(){
	Coord temp;
	temp.m_x = -m_x;
	temp.m_y = -m_y;
	return temp;
}
