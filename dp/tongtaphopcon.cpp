//C++ implementation for subset sum
// problem using tabulation
#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of arr[]
// with sum equal to the given sum using tabulation with vectors
bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();

    // Create a 2D vector for storing results
      // of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then answer is true (empty subset)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
      
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1]) {
              
               // Exclude the current element
                dp[i][j] = dp[i - 1][j]; 
            }
            else {
              
               // Include or exclude
                dp[i][j] = dp[i - 1][j] 
                || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}