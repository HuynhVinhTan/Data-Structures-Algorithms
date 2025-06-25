#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int** A;
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dem = 0;
int n;

void xuat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i][j]);
        cout << endl;
    }
    cout << endl;
}

int countOptions(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int u = x + X[i];
        int v = y + Y[i];
        if (u >= 0 && u < n && v >= 0 && v < n && A[u][v] == 0)
            count++;
    }
    return count;
}
bool diChuyen(int x, int y) {
    ++dem;
    A[x][y] = dem;
    if (dem == n * n) {
        xuat();
        return true;
    }
    vector<pair<int, pair<int, int>>> moves;
    for (int i = 0; i < 8; i++) {
        int u = x + X[i];
        int v = y + Y[i];
        if (u >= 0 && u < n && v >= 0 && v < n && A[u][v] == 0) {
            moves.push_back({countOptions(u, v), {u, v}});
        }
    }
    sort(moves.begin(), moves.end()); // Ưu tiên bước đi có ít lựa chọn nhất
    for (auto move : moves) {
        int u = move.second.first;
        int v = move.second.second;
        if (diChuyen(u, v)) return true;
    }
    --dem;
    A[x][y] = 0;
    return false;
}

int main() {
    cout << "Nhap n: ";
    // cin >> n;
    n = 8;
    if (n < 5) {
        cout << "Bàn cờ quá nhỏ, không thể tìm được đường đi." << endl;
        return 0;
    }

    A = new int*[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n]{0};

    int a, b;
    cout << "Nhap vi tri bat dau.\nx: ";
    cin >> a;
    cout << "y: ";
    cin >> b;

    a--; b--; // Chuyển tọa độ về 0-index

    if (a < 0 || a >= n || b < 0 || b >= n) {
        cout << "Vi tri bat dau khong hop le!" << endl;
        return 0;
    }

    if (!diChuyen(a, b)) {
        cout << "Khong tim thay duong di." << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
