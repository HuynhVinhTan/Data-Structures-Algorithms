#include <iostream>
#include <vector>
using namespace std;

// Hàm in ra các hoạt động được chọn
void printSolution(const vector<vector<int>>& trace, int i, int j) {
    if (trace[i][j] != -1) {
        int k = trace[i][j];
        printSolution(trace, i, k); // Đệ quy in hoạt động từ i đến k
        cout << k << " ";            // In hoạt động k
        printSolution(trace, k, j); // Đệ quy in hoạt động từ k đến j
    }
}

// Hàm xây dựng bảng c[i][j] và truy vết
void activitySelectionDP(vector<int>& s, vector<int>& f, int n) {
    // Khởi tạo bảng giá trị c[i][j] và bảng truy vết
    vector<vector<int>> c(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> trace(n + 2, vector<int>(n + 2, -1));

    // Duyệt qua các khoảng cách d (độ dài khoảng giữa i và j)
    for (int d = 2; d <= n + 1; d++) {
        for (int i = 0; i <= n - d + 1; i++) {
            int j = i + d;
            for (int k = i + 1; k < j; k++) {
                if (f[i] <= s[k] && f[k] <= s[j]) { // Điều kiện không xung đột
                    int q = c[i][k] + c[k][j] + 1;
                    if (q > c[i][j]) {
                        c[i][j] = q;
                        trace[i][j] = k; // Lưu vết hoạt động k
                    }
                }
            }
        }
    }

    // Kết quả: Kích thước tập con lớn nhất
    cout << "Kích thước tập con lớn nhất: " << c[0][n + 1] << endl;

    // In ra các hoạt động được chọn
    cout << "Các hoạt động được chọn: ";
    printSolution(trace, 0, n + 1);
    cout << endl;
}

int main() {
    // Nhập số lượng hoạt động
    int n = 4;
    // Thời gian bắt đầu và kết thúc (thêm hoạt động ảo)
    vector<int> s = {0, 1, 3, 5, 8, 10}; 
    vector<int> f = {0, 2, 4, 7, 9, 11}; 

    // Gọi hàm xử lý
    activitySelectionDP(s, f, n);

    return 0;
}
