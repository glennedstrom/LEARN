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

n,m = map(int,input().split())

mp = {}
for i in range(m):
    a,b = input().split()

    if len(a) <= len(b):
        mp[a] = a
    else:
        mp[a] = b

a = input().split()
#(print(mp[word], end=" ") for word in a.split())
for i in a:
    print(mp[i], end=" ")
