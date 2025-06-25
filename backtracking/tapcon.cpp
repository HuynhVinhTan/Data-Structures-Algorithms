#include <iostream>
#include <vector>
using namespace std;

int n, m; // Kích thước tập hợp và số phần tử của tập con
vector<int> s; // Mảng đánh dấu các phần tử trong tập con
vector<int> A; // Tập hợp ban đầu

// Hàm in tập con hiện tại
void print() {
    for (int i = 0; i < n; i++) {
        if (s[i] == 1) 
            cout << A[i] << " ";
    }
    cout << endl;
}

void tapcon(int k, int count) {
    if (count > m) return; 
    if (k == n) { 
        if (count == m) print();
        return;
    }
    s[k] = 0;
    tapcon(k + 1, count);
    s[k] = 1;
    tapcon(k + 1, count + 1);
}

int main() {
    cout << "Nhap kich thuoc tap hop n: ";
    cin >> n;
    cout << "Nhap so phan tu cua tap con m: ";
    cin >> m;

    A.resize(n);
    s.resize(n, 0);
    cout << "Nhap cac phan tu cua tap hop:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Cac tap con co dung " << m << " phan tu la:\n";
    tapcon(0, 0); // Bắt đầu từ phần tử đầu tiên, với 0 phần tử được chọn

    return 0;
}
