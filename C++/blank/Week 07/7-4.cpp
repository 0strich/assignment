#include <iostream>
using namespace std;

class myclass{
	static int m_data;
public:
	void SetData(int n) {m_data = n;}
	int GetData() {return m_data;}
};

int main(){
	myclass ob1, ob2;
	ob1.SetData(100);

	cout << "ob1 의 m_data 값은 " << ob1.GetData() << endl;
	cout << "ob2 의 m_data 값은 " << ob2.GetData() << endl;

	return 0;
}

int myclass::m_data = 100;
