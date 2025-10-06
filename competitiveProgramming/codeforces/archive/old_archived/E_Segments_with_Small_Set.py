from enum import unique
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

n,k = ints()

nums = list(ints())

tot = 0
visiting = defaultdict(int)
unique_count = 0
l = 0

for r in range(n):
    visiting[nums[r]] += 1
    if(visiting[nums[r]] == 1):
        unique_count+=1

    while unique_count > k:
        visiting[nums[l]]-=1
        if(visiting[nums[l]] == 0):
            unique_count-=1
        l+=1

    tot += r-l+1

print(tot)
