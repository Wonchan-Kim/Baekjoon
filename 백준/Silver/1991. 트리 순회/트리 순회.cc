#include <iostream>

using namespace::std;

pair<char, char> arr[26];
int N;

void preorder(char c)
{
    if(c!= '.')
    {
        cout << c;
        preorder(arr[c-'A'].first);
        preorder(arr[c-'A'].second);
    }
}

void inorder(char c)
{
    if(c!= '.')
    {
       inorder(arr[c-'A'].first);
        
        cout << c;
        
        inorder(arr[c-'A'].second);
    }
}
void postorder(char c)
{
    if(c!= '.')
    {
        
        postorder(arr[c-'A'].first);
        postorder(arr[c-'A'].second);
        cout << c;
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;
        
        arr[(parent - 'A')].first = left;
        arr[(parent - 'A')].second = right;
    }
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
}