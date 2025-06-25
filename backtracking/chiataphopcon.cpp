// C++ program to check whether an array can be
// partitioned into K subsets of equal sum

#include <bits/stdc++.h>
using namespace std;

bool isKPartitionPossible(vector<int> &arr, vector<int> &subsetSum, vector<bool> &taken, int target, int k, int n, int currIdx, int limitIdx) {

    // If the current subset sum matches the target
    if (subsetSum[currIdx] == target) {
      
        // If all but one subset are filled, the 
       // last subset is guaranteed to work
        if (currIdx == k - 2)
            return true;
        return isKPartitionPossible(arr, subsetSum, taken, target, k, n, currIdx + 1, n - 1);
    }

    // Try including each element in the current subset
    for (int i = limitIdx; i >= 0; i--) {
      
        // Skip if the element is already used
        if (taken[i])
            continue;
        int temp = subsetSum[currIdx] + arr[i];
        if (temp <= target) {
          
            // Only proceed if it doesn't exceed the target
            taken[i] = true;
            subsetSum[currIdx] += arr[i];
            if (isKPartitionPossible(arr, subsetSum, taken, target, k, n, currIdx, i - 1))
                return true;
            // Backtrack
            taken[i] = false;
            subsetSum[currIdx] -= arr[i];
        }
    }
    return false;
}

bool isKPartitionPossible(vector<int> &arr, int k) {
  
    int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);

    // If only one subset is needed, it's always possible
    if (k == 1)
        return true;

    // Check if partition is impossible
    if (n < k || sum % k != 0)
        return false;

    int target = sum / k;
    vector<int> subsetSum(k, 0);
    vector<bool> taken(n, false);

    // Initialize first subset with the last element
    subsetSum[0] = arr[n - 1];
    taken[n - 1] = true;

    // Recursively check for partitions
    return isKPartitionPossible(arr, subsetSum, taken,
                                target, k, n, 0, n - 1);
}

int main() {
    vector<int> arr = {2, 1, 4, 5, 3, 3};
    int k = 3;

    if (isKPartitionPossible(arr, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}