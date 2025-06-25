#include<iostream>
#include<math.h>

using namespace std;

long long Xn(int n);

int main(){
    int n;
    cout<<"nhap n : ";
    cin>>n;
    cout<<"Xn = "<<Xn(n)<<endl;
    return 0;
}

long long Xn(int n){
    long long sum = 0;  
    if(n == 0) return 1;
    for(int i = 0; i < n; i++)
        sum = sum + pow(n - i, 2) * Xn(i);
    return sum;
}
