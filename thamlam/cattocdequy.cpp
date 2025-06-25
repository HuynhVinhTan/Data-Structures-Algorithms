#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int calculateTotalWaitTime(const vector<int>& times) {
    int totalWaitTime = 0;
    int currentTime = 0;
    for (int time : times) {
        totalWaitTime += currentTime;
        currentTime += time;
    }
    return totalWaitTime;
}

void generatePermutations(vector<int>& times, int l, int r, vector<int>& bestSchedule, int& minWaitTime) {
    if (l == r) {
        int totalWaitTime = calculateTotalWaitTime(times);
        if (totalWaitTime < minWaitTime) {
            minWaitTime = totalWaitTime;
            bestSchedule = times;
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(times[l], times[i]);
            generatePermutations(times, l + 1, r, bestSchedule, minWaitTime);
            swap(times[l], times[i]);
        }
    }
}

int main() {
    int n;
    cout << "Nhập số lượng khách hàng: ";
    cin >> n;

    vector<int> times(n);
    cout << "Nhập thời gian phục vụ của từng khách hàng: ";
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    vector<int> bestSchedule = times;
    int minWaitTime = calculateTotalWaitTime(times);
    generatePermutations(times, 0, n - 1, bestSchedule, minWaitTime);
    cout << "Hoán vị tối ưu (thứ tự phục vụ khách hàng): ";
    for (int time : bestSchedule) {
        cout << time << " ";
    }
    cout << endl;
    cout << "Tổng thời gian chờ tối ưu: " << minWaitTime << endl;
    return 0;
}