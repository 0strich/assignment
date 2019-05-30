#include <iostream>
using namespace std;

class myclass{
	static int m_data;							// 정적 멤버 변수 m_data 를 int 형으로 선언
public:
	void SetData(int n) { m_data = n; }
	int GetData() { return m_data; }
};

int myclass::m_data;// 정적 멤버 변수(m_data) 메모리 할당

int main(){
	myclass ob1, ob2;

	ob1.SetData(100);							// 객체 ob1의 m_data 에 100의 값을 셋팅

	// ob1 의 data 값을 출력
	cout << "ob1의 m_data 값은 " << ob1.GetData() << "\n";

	// ob2 의 data 값을 출력
	cout << "ob2의 m_data 값은 " << ob2.GetData() << "\n";

	return 0;
}
