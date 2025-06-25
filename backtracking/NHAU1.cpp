#include <iostream>
#include <cmath>
using namespace std;

int n; // Kích thước bàn cờ (số lượng quân hậu)
int *s; // Mảng lưu vị trí các quân hậu trên bàn cờ
int sol = 0; // Đếm số lượng cấu hình hợp lệ

bool trienvong(int k){
    // Kiểm tra sự va chạm với các quân hậu đã đặt
    for(int i = 1; i < k; i++){
        if(s[i] == s[k] || abs(s[i] - s[k]) == abs(i - k)) 
            return false;
    }
    return true;
}

void print(){
    sol++;
    // In ra các vị trí của quân hậu
    for(int i = 1; i <= n; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

void xephau(int k){
    if(k == n + 1){ // Sửa điều kiện so sánh ở đây
        print();
    } else {
        for(int i = 1; i <= n; i++){
            s[k] = i; // Đặt quân hậu vào vị trí i của hàng k
            if(trienvong(k)){
                xephau(k + 1); // Tiến hành thử các vị trí tiếp theo
            }
        }
    }
}

int main(){
    cout << "Nhap so luong quan hau: ";
    n = 8;
    s = new int[n + 1]; // Cấp phát bộ nhớ cho mảng
    xephau(1); // Bắt đầu từ hàng 1
    cout << "So cau hinh hop la: " << sol << endl;
    delete[] s; // Giải phóng bộ nhớ sau khi sử dụng
    return 0;
}
