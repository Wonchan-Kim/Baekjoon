#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
using std::vector;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> vec(n+1,1);
    vec[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
                vec[i] = max(vec[i], vec[j]+1);
            
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, vec[i]);
    }
  
    cout << ans << endl;
    return 0;
}




