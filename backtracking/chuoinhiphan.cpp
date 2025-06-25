#include <iostream>
#include <vector>
using namespace std;

int n; 
vector<int> s; 

void print() {
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
}

void chuoinhiphan(int k) {
    if (k == n) {
        print();
        return;
    }
    for (int i = 0; i <= 1; i++) { 
        s[k] = i; 
        chuoinhiphan(k + 1);
    }
}

int main() {
    cout << "Nhap do dai chuoi nhi phan n: ";
    cin >> n;
    s.resize(n);
    chuoinhiphan(0);
    return 0;
}
