#include <iostream>
#include <queue>

using namespace::std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    queue<int> circle;
    
    int n;
    cin >> n;
    
    for(int i = 1; i < n + 1; i++)
    {
        circle.push(i);
    }
    
    int K;
    cin >> K;
    cout << '<';
    while(circle.size() > 1)
    {
        for(int i = 0; i < K - 1; i++)
        {
            int temp = circle.front();
            circle.pop();
            circle.push(temp);
        }
        int temp = circle.front();
        cout << temp << ',' << ' ';
        circle.pop();
    }
    cout << circle.front() << ">\n";
}