#include <iostream>
using namespace std;

class base {
	int i, j;
public:
	// 생성자 함수는 a,b 두 개의 매개 변수를 가지며 첫 번째 매개변수는 i에
	// 두 번째 매개변수는 j에 치환하느 생성자 함수를 만들어라
	base(int a, int b) {                           // 빈칸
		i = a;                                     // 빈칸
		j = b;                                     // 빈칸
	}
	void showij() {
		cout << i << ' ' << j << endl;
	}
};

class derived : public base {
	int k;
public:
	// 생성자 함수의 매개변수로 a, b, c 를 받아 c는 변수 k에 치환하고
	// a, b 는 기본 클래스의 생성자 함수에 전달하는 생성자 함수를 만들어라
	derived(int a, int b, int c) : base(a,b) {     // 빈칸
		k = c;                                     // 빈칸
	}
	void show() {
		cout << k << ' ';
		showij();
	}
};

int main() {
	derived ob(1, 2, 3);
	ob.show();
	system("PAUSE");
	return 0;
}
