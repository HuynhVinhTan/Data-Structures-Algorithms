def compute_matrix_chain(p):
    """
    Tính toán chi phí tối thiểu và vị trí chia tối ưu cho dãy ma trận.
    """
    n = len(p) - 1  # Số lượng ma trận
    dp = [[float('inf')] * n for _ in range(n)]  # Chi phí tối thiểu
    split = [[0] * n for _ in range(n)]          # Vị trí chia tối ưu

    # Chi phí đoạn con độ dài 1 bằng 0
    for i in range(n):
        dp[i][i] = 0

    # Xét độ dài đoạn con tăng dần
    for l in range(2, n + 1):  # l = độ dài đoạn con
        for i in range(n - l + 1):  # Bắt đầu đoạn con
            j = i + l - 1           # Kết thúc đoạn con
            for k in range(i, j):   # Chọn điểm chia k
                cost = dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j+1]
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    split[i][j] = k

    return dp, split  # Trả về bảng chi phí và vị trí chia


def build_expression(split, i, j):
    """
    Xây dựng biểu thức ngoặc hóa tối ưu từ bảng vị trí chia.
    """
    if i == j:
        return f"M{i+1}"  # Ma trận đơn lẻ
    k = split[i][j]
    left = build_expression(split, i, k)
    right = build_expression(split, k+1, j)
    return f"({left}.{right})"


# Ví dụ sử dụng
p = [5,10,3,12,5,50,6]  # Kích thước ma trận
dp, split = compute_matrix_chain(p)
expression = build_expression(split, 0, len(p) - 2)
cost = dp[0][len(p) - 2]

print(f"Biểu thức kết hợp tối ưu: {expression}")
print(f"Chi phí tối thiểu: {cost}")
