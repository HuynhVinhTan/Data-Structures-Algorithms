#include<iostream>
using namespace std;

void catalan(int n){
    int dp[n];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<n; i++){
        dp[i] = 0;
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    for(int i=0; i<n; i++){
        cout<<dp[i]<<" ";
    }
    cout << dp[n-1] << endl;
}
int main(){
    int n;
    cin >> n;
    catalan(n);
    return 0;
}