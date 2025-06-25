#include <bits/stdc++.h>
using namespace std;
#define V 5 

void printSolutions(const vector<vector<int>> &solutions); 

bool isSafe(int v, bool graph[V][V], int path[], int pos) 
{ 
    if (graph[path[pos - 1]][v] == 0) 
        return false; 
    for (int i = 0; i < pos; i++) 
        if (path[i] == v) 
            return false; 
    return true; 
} 
void hamCycleUtil(bool graph[V][V], int path[], int pos, vector<vector<int>> &allCycles) 
{ 
    if (pos == V) 
    { 
        if (graph[path[pos - 1]][path[0]] == 1) 
        { 
            vector<int> cycle(path, path + V);
            allCycles.push_back(cycle);
        } 
        return; 
    } 
    for (int v = 1; v < V; v++) 
    { 
        if (isSafe(v, graph, path, pos)) 
        { 
            path[pos] = v; 
            hamCycleUtil(graph, path, pos + 1, allCycles); 
            path[pos] = -1; 
        } 
    } 
} 
void findAllHamCycles(bool graph[V][V]) 
{ 
    int path[V]; 
    vector<vector<int>> allCycles; 
    for (int i = 0; i < V; i++) 
        path[i] = -1; 
    path[0] = 0; 

    hamCycleUtil(graph, path, 1, allCycles); 

    if (allCycles.empty()) 
        cout << "No Hamiltonian Cycle exists\n"; 
    else 
        printSolutions(allCycles); 
} 

void printSolutions(const vector<vector<int>> &solutions) 
{ 
    cout << "Hamiltonian Cycles found:\n"; 
    for (const auto &cycle : solutions) 
    { 
        for (int v : cycle) 
            cout << v << " "; 
        cout << cycle[0] << "\n"; // Close the cycle
    } 
    cout << endl; 
} 

// Driver Code 
int main() 
{ 
    bool graph1[V][V] = {{0, 1, 0, 1, 0}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 1}, 
                         {0, 1, 1, 1, 0}}; 

    cout << "Graph 1:\n";
    findAllHamCycles(graph1); 

    bool graph2[V][V] = {{0, 1, 0, 1, 0}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 0}, 
                         {0, 1, 1, 0, 0}}; 

    cout << "Graph 2:\n";
    findAllHamCycles(graph2); 

    return 0; 
} 
