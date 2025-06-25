#include<bits/stdc++.h>

using namespace std;

// Hàm tính tổng thời gian chờ của các khách hàng theo một hoán vị cho trước
int calculateTotalWaitTime(const vector<int>& times) {
    int totalWaitTime = 0;
    int currentTime = 0;
    for (int i = 0; i < times.size(); ++i) {
        totalWaitTime += currentTime; // Thời gian chờ của khách hàng thứ i
        currentTime += times[i]; // Cập nhật thời gian hoàn thành phục vụ khách hàng thứ i
    }
    return totalWaitTime;
}

// Hàm sắp xếp thời gian phục vụ theo thứ tự tăng dần và tính toán tổng thời gian chờ
void findOptimalSchedule(vector<int>& times) {
    vector<int> bestSchedule = times;
    // Sắp xếp thời gian phục vụ theo thứ tự tăng dần
    sort(bestSchedule.begin(), bestSchedule.end());
    // Tính tổng thời gian chờ với thứ tự đã sắp xếp
    int minWaitTime = calculateTotalWaitTime(bestSchedule);
    // In ra hoán vị tối ưu và tổng thời gian chờ
    cout << "Hoán vị tối ưu (thứ tự phục vụ khách hàng): ";
    for (int time : bestSchedule) {
        cout << time << " ";
    }
    cout << endl;
    cout << "Tổng thời gian chờ tối ưu: " << minWaitTime << endl;
}

int main() {
    // Nhập số lượng khách hàng và thời gian phục vụ của từng khách hàng
    int n;
    cout << "Nhập số lượng khách hàng: ";
    cin >> n;

    vector<int> times(n);
    cout << "Nhập thời gian phục vụ của từng khách hàng: ";
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    // Tìm hoán vị tối ưu
    findOptimalSchedule(times);
    return 0;
}

