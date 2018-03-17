
arr = [[1, 1, 1, 0, 0, 0], [0, 1, 0, 0, 0, 0], [1, 1, 1, 0, 0, 0], [0, 9, 2, -4, -4, 0], [0, 0, 0, -2, 0, 0], [0, 0, -1, -2, -4, 0]]

max_sum = -100

for i in range(4):
    for j in range(4):
        cur_sum = 0
        for ki in range(3):
            for kj in range(3):
                cur_sum += arr[i + ki][j + kj]
        cur_sum -= arr[i + 1][j]
        cur_sum -= arr[i + 1][j + 2]

        if cur_sum > max_sum:
            max_sum = cur_sum

print(max_sum)
