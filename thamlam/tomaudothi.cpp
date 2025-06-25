#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
public:
    int V; // Số lượng đỉnh
    vector<vector<int>> adj; // Danh sách kề

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Hàm tìm màu tô cho các đỉnh
    void graphColoring() {
        vector<int> result(V, -1); // Mảng lưu màu của các đỉnh
        vector<bool> available(V, false); // Mảng kiểm tra màu đã dùng

        // Gán màu đầu tiên cho đỉnh đầu tiên
        result[0] = 0;

        // Duyệt tất cả các đỉnh còn lại
        for (int u = 1; u < V; u++) {
            // Đánh dấu các màu mà các đỉnh kề đã dùng
            fill(available.begin(), available.end(), false);

            // Kiểm tra tất cả các đỉnh kề của đỉnh u
            for (int i : adj[u]) {
                if (result[i] != -1) {
                    available[result[i]] = true; // Đánh dấu màu đã dùng
                }
            }

            // Tìm màu chưa sử dụng
            int color;
            for (color = 0; color < V; color++) {
                if (!available[color]) {
                    break;
                }
            }

            result[u] = color; // Gán màu cho đỉnh u
        }

        // In ra kết quả
        cout << "Màu của các đỉnh là: \n";
        for (int u = 0; u < V; u++) {
            cout << "Đỉnh " << u << " : Màu " << result[u] << endl;
        }
    }
};

int main() {
    // Khởi tạo đồ thị
    Graph g(6); // Số lượng đỉnh là 5
    // Thêm các cạnh vào đồ thị
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 0);
    // Tô màu đồ thị
    g.graphColoring();
    return 0;
}
