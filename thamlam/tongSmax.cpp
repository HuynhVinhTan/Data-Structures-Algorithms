#include <bits/stdc++.h>

using namespace std;

vector<int> findSubset(vector<int> &A, int m){
    int n = A.size();
    vector<int> result;
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<int>());
    for(int i = 0; i < m; i++){
        result.push_back(sortedA[i]);
    }
    return result;
}

int main(){
    vector<int> A = {10, 5 ,192, 47, 23, 12, 54, 43};
    int m = 5;
    vector<int> results = findSubset(A, m);
    for(auto result : results){
        cout<<result<<" ";
    }
    return 0;
}