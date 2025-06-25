#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính thời lượng lớn nhất có thể ghi lên băng cát-xét
int timeDP(int n, int d, vector<int>& durations) {
    // Tạo bảng dp với kích thước [n+1][d+1][d+1]
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d + 1, vector<int>(d + 1, 0)));

    // Điền bảng dp
    for (int i = 1; i <= n; ++i) {
        for (int t1 = 0; t1 <= d; ++t1) {
            for (int t2 = 0; t2 <= d; ++t2) {
                // Không ghi bài hát i
                dp[i][t1][t2] = dp[i - 1][t1][t2];

                // Ghi bài hát i vào mặt 1 nếu đủ thời gian
                if (t1 >= durations[i - 1]) {
                    dp[i][t1][t2] = max(dp[i][t1][t2], dp[i - 1][t1 - durations[i - 1]][t2] + durations[i - 1]);
                }

                // Ghi bài hát i vào mặt 2 nếu đủ thời gian
                if (t2 >= durations[i - 1]) {
                    dp[i][t1][t2] = max(dp[i][t1][t2], dp[i - 1][t1][t2 - durations[i - 1]] + durations[i - 1]);
                }
            }
        }
    }
    //in bảng dp
    // for (int i = 1; i <= n; ++i) {
    //     for (int t1 = 0; t1 <= d; ++t1) {
    //         for (int t2 = 0; t2 <= d; ++t2) {
    //             cout << dp[i][t1][t2] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // Kết quả
    return dp[n][d][d];
}

int main() {
    // Số bài hát và thời lượng mỗi mặt
    int n = 5; // Số bài hát
    int d = 30; // Thời lượng tối đa mỗi mặt

    // Thời lượng của từng bài hát
    vector<int> durations = {10, 20, 15, 25, 30};

    // Gọi hàm và in kết quả
    int maxDuration = timeDP(n, d, durations);
    cout << "Thời lượng lớn nhất có thể ghi lên băng cát-xét: " << maxDuration << " phút" << endl;

    return 0;
}