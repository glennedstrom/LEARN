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
from copy import deepcopy
ints = lambda: map(int, input().split())

n,m,d = ints()

mat = [[i for i in ints()] for i in range(n)]

# x * d == min(diff)
# search for x with ternary seach
print(mat)

l = 0
r = 10000

f = lambda x: sum([sum([abs(x*d-col) for col in row]) for row in mat])

while l < r:
    mid1 = (r-l)//3 + l
    mid2 = 2*(r-l)//3 + l

    if f(mid1) < f(mid2):
        r = mid2
    else:
        l = mid1+1

print(l)
