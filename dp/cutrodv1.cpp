// C++ program to find maximum
// profit from rod of size n 
#include <bits/stdc++.h>
using namespace std;

int cutRodRecur(int i, vector<int> &price, vector<int> &memo) {
    
    // Base case
    if (i==0) return 0;
    
    // If value is memoized
    if (memo[i-1]!=-1) return memo[i-1];
    
    int ans = 0;
    
    // Find maximum value for each cut.
    // Take value of rod of length j, and 
    // recursively find value of rod of 
    // length (i-j).
    for (int j=1; j<=i; j++) {
        ans = max(ans, price[j-1]+cutRodRecur(i-j, price, memo));
    }
    
    return memo[i-1] = ans;
}

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> memo(price.size(), -1);
    return cutRodRecur(n, price, memo);
}

int main() {
    vector<int> price =  { 1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}