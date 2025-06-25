#include<iostream>
using namespace std;

long long giaithua(int n){
    if(n==0) return 1;
    return n*giaithua(n-1);
}

int main(){
    int n;
    int k;
    cout<<"nhap n : ";
    cin>>n;
    cout<<"nhap k : ";
    cin>>k;
    cout<<"Giai thua cua n la : "<<giaithua(n)<<endl;
    cout<<"To hop chap k cua n la : "<<giaithua(n)/(giaithua(n-k)*giaithua(k))<<endl;
    return 0;
}