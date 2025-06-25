#include <iostream>
#include <vector>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val, vector<int>& selectedItems) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: if there's no item or the capacity is 0
            else if (wt[i - 1] <= w) // Check if current item can be included
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                               dp[i - 1][w]);  // Take the maximum of including or excluding the item
            else
                dp[i][w] = dp[i - 1][w];  // If the item can't be included
        }
    }

    // Traceback to find the items included in the knapsack
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) { // Item i-1 is included
            selectedItems.push_back(i - 1); // Store the index of the selected item
            w -= wt[i - 1]; // Reduce the remaining capacity
        }
    }

    // Return the maximum value that can be obtained with capacity W
    return dp[n][W];
}

// Driver Code
int main() {
    vector<int> profit = {3, 2, 3, 1, 3, 2, 3, 1, 3, 1};
    vector<int> weight = {7, 9, 5, 8, 9, 5, 6, 7, 6, 5};
    int W = 10;
    vector<int> selectedItems;

    int maxValue = knapSack(W, weight, profit, selectedItems);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    // Print the selected items
    cout << "Selected items (0-based index): ";
    for (int item : selectedItems) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
