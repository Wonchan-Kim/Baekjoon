#include <iostream>



using namespace std;

int main(){
	int N;
	int num = 0;
	cin >> N;
	for(int i = 1; i <= N; i *= 10){
		num += N - i + 1;
	}
	cout << num << endl;
}