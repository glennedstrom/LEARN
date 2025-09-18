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

n,m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))



ai = 0
for bi in range(len(b)):
    while ai < len(a) and a[ai] < b[bi]:
        ai += 1
    print(ai, end=" ")



