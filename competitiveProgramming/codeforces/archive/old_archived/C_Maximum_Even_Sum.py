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
    # Count how many 2's and you can either have 0 or you can have 2 or more if you have 1 on b and the rest on a
    # or just send all 2's to a while divisible by 4; that keeps a 2

    a,b = map(int, input().split())
    if b % 2 == 0:
        c = b//2
        a *= c
        b //= c
    else:
        a*=b
        b //=b

    if b % 2 != a % 2:
        print(-1)
        return

    print(a+b)



if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
