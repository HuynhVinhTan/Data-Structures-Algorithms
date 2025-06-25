#include<iostream>
using namespace std;

long long int giaithua(int n);
int main(){
    int n;
    cout<<"nhap n : ";
    cin>>n;
    cout<<"Giai thua cua n la : "<<giaithua(n)<<endl;
    return 0;
}

long long int giaithua(int n){
    if (n==0) return 1;
    else return n*giaithua(n-1);
}