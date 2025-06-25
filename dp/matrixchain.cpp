#include <iostream>
#include <iomanip> // Để sử dụng setw
#include <climits> // Để sử dụng INT_MAX
using namespace std;

// Hàm tính toán số phép nhân tối thiểu
int MatrixChainOrder(int p[], int n)
{
	int dp[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = 0;
		}
	}
	// Gán giá trị 0 cho dp[i][i] vì nhân một ma trận không cần phép nhân nào.
	for (int i = 1; i < n; i++)
		dp[i][i] = 0;
	// Duyệt qua tất cả các độ dài đoạn con L
	for (int L = 1; L < n; L++) {
		for (int i = 1; i < n - L; i++) {
			int j = i + L;
			dp[i][j] = INT_MAX;
			// Tìm điểm phân chia k tối ưu
			for (int k = i; k < j; k++) {
				int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}
	// In ma trận dp với định dạng đẹp
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= j)
				cout << setw(8) << dp[i][j]; // Căn độ rộng 8 ký tự
			else
				cout << setw(8) << "-";      // Hiển thị dấu "-" cho các ô không dùng
		}
		cout << endl;
	}

	// Trả về kết quả tối ưu
	return dp[1][n-1];
}

// Hàm chính
int main()
{
	int arr[] = {2,25,3,16,1,1000};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is: \n"
		 << MatrixChainOrder(arr, size) << endl;

	return 0;
}
