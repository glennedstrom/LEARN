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

n,m,k = map(int, input().split())

players = []
for i in range(m):
    players.append(int(input()))

fedor = int(input())

friends = 0
for p in players:
    ftest = p ^ fedor
    
    if ftest.bit_count() <= k:
        friends += 1

print(friends)
