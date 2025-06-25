#include<iostream>
using namespace std;

void thuexe(int s[], int f[], int n) {
    // Sắp xếp các công việc theo thời gian kết thúc tăng dần
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (f[i] > f[j]) {
                // Hoán đổi thời gian bắt đầu
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                // Hoán đổi thời gian kết thúc
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }

    // Chọn các công việc không xung đột
    cout << "Danh sách công việc được chọn: " << endl;
    int last_finish_time = 0; // Thời gian kết thúc của công việc cuối cùng đã chọn
    for (i = 0; i < n; i++) {
        if (s[i] >= last_finish_time) { // Công việc không trùng thời gian
            cout << "Công việc " << i + 1 << ": (" << s[i] << ", " << f[i] << ")" << endl;
            last_finish_time = f[i];
        }
    }
}

int main() {
    int n;
    cout << "Nhập số lượng công việc: ";
    cin >> n;

    int s[n], f[n];
    cout << "Nhập thời gian bắt đầu và kết thúc của các công việc:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Công việc " << i + 1 << " - Bắt đầu: ";
        cin >> s[i];
        cout << "Công việc " << i + 1 << " - Kết thúc: ";
        cin >> f[i];
    }

    thuexe(s, f, n);

    return 0;
}
