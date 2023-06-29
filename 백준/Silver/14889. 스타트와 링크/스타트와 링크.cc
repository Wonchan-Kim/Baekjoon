#include <iostream>
#include <algorithm>

using namespace std;


//CHECKLIST: 1. 절반 순회하면서 방문한 팀과 미방문한 팀으로 구분시켰는가?
//CHECKLIST: 2. 최소값 갱신

int arr[21][21];
int N;
int ans = 101;
bool visited[21] = {false};
void dfs(int len, int index){
    if(len == N/2){ //NOTE: 절반까지 순회, 팀 나누기
        int left_team = 0;
        int right_team = 0;
        

        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){ //NOTE: 중복값 처리 위해
                if(visited[i] && visited[j]){
                    left_team += (arr[i][j] + arr[j][i]); 
                }
                else if(!visited[i] && !visited[j])
                    right_team += (arr[i][j] + arr[j][i]);
            }
        }
        ans = min(ans, abs(left_team - right_team));
        return;
    }
    for(int i = index; i < N; i++){
        if(visited[i])
            continue;
        
        visited[i] = true;
        dfs(len + 1,  i + 1);
        visited[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    cout << ans << endl;
}