#include <iostream>
#include <string>
using namespace std;

// Hàm đệ quy để tạo và in ra các chuỗi thập lục phân
void generateHexadecimal(int n, string current) {
    // Khi độ dài chuỗi đạt n, in chuỗi đó
    if (current.length() == n) {
        cout << current << endl;
        return;
    }

    // Các ký tự trong hệ cơ số 16 (0-9 và A-F)
    char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    // Duyệt qua các ký tự và gọi đệ quy để tạo chuỗi
    for (int i = 0; i < 16; i++) {
        generateHexadecimal(n, current + hexChars[i]);
    }
}

int main() {
    int n;
    cout << "Nhap do dai cua chuoi thap luc phan: ";
    // cin >> n;
    n = 2;
    generateHexadecimal(n, ""); // Gọi hàm đệ quy bắt đầu tạo chuỗi thập lục phân
    return 0;
}
