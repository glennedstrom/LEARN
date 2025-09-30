import sys
def input():
    return sys.stdin.readline().strip()
import math
from math import *
import collections
from collections import ChainMap, Counter, OrderedDict, UserDict, UserList, UserString, defaultdict
import itertools
from itertools import combinations, combinations_with_replacement, count, groupby, permutations
import heapq
from heapq import nlargest, nsmallest
from queue import Queue, PriorityQueue

def solve():
    n,k = map(int, input().split())

    remain = n - k;

    s = input()

    c = Counter(s)

    twos = 0
    ones = 0

    for i in c:
        # print(i, c[i])
        twos += c[i] // 2
        if c[i] % 2 == 1:
            ones = 1

    o = min(twos*2,remain//2*2)

    ones = ones or (n != k)
    o = min(remain,o+ones)

    print("YES") if o == remain else print("NO")
    # print(f"goal: {remain=}")
    # print()





if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
