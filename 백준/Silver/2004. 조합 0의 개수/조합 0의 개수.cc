#include <iostream>
using namespace::std;

long long get_num(long long n, int a){
    long long ans = 0;//5로 나누고 25로 나누고 ---- 
    for(long long i = a; n / i >= 1; i*=a){
        ans += n / i;
    }
    return ans;
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long comp1, comp2;
    comp1 = get_num(a,5) - get_num(b,5) - get_num(a-b, 5);
    
    comp2 = get_num(a,2) - get_num(b,2) - get_num(a-b, 2);
 
    cout <<  ((comp1 >= comp2) ? comp2 : comp1);
}