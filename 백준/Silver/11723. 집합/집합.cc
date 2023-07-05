
#include <iostream>

using namespace std;
unsigned int BIT = 0;
void check(string&s, int var){
	if(s == "add"){
		BIT |= (1u << var);
		
	}
	else if(s == "check"){
		if(BIT & (1u << var)){
			cout << 1 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	else if(s == "remove"){
		BIT &= ~(1u<<var);

	}
	else if(s == "toggle"){
		BIT ^= (1u << var);

	}
	else if(s == "all"){
		BIT |= (0XFFFFFFFF);
	}
	else if(s == "empty"){
		BIT &= (0x00000000);
	}
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
int N;
cin >> N;
string s;
int var;
for(int i = 0; i < N; i++){
	cin >> s;
	if(s != "all" && s != "empty")
	    cin >> var;
	check(s, var);
    }
}