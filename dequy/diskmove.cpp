#include<iostream>
using namespace std;
int count = 0;
void diskmove(int n, int c1, int c2, int c3){
    if(n==1){
        cout<<"Move from "<<c1<<" to "<<c2<<endl;
        count ++;
    } else {
        diskmove(n-1, c1, c3, c2);
        diskmove(1, c1, c2, c3);
        diskmove(n-1, c3, c2, c1);
    }
}

int main(){
    int n;
    cout<<"nhap n : ";
    cin>>n;
    diskmove(n, 1, 2, 3);
    cout<<"So buoc : "<<count<<endl;
    return 0;
}