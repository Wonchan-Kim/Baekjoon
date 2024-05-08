#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> parties[55];
int parents[55];

int find_parent(int x){
    if(parents[x] == x) return x;

    return parents[x] = find_parent(parents[x]);
}

void union_parents(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a<b) parents[b] = a;
    else parents[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i=1; i<=n; i++) parents[i] = i;

    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int know_truth;
        cin>>know_truth;
        parents[know_truth] = 0;
    }

    for(int i=0; i<m; i++){
        int party_mans;
        cin>>party_mans;

        int temp;
        int prev;
        cin>>temp;

        prev = temp;
        parties[i].push_back(temp);

        for(int j=1; j<party_mans; j++){
            int idx;
            cin>>idx;

            union_parents(prev, idx);
            prev = idx;
        }

    }
    int ans = 0;
    for(int i=0; i<m; i++){
        int is_can_tell_lie = 1;
        for(int j=0; j<parties[i].size(); j++){
            if(find_parent(parents[parties[i][j]]) == 0){
                is_can_tell_lie = 0;
                break;
            }
        }

        if(is_can_tell_lie) ans++;
    }

    cout<<ans;

    return 0;
}