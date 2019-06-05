#include <iostream>
using namespace std;

class Point{
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0);
	void Get_XY(int &a, int &b);
	friend Point operator+(Point ob1, Point ob2);
	friend Point operator+(Point ob1, int i);
	friend Point operator+(int i, Point ob1);
};

int main(){
	Point ob1(5, 4), ob2(4, 7), ob3, ob4, ob5;
	int x, y;
	ob3 = ob1 + ob2;
	ob3.Get_XY(x, y);
	cout << "ob3 의 x 는 " << x << " y 는 " << y << "\n";

	ob4 = ob3 + 6;
	ob4.Get_XY(x, y);
	cout << "ob4 의 x 는 " << x << " y 는 " << y << "\n";

	ob5 = ob3 + 3;
	ob3.Get_XY(x, y);
	cout << "ob3 의 x 는 " << x << " y 는 " << y << "\n";

	return 0;
}

Point::Point(int x, int y){
	m_x = x;
	m_y = y;
}
void Point::Get_XY(int &a, int &b){
	a = m_x;
	b = m_y;
}
Point operator+(Point ob1, Point ob2){
	Point temp;
	temp.m_x = ob1.m_x + ob2.m_x;
	temp.m_y = ob1.m_y + ob2.m_y;
	return temp;
};
Point operator+(Point ob1, int i){
	Point temp;
	temp.m_x = ob1.m_x + i;
	temp.m_y = ob1.m_y + i;
	return temp;
}
Point operator+(int i, Point ob1){
	Point temp;
	temp.m_x = i + ob1.m_x;
	temp.m_y = i + ob1.m_y;
	return temp;
}
