#include <bits/stdc++.h>
using namespace std;

// To store the matrix dimension
int M, N;

// Function to print the path taken to reach destination
void printPath(vector<int>& path)
{
    for (int i : path) {
        cout << i << ", ";
    }
    cout << endl;
}

// Function to find all possible path in matrix from top
// left cell to bottom right cell
void findPaths(vector<vector<int> >& arr, vector<int>& path,
               int i, int j)
{

    // if the bottom right cell, print the path
    if (i == M - 1 && j == N - 1) {
        path.push_back(arr[i][j]);
        printPath(path);
        path.pop_back();
        return;
    }

    // Boundary cases: In case in we reach out of the matrix
    if (i < 0 || i >= M || j < 0 || j >= N) {
        return;
    }

    // Include the current cell in the path
    path.push_back(arr[i][j]);

    // Move right in the matrix
    if (j + 1 < N) {
        findPaths(arr, path, i, j + 1);
    }

    // Move down in the matrix
    if (i + 1 < M) {
        findPaths(arr, path, i + 1, j);
    }

    // Backtrack: Remove the current cell from the current
    // path
    path.pop_back();
}

// Driver code
int main()
{
    // Input matrix
    vector<vector<int> > arr
        = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

    // To store the path
    vector<int> path;

    // Starting cell `(0, 0)` cell
    int i = 0, j = 0;

    M = arr.size();
    N = arr[0].size();

    // Function call
    findPaths(arr, path, i, j);

    return 0;
}