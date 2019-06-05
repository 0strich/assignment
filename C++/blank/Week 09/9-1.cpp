#include <iostream>
#include <math.h>
using namespace std;

class Point{
	int m_x, m_y;
	double Length(){
		return sqrt(double(m_x * m_x + m_y * m_y));
	}
public:
	Point(int x, int y){
		m_x = x;
		m_y = y;
	}
	void ShowPoint();
	friend void ShowMe(Point &p);
};

int main(){
	Point obj(4, 5);
	obj.ShowPoint();
	ShowMe(obj);

	return 0;
}

void Point::ShowPoint(){
	cout << "객체 멤버함수로 (" << m_x << ',' << m_y << ')' << "	Length = " << Length() << endl;
}
void ShowMe(Point &p){
	cout << "프렌드 함수로 (" << p.m_x << ',' << p.m_y << ')' << "	Length = " << p.Length() << endl;
}
