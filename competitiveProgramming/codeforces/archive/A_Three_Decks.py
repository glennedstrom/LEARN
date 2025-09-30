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
    a,b,c = map(int, input().split())

    temp = b-a
    a += temp
    c -= temp

    if (c-a) % 3 != 0 or c < a:
        print("NO")
        return
    print("YES")

    # 0 0 6
    # 1 1 4
    # 2 2 2



if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
