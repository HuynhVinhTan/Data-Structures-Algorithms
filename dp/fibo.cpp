#include<iostream>
using namespace std;

int fibonacci(int n){
    int f1 = 1;
    int f2 = 1;
    for(int i = 1; i < n; i++){
        // cout << f1 << " ";
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f1;
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    // fibonacci(n);
    cout<<fibonacci(n)<<endl;
    return 0;
}