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

n,s = ints()
nums = list(ints())


l = 0
acc = 0 # accumulator, running total
best = 0
for r in range(n):
    acc += nums[r]

    while acc > s:
        acc -= nums[l]
        l+=1

    best = max(best,r-l+1)
print(best)

