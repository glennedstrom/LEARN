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
    n,k,x = map(int, input().split())
    q = n-k
    maxn = n*(n+1)/2 - (q)*(q+1)/2
    minn = k*(k+1)/2

    print("YES") if x <= maxn and x >= minn else print("NO")

    # INFO:
    # 5 and 3

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
