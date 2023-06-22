    #include <algorithm>
    #include <iostream>
    #include <vector>
    using namespace std;

    bool flag = true;
    int N;
    vector<int> store;

    void previous_permutation(vector<int>& store){
        int i = N - 2; //NOTE: i points at the previous of the last element  1 4 3 5, 1 3 5 4 
    
        while(i >= 0 && store[i] <= store[i+1])
            i--;
        if(i < 0){
            flag = false;
            return;
        }

        int j = N - 1;

        while(store[j] >=  store[i]){
            j--;
        }
        swap(store[i], store[j]);
        sort(store.begin() + (i + 1), store.end(), greater<int>());
    }

    int main(){
        cin >> N;
        store.resize(N);
        for(int i = 0; i < N; i++){
            cin >> store[i];
        }
        previous_permutation(store);

        if(flag == false){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 0; i < N; i++){
            cout << store[i] << ' ';
        }
        cout << endl;
         
    }