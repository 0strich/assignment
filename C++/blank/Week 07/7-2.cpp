#include <iostream>
#include <math.h>
using namespace std;

class Point{
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0);
	void SetX(int x);
	void SetY(int y);
	void ShowPoint(char*);
	int GetX(){return m_x;}
	int GetY(){return m_y;}
	double Length();
};

int main(){
	Point p1;
	Point p2(4, 7);
	Point p3(5, -8);
	cout << "p2.x = " << p2.GetX() << endl;
	cout << "p2.y = " << p2.GetY() << endl;
	cout << "p2.Length = " << p2.Length() << endl;
	p1.SetX(3);
	p1.ShowPoint("점 p1");
	cout << "p1 Length = " << p1.Length() << endl;
	p2.SetY(9);
	p2.ShowPoint("점 p2");
	cout << "p2 Length = " << p2.Length() << endl;
	p3.ShowPoint("점 p3");
	cout << "p3 Length = " << p3.Length() << endl;

	return 0;
}

Point::Point(int x, int y){
	m_x = x;
	m_y = y;
}
void Point::SetX(int x){
	m_x = x;
}
void Point::SetY(int y){
	m_y = y;
}
void Point::ShowPoint(char* pnt){
	cout << pnt << " = (" << m_x << ", " << m_y <<  ')' << endl;
}
double Length(){
	return sqrt(double(m_x*m_x + m_y*m_y));
}
