#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9; // Giá trị vô cùng
char a[N][N];
int dist[N][N];
int n, m;
pair<int, int> pB, pC;

int main() {
    cin >> n >> m;

    // Khởi tạo ma trận và vị trí B, C
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            dist[i][j] = INF; // Gán giá trị vô cùng ban đầu
            if (a[i][j] == 'C') {
                pC = {i, j};
                dist[i][j] = 0; // Điểm bắt đầu
            } else if (a[i][j] == 'B') {
                pB = {i, j};
            }
        }
    }

    // DP: Duyệt từ trên xuống và từ trái qua phải
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '*') continue; // Bỏ qua vật cản
            if (i > 1) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
            if (j > 1) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
        }
    }

    // DP: Duyệt từ dưới lên và từ phải qua trái
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (a[i][j] == '*') continue; // Bỏ qua vật cản
            if (i < n) dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < m) dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    // Kết quả tại vị trí B
    int result = dist[pB.first][pB.second];
    if (result == INF) cout << -1 << endl; // Không tìm được đường đi
    else cout << result << endl;

    return 0;
}
