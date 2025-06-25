#include <bits/stdc++.h>
using namespace std;

#define V 5 // Số lượng nước (đỉnh) trong ví dụ, thay đổi theo yêu cầu

// Kiểm tra xem việc tô màu c cho đỉnh v có hợp lệ không
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;  // Nếu có đỉnh láng giềng cùng màu thì không hợp lệ
        }
    }
    return true;
}
// Hàm đệ quy giải quyết bài toán tô màu đồ thị
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    // Nếu tất cả các đỉnh đã được tô màu
    if (v == V) {
        return true;
    }
    // Thử tô màu cho đỉnh v với các màu từ 1 đến m
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            // Đệ quy gán màu cho các đỉnh còn lại
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Nếu không thể tô màu, quay lại và thử màu khác
        }
    }
    return false;
}
// Hàm giải quyết bài toán tô màu đồ thị với m màu
bool graphColoring(bool graph[V][V], int m) {
    int color[V];
    memset(color, 0, sizeof(color));  // Khởi tạo tất cả màu là 0 (chưa tô)
    // Gọi hàm đệ quy để giải quyết bài toán
    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }
    // In ra kết quả
    cout << "Solution Exists: Following are the assigned colors:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Water " << i + 1 << " is colored with color " << color[i] << endl;
    }
    return true;
}

int main() {
    // Đồ thị mô phỏng mối quan hệ láng giềng giữa các nước
    bool graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    // Số màu tối đa được phép sử dụng
    int m = 4;

    // Gọi hàm giải quyết bài toán tô màu đồ thị
    graphColoring(graph, m);
    return 0;
}
