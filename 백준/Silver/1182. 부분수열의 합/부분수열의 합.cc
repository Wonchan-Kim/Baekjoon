#include <iostream>

using namespace std;

int arr[21];
int N;
int target;
int answer = 0;

void dfs(int index, int sum){
	if(index == N)
		return;
		
	if(sum + arr[index] == target){
	    answer++;
	}
	
	
	dfs(index + 1, sum);
	dfs(index + 1, sum + arr[index]);
}

int main(){

	cin >> N >> target;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	dfs(0,0);
	cout << answer << endl;
}