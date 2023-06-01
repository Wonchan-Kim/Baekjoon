#include <iostream>
#include <stack>
#include <string>
using namespace::std;

int main(){
    string sentence;
    int i;
    cin >> i;
    stack<char> charstack;
    cin.ignore(); //cin 함수에 의한 개행문자 무시
    while(i > 0){
        getline(cin, sentence);
        sentence += ' ';
        for(long unsigned int j = 0; j < sentence.size(); j++){
            if(sentence[j] == ' '){
                while(!charstack.empty()){
                    cout << charstack.top();
                    charstack.pop();
                }
                cout << ' ';
            }
            else
                charstack.push(sentence[j]);
        }
        cout << '\n';
        i--;
    }
}
/*
getline 함수는 c++에서 두 개의 헤더에 정의되어 있다.
(1) iostream 헤더에 정의된 getline
    #include <iostream>
        using namespace std;

        int main(){
            
            char test[10];
            
            cin.getline(test,10);
            cout << test << endl;
            return 0;
        }

    istream& getline(char* s, streamsize n);
    istream& getline(char* s, streamsize n, char delim);

    스트림으로부터 한 줄을 읽는다. 
    입력 시퀀스(sequence) 로 부터 문자를 읽어들여 C 형식의 문자열로 s 에 저장한다.

이 함수는 최대 (n - 1) 개의 문자들을 읽어들일 때 까지나 (n 번째는 NULL 문자로 채워진다), 제한자(delimiter) 가 나타날 때 까지 읽게 된다. 
제한자는 함수의 인자 delim 으로 전달되며, 명시하지 않았다면 '\n' 으로 간주한다. 또한 입력은 파일의 끝에 도달하거나, 입력 작업시 오류가 발생시 자동으로 종료된다.

(2) string 헤더에 정의된 getline
    지정한 구분자(delimeter)을 만날 때까지 문자열을 입력받아 string에 저장한다. 구분자는 따로 지정하지 않아도 된다.
    getline(stream, string object, delimiter);

    **caution**
    int main(){
        int val;
        cin >> val;
        string str;
        getline(cin,str);
        cout << val << str << endl;
    }
    위 경우 예상과 달리 int 값만 받고 종료되는 것을 알 수 있다.
    이는 표준입력버퍼에 개행문자 '\n'가 남아있기 떄문이다. 
    getline()앞에 cin.ignore()함수로 버퍼를 클리어 해주면 된다. 
*/


/*
문제
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 
단어와 단어 사이에는 공백이 하나 있다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.

예제 입력  
2
I am happy today
We want to win the first prize
예제 출력 

I ma yppah yadot
eW tnaw ot niw eht tsrif ezirp
*/