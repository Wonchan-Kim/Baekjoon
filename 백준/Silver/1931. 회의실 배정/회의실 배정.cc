/*
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다.
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자.
단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
*/

/*
 * 첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다.
 * 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다.
 * 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool compare(const pair<long long, long long>& a, const pair<long long, long long>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main () {
    long long n;
    cin >> n;


    vector<pair<long long,long long>> conference;
    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        conference.push_back({a,b});
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    sort(conference.begin(), conference.end(), compare);
   
    long long cnt = 0;
    long long i = 0;
    while(i < n){
        long long end_time = conference[i++].second;
        while(conference[i].first < end_time && i < n){
            i++;
        }
        cnt++;
    }
    cout << cnt << endl;
}