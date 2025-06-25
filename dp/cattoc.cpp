#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int d;  // Thời gian hoàn thành công việc
    int g;  // Lợi ích của công việc
};

// Hàm tính lợi ích tối đa có thể thu được
int maxBenefit(const vector<Job>& jobs, int T, int n) {
    // dp[t] lưu trữ lợi ích tối đa có thể thu được khi sử dụng tối đa t đơn vị thời gian
    vector<int> dp(T + 1, 0);

    // Sắp xếp các công việc theo lợi ích giảm dần
    vector<Job> sortedJobs = jobs;
    sort(sortedJobs.begin(), sortedJobs.end(), [](const Job& a, const Job& b) {
        return a.g > b.g;  // Sắp xếp theo lợi ích giảm dần
    });

    // Quy hoạch động
    for (int i = 0; i < n; i++) {
        // Duyệt từ T về 1 để tránh sử dụng công việc nhiều lần
        for (int t = T; t >= sortedJobs[i].d; t--) {
            dp[t] = max(dp[t], dp[t - sortedJobs[i].d] + sortedJobs[i].g);
        }
    }

    return dp[T];  // Lợi ích tối đa có thể đạt được
}

int main() {
    int n, T;
    cout << "Nhập số lượng công việc và thời gian tối đa: ";
    cin >> n >> T;

    vector<Job> jobs(n);
    cout << "Nhập thời gian hoàn thành và lợi ích của từng công việc (d[i] g[i]):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].d >> jobs[i].g;
    }

    // Tính tổng lợi ích tối đa có thể thu được
    int result = maxBenefit(jobs, T, n);

    // In kết quả
    cout << "Tổng lợi ích tối đa có thể đạt được là: " << result << endl;

    return 0;
}
