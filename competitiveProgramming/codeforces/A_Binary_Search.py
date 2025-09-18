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
queries = list(ints())

for target in queries:
    l,r = 0,len(nums)

    while l < r:
        mid = (r-l)//2+l

        if nums[mid] < target:
            l = mid + 1
        else:
            r = mid
    if l != len(nums) and nums[l] == target:
        print("YES")
    else:
        print("NO")


