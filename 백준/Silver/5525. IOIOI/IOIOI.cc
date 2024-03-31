#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> result;

vector<int> getPi(const string& N) {
    int n = N.size();
    vector<int> pi(n, 0);
    int matched = 0;

    for (int i = 1; i < n; i++) {
        while (matched > 0 && N[i] != N[matched]) {
            matched = pi[matched - 1];
        }
        if (N[i] == N[matched]) {
            pi[i] = ++matched;
        }
    }
    return pi;
}

void KMP(const string& H, const string& N) {
    int h = H.size();
    int n = N.size();
    vector<int> pi = getPi(N);
    int matched = 0;

    for (int i = 0; i < h; i++) {
        while (matched > 0 && H[i] != N[matched]) {
            matched = pi[matched - 1];
        }
        if (H[i] == N[matched]) {
            matched++;
            if (matched == n) {
                result.push_back(i - n + 1);
                matched = pi[matched - 1];
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    string pattern = "";
    for (int i = 0; i < 2 * N + 1; i++) {
        pattern += (i % 2 == 0) ? 'I' : 'O';
    }

    KMP(S, pattern);
    cout << result.size() << endl;

    return 0;
}
