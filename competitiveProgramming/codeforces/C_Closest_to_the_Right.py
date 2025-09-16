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



n,k = map(int,input().split())
nums = [0] + list(map(int,input().split()))
queries = map(int,input().split())


for target in queries:
    l = 1
    r = n+1

    while l < r:
        mid = (r-l)//2+l

        if nums[mid] < target:
            l = mid + 1
        else:
            r = mid

    print(l)
