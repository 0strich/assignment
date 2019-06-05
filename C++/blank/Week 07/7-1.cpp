#include <iostream>
using namespace std;

int big(int a[], int size);
int big(int a, int b);

int main(){
	int arr[5] = {1, 9, -2, 8, 6};
	cout << big(2, 3) << endl;
	cout << big(arr, 5) << endl;

	return 0;
}

int big(int a[], int size){
	int max = a[0];
	for(int i=1; i<size; i++){
		if(max < a[i])
			max = a[i];
	}
	return max;
}
int big(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}
