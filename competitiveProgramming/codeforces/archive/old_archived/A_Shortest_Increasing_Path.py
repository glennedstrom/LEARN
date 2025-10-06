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
ints = lambda: map(int, input().split())

def solve():
    x,y = ints()

    if x < y:
        print(2)
    elif x == y:
        print(-1) # y == 1
    elif x > y+1 and y > 1:
        print(3)
    else:
        print(-1) # y == 1
    


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
