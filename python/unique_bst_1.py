def numTrees(n):
    count = {}
    count[0] = 1
    count[1] = 1
    for i in range(2, n+1):
        count[i] = 0
        for j in range(i):
            print(i, j, i-j-1, count[j] * count[i-j-1])
            count[i] += count[j] * count[i-j-1]

    return count[n]

if __name__ == '__main__':
    print(numTrees(6))
