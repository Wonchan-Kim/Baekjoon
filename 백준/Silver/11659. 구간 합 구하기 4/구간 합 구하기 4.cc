#include <iostream>
#include <vector>

using namespace std;

class segTree {
public:
    vector<int> tree;
    int n;

    int TreeInit(int index, int start, int end, vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        if (start == end)
            tree[index] = arr[start];
        else {
            int mid = (start + end) / 2;
            tree[index] = TreeInit(index * 2 + 1, start, mid, arr) + TreeInit(index * 2 + 2, mid + 1, end, arr);
        }
        return tree[index];
    }

    int sum(int index, int start, int end, int left, int right) {
        if (start > right || end < left)
            return 0;
        else if (start >= left && end <= right)
            return tree[index];
        else {
            int mid = (start + end) / 2;
            return sum(index * 2 + 1, start, mid, left, right) + sum(index * 2 + 2, mid + 1, end, left, right);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    segTree tree;
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    tree.TreeInit(0, 0, N - 1, arr);
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << tree.sum(0, 0, N - 1, start - 1, end - 1) << "\n";
    }
    return 0;
}
