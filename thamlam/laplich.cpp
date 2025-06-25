#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int gi; // Lợi ích của công việc
    int di; // Thời gian hoàn thành công việc (deadline)
};

// Hàm sắp xếp các công việc theo lợi ích gi giảm dần
bool compareJobs(Job a, Job b) {
    return a.gi > b.gi;
}

void scheduleJobs(vector<Job>& jobs) {
    // Sắp xếp công việc theo lợi ích gi giảm dần
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    int n = jobs.size();
    vector<bool> slot(n, false); // Mảng để đánh dấu công việc đã được thực hiện
    vector<int> result(n, -1);   // Mảng lưu kết quả công việc đã chọn

    // Duyệt qua các công việc
    for (int i = 0; i < n; i++) {
        // Tìm thời điểm trống sau thời điểm deadline của công việc i
        for (int j = min(n, jobs[i].di) - 1; j >= 0; j--) {
            // Nếu chưa có công việc nào ở thời điểm này, chọn công việc i
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // In ra công việc đã chọn
    cout << "Công việc đã chọn: ";
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            cout << "Công việc với lợi ích: " << jobs[result[i]].gi << " ";
            totalProfit += jobs[result[i]].gi;
        }
    }
    cout << "\nTổng lợi ích: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Nhập số lượng công việc: ";
    cin >> n;
    
    vector<Job> jobs(n);
    cout << "Nhập các công việc (lợi ích gi, deadline di):\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].gi >> jobs[i].di;
    }
    
    scheduleJobs(jobs);

    return 0;
}
