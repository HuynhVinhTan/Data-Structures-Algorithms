#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> s;

void print(vector<int> s){
    for(int i = 0; i < n; i++){
        if(s[i] == 1) 
            cout << i+1 << " ";
    }
    cout << endl;
}
void tapcon(int k){
    if(k-1 == n){
        print(s);
    } else {
        s[k] = 0;
        tapcon(k+1);
        s[k] = 1;
        tapcon(k+1);
    }
}
int main(){
    cout<<"Nhap kich thuoc tap hop n: ";
    cin >> n;
    s.resize(n);
    tapcon(0);
    return 0;
}