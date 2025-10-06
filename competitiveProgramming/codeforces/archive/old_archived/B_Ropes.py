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

# guess a length, have a function output how many pieces it can be cut into O(N) for O(NlogN)

n,k = map(int, input().split())

ropes = [int(input()) for _ in range(n)]


def num_ropes(cut_length):
    count = 0
    for rope in ropes:
        count += floor(rope / cut_length) # cut up the rope into this many cuts
    return count

l,r = 1e-6,max(ropes)

while r-l >= 1e-6:
    mid = (r-l)/2+l

    if num_ropes(mid) >= k: # ge because length is in the denominator so it flips everything
        l = mid
    else:
        r = mid

print(l)

