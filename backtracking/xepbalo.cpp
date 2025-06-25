#include <iostream>
#include <vector>
using namespace std;
// Dữ liệu đồ vật
vector<int> w; // Trọng lượng
vector<int> v; // Giá trị
int n;         // Số lượng đồ vật
int W;         // Trọng lượng tối đa của ba lô
// Kết quả tốt nhất
int giatri_totnhat = 0;
vector<int> giaphap_totnhat;
// Hàm quay lui
void xepBalo(int k, vector<int>& s, int tongTrongLuong, int tongGiaTri) {
    // Nếu đã chọn hết các đồ vật
    if (k == n) {
        // Kiểm tra điều kiện trọng lượng
        if (tongTrongLuong <= W && tongGiaTri > giatri_totnhat) {
            // Cập nhật giá trị tốt nhất
            giatri_totnhat = tongGiaTri;
            giaphap_totnhat = s; // Lưu giải pháp
        }
        return;
    }
    // Không chọn đồ vật thứ k
    s[k] = 0;
    xepBalo(k + 1, s, tongTrongLuong, tongGiaTri);
    // Chọn đồ vật thứ k (nếu hợp lệ)
    if (tongTrongLuong + w[k] <= W) {
        s[k] = 1;
        xepBalo(k + 1, s, tongTrongLuong + w[k], tongGiaTri + v[k]);
    }
}

int main() {
    cout << "Nhap so luong do vat: ";
    cin >> n;
    cout << "Nhap trong luong toi da cua balo: ";
    cin >> W;
    w.resize(n);
    v.resize(n);
    cout << "Nhap trong luong va gia tri cua tung do vat:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Do vat " << i + 1 << " (w, v): ";
        cin >> w[i] >> v[i];
    }
    vector<int> s(n, 0); // Lưu trạng thái chọn đồ vật
    // Gọi hàm quay lui
    xepBalo(0, s, 0, 0);
    // In kết quả
    cout << "Gia tri lon nhat: " << giatri_totnhat << endl;
    cout << "Cac do vat duoc chon (1-indexed): ";
    for (int i = 0; i < n; i++) {
        if (giaphap_totnhat[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}
//sorting: quicksort, heapsort --> bo BST + Hastable: 2 cau
//Dynamic programming: 1 cau: cho truoc thuat toan
//Backtracking: 1 cau: cau kho
//Greeding's algorithm: 1 cau: khong cho truoc thuat toan
//divide and conquer: 1 cau: hen xui