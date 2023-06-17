#include <iostream>
#include <vector>

using namespace std;

int visited[10] = {false};
vector<int> vec;
int n;
int m;
void backtrack(int len){
    if(len == n){
        for(int i = 0; i < len; i++){
            cout << vec[i] << ' ';
        }
         cout << '\n';
    }
    
	for(int i = 1; i <= m; i++){
	    if(visited[i] == true)
	        continue;
	    else{
	        visited[i] = true;
	        vec.push_back(i);
	        backtrack(len + 1);
	        visited[i] = false;
	        vec.pop_back();
	    }
	}
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
	cin >> m >> n;
    backtrack(0);
}