#include <iostream>
using namespace std;

class base {
	int i, j;
public:
	base(int a, int b) {
		i = a;
		j = b;
	}
	void showij() {
		cout << i << ' ' << j << endl;
	}
};

class derived : public base {
	int k;
public:
	derived(int a, int b, int c) : base(a,b) {
		k = c;
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
