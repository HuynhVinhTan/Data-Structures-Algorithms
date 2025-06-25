#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
int M[MAX][MAX]; // Mảng biểu diễn mê cung (1 là tường, 0 là đường đi)
int n; // Kích thước mê cung

struct Cell {
    int i, j; // Tọa độ (i, j) trong mê cung
};

vector<Cell> s; // Lưu trữ đường đi hiện tại
int dem = 0; // Đếm số bước di chuyển

// Hàm kiểm tra tính hợp lệ của các bước đi
bool trienvong(int k) {
    // Kiểm tra nếu ô nằm ngoài mê cung hoặc bị tường chắn
    if (s[k].i < 1 || s[k].i > n || s[k].j < 1 || s[k].j > n) {
        return false;
    }
    if (M[s[k].i][s[k].j] == 1) {
        return false;
    }
    // Kiểm tra nếu ô đã đi qua trước đó
    for (int q = 0; q < k; q++) {
        if (s[k].i == s[q].i && s[k].j == s[q].j) {
            return false;
        }
    }
    return true;
}

// Hàm tìm đường đi trong mê cung
void mecung(int k) {
    // Nếu đã đến đích, in đường đi
    if (s[k - 1].i == n && s[k - 1].j == n) {
        for (int i = 0; i < k; i++) {
            cout << "(" << s[i].i << ", " << s[i].j << ") ";
        }
        cout << endl;
    } else {
        // Di chuyển lên
        s[k].i = s[k - 1].i - 1;
        s[k].j = s[k - 1].j;
        if (trienvong(k)) {
            mecung(k + 1);
        }

        // Di chuyển xuống
        s[k].i = s[k - 1].i + 1;
        s[k].j = s[k - 1].j;
        if (trienvong(k)) {
            mecung(k + 1);
        }

        // Di chuyển qua trái
        s[k].i = s[k - 1].i;
        s[k].j = s[k - 1].j - 1;
        if (trienvong(k)) {
            mecung(k + 1);
        }

        // Di chuyển qua phải
        s[k].i = s[k - 1].i;
        s[k].j = s[k - 1].j + 1;
        if (trienvong(k)) {
            mecung(k + 1);
        }
    }
}

int main() {
    cout << "Nhập kích thước mê cung n: ";
    cin >> n;
    // Nhập mê cung
    cout << "Nhập mê cung (" << n << "x" << n << "):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> M[i][j];
        }
    }
    // Bắt đầu từ ô (1,1)
    s.push_back({1, 1});
    // Gọi hàm tìm đường đi
    cout << "Các đường đi trong mê cung:\n";
    mecung(1);
    return 0;
}
