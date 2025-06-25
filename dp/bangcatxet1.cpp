#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int time_dynamic(int n, int d, const vector<int>& durations) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d + 1, vector<int>(d + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int t1 = 0; t1 <= d; ++t1) {
            for (int t2 = 0; t2 <= d; ++t2) {
                dp[i][t1][t2] = dp[i - 1][t1][t2]; // Không thêm bài hát vào mặt băng nào
                if (durations[i - 1] <= t1) { // Thêm bài hát vào mặt băng thứ nhất
                    dp[i][t1][t2] = max(dp[i][t1][t2], dp[i - 1][t1 - durations[i - 1]][t2] + durations[i - 1]);
                }
                if (durations[i - 1] <= t2) { // Thêm bài hát vào mặt băng thứ hai
                    dp[i][t1][t2] = max(dp[i][t1][t2], dp[i - 1][t1][t2 - durations[i - 1]] + durations[i - 1]);
                }
            }
        }
    }
    return dp[n][d][d];
}

int main() {
    // Danh sách bài hát và thời lượng
    vector<vector<int>> test_cases = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 20 bài hát, mỗi bài 1 phút
        {10, 15, 20, 25, 30}, // 5 bài hát có thời lượng khác nhau
        {5, 5, 5, 5, 5, 5, 5, 5}, // 8 bài hát, mỗi bài 5 phút
        {40, 50, 60}, // Các bài hát có thời lượng dài hơn d
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} // Thời lượng bài hát tăng dần
    };

    int d = 30; // Thời lượng tối đa mỗi mặt băng
    for (size_t i = 0; i < test_cases.size(); ++i) {
        vector<int> durations = test_cases[i];
        int n = durations.size();

        cout << "Test case " << i + 1 << ":" << endl;
        cout << "Durations: ";
        for (int duration : durations) {
            cout << duration << " ";
        }
        cout << endl;

        // Tính toán thời lượng lớn nhất sử dụng quy hoạch động
        int max_duration_dynamic = time_dynamic(n, d, durations);

        cout << "Max duration using dynamic programming: " << max_duration_dynamic << endl;
        cout << "---------------------------------------------" << endl;
    }

    return 0;
}
