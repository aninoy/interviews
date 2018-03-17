arr_t = input().strip().split(' ')
N = int(arr_t[0])
Q = int(arr_t[1])
seqList = []
lastAnswer = 0
for i in range(N):
    seqList.append([])
qList = []
for i in range(Q):
    arr_t = [int(arr_temp) for arr_temp in input().strip().split(' ')]
    qList.append(arr_t)

for i in range(Q):
    type = qList[i][0]
    x = qList[i][1]
    y = qList[i][2]
    seq_num = (x ^ lastAnswer) % N

    if type == 1:
        if seq_num >= 0 and seq_num < N:
            seqList[seq_num].append(y)
    elif type == 2:
        size = len(seqList[seq_num])
        lastAnswer = seqList[seq_num][y % size]
        print(lastAnswer)
