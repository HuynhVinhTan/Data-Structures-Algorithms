#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
int C[MAX][MAX]; // Ma trận trọng số (hoặc kết nối)
vector<int> s;  // Lưu đường đi hiện tại
int n, start, dest; // Số thành phố, thành phố bắt đầu, thành phố đích

// Kiểm tra tính hợp lệ của s[1..k]
bool trienvong(int k) {
    if (C[s[k - 1]][s[k]] == 0) {
        return false; // Không có đường từ s[k-1] đến s[k]
    }
    for (int i = 1; i < k; i++) {
        if (s[i] == s[k]) {
            return false; // Đã đi qua thành phố này trước đó
        }
    }
    return true;
}

// Hàm tìm đường đi
void duongdi(int k) {
    if (s[k - 1] == dest) { // Nếu đã đến thành phố đích
        for (int i = 1; i < k; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    } else {
        for (int j = 1; j <= n; j++) {
            s[k] = j; // Gán thành phố j vào vị trí k
            if (trienvong(k)) { // Kiểm tra tính hợp lệ
                duongdi(k + 1); // Gọi đệ quy để tìm tiếp
            }
        }
    }
}

int main() {
    cout << "Nhập số lượng thành phố: ";
    cin >> n;

    cout << "Nhập ma trận kết nối (" << n << "x" << n << "):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
        }
    }

    cout << "Nhập thành phố bắt đầu: ";
    cin >> start;
    cout << "Nhập thành phố đích: ";
    cin >> dest;

    s.resize(n + 1);
    s[1] = start; // Bắt đầu từ thành phố khởi đầu

    cout << "Các đường đi từ " << start << " đến " << dest << ":\n";
    duongdi(2); // Bắt đầu tìm từ vị trí thứ 2

    return 0;
}
