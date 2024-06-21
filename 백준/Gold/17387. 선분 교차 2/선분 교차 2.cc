#include <iostream>
#include <utility>
using namespace std;

struct point{
    long long int x;
    long long int y;
};

long long int ccw(point p1, point p2, point p3){
    long long int temp = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if (temp > 0)
        return 1;
    else if (temp < 0)
        return -1;
    else
        return 0;
}

bool isBetween(point a, point b, point c) {
    if (a.x != b.x)
        return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x);
    else
        return min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool intersect(point arr[]) {
    long long int ccw1 = ccw(arr[0], arr[1], arr[2]) * ccw(arr[0], arr[1], arr[3]);
    long long int ccw2 = ccw(arr[2], arr[3], arr[0]) * ccw(arr[2], arr[3], arr[1]);
    
    if (ccw1 <= 0 && ccw2 <= 0) {
        if (ccw1 == 0 && ccw2 == 0) {
            if (isBetween(arr[0], arr[1], arr[2]) || isBetween(arr[0], arr[1], arr[3]) ||
                isBetween(arr[2], arr[3], arr[0]) || isBetween(arr[2], arr[3], arr[1]))
                return true;
            else
                return false;
        }
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    point arr[4];
    long long int x, y;
    for(long long int i = 0; i < 4; i++){
        cin >> x >> y;
        arr[i].x = x;
        arr[i].y = y;
    }

    if (intersect(arr)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}