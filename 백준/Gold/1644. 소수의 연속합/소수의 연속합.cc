#include <iostream>
#include <vector>
using namespace std;

int n;
bool prime[4000001] = {true};
vector<int> primes;
void era() {
    fill(begin(prime), end(prime), true);  // Initialize all elements to true
    prime[0] = prime[1] = false;           // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n <= 1){
        cout << 0 << '\n';
        return 0;
    }
    era();
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    while(right <= primes.size()){
        if (sum >= n){
            sum -= primes[left];
            left++;
        }
        if(sum < n) {
            sum += primes[right];
            right++;
        }
        if (sum == n)
            ans += 1;
    }
    cout << ans << '\n';
    return 0;

}