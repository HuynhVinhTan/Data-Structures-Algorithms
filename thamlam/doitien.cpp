#include <bits/stdc++.h>

using namespace std;

int S[] = {1,2,5,10,20,50,100,200,500};
int n = sizeof(S)/sizeof(S[0]);

void doitien(int v){
    sort(S,S+n);
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        while(v >= S[i]){
            v = v - S[i];
            ans.push_back(S[i]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int v;
    cin >> v;
    doitien(v);
    return 0;
}