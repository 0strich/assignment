#include <iostream>
using namespace std;

class myclass{
	_____________________;							// 정적 멤버 변수 m_data 를 int 형으로 선언
public:
	void SetData(int n) { m_data = n; }
	int GetData() { return m_data; }
};

_____________________								// 정젖 멤버 변수(m_data) 메모리 할당



int main(){
	myclass ob1, ob2;


	_____________________;							// 객체 ob1의 m_data 에 100의 값을 셋팅

	// ob1 의 data 값을 출력 
	cout << "ob1의 m_data 값은 " << _____________________ << "\n";

	// ob2 의 data 값을 출력
	cout << "ob2의 m_data 값은 " << _____________________ << "\n";
	
	return 0;
}

