#!/bin/python3

import os
import sys

if __name__ == '__main__':
    nd = input().split()
    n = int(nd[0])
    d = int(nd[1])
    a = list(map(int, input().rstrip().split()))

    for i in range(d):
        temp = a[1:]
        temp.append(a[0])
        a = temp

    print(' '.join([str(x) for x in a]))



