#include <iostream>
using namespace std;

void findSolutions(int x, int y, int z, int sum) {
    // Khi x + y + z = sum, in ra nghiệm
    if (x + y + z == sum) {
        cout << x << " " << y << " " << z << endl;
        return;
    }
    
    // Duyệt giá trị của x
    for (int i = x; i <= sum - 2; i++) { // x <= sum-2 để đảm bảo có đủ chỗ cho y và z
        for (int j = y; j <= sum - i - 1; j++) { // y <= sum - i - 1 để đảm bảo có chỗ cho z
            int k = sum - i - j; // z được tính tự động
            if (k > 0) { // Chỉ xét nghiệm nguyên dương
                findSolutions(i, j, k, sum); // Đệ quy để tìm nghiệm
            }
        }
    }
}

int main() {
    int sum = 20;
    findSolutions(1, 1, 1, sum); // Khởi tạo tìm kiếm từ x = 1, y = 1, z = 1 với tổng là 20
    return 0;
}
