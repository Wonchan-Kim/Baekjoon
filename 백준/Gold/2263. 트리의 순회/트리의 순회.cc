#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> in;
vector<int> post;
vector<int> IDX;

void rec(int inS, int inE, int posS, int posE){
    if(inS > inE || posS > posE){
        return;
    }
    int rootIndex = IDX[post[posE]];
    int leftLen = rootIndex - inS;
    int rightLen = inE - rootIndex;
    cout << in[rootIndex] << " ";

    rec(inS, rootIndex - 1, posS, posS + leftLen - 1);
    rec(rootIndex + 1, inE, posE - rightLen, posE - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    in.resize(n+1);
    post.resize(n+1);
    IDX.resize(n+1);

    for(int i = 0; i < n; i++){
        cin >> in[i];
        IDX[in[i]] = i;
    }    
    for(int j = 0; j < n; j++){
        cin >> post[j];
    }
    rec(0, n -1, 0, n-1);
    return 0;
}