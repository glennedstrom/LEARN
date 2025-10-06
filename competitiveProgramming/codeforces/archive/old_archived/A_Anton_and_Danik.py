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

n = ints()

s = input()

a = 0
o = 0
for c in s:
    if c == 'A':
        a+=1
    else:
        o+=1


if a > o:
    print("Anton")
elif o > a:
    print("Danik")
else:
    print("Friendship")
