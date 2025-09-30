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

n = int(input())
nums = [0] + sorted(list(map(int, input().split())))
pre = list(range(0,n+1))
# binary search for the upper bound of the right, and lower bound of the left.
# Use this on the range() as a prefix sum to directly count how many are in that range

k = int(input())

for _ in range(k):
    tl,tr = map(int, input().split())
    l = 1; r = n+1

    while l < r:
        mid = (r-l)//2+l

        if nums[mid] < tl:
            l = mid + 1
        else:
            r = mid

    lower = l

    l = 1; r = n+1

    while l < r:
        mid = (r-l)//2+l

        if nums[mid] <= tr:
            l = mid + 1
        else:
            r = mid

    upper = l

    print(pre[upper-1] - pre[lower-1])
