#include <iostream>
#include <vector>
using namespace std;
int n;                
// Số lượng phần tử
vector<int> s;        
// Dãy lưu hoán vị hiện tại
// Hàm kiểm tra tính hợp lệ của s[1..k]
bool trienvong(int k) {
    for (int i = 1; i < k; i++) {
        if (s[k] == s[i]) {
            return false; 
            // Phát hiện trùng lặp
        }
    }
    return true;
}
// Hàm sinh hoán vị
void hoanvi(int k) {
    if (k == n + 1) { 
        // Nếu đã điền đầy đủ dãy s[1..n]
        for (int i = 1; i <= n; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            s[k] = i; 
            // Gán giá trị i vào vị trí k
            if (trienvong(k)) { 
                // Kiểm tra tính hợp lệ
                hoanvi(k + 1); 
                // Gọi đệ quy để xử lý tiếp
            }
        }
    }
}
int main() {
    cout << "Nhập số lượng phần tử: ";
    cin >> n;
    s.resize(n + 1); 
    // Khởi tạo mảng lưu hoán vị
    hoanvi(1); 
    // Bắt đầu sinh hoán vị từ vị trí đầu tiên
    return 0;
}
