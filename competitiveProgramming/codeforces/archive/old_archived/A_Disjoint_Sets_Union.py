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

class UnionFind():
    def __init__(self, n):
        self.p = list(range(0,n+1)) # parent map
        self.r = [1] * (n+1) # rank

    def get(self, a: int) -> int:
        if a != self.p[a]:
            self.p[a] = self.get(self.p[a])
        return self.p[a]

    def union(self, a: int, b: int):
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return
        
        if self.r[a] == self.r[b]:
            self.r[a]+=1

        if self.r[a] > self.r[b]: # a is parent
            self.p[b] = a
        else:
            self.p[a] = b


n,m = ints()

UF = UnionFind(n)

for i in range(m):
    inputs = input().split()
    op = inputs[0]
    u,v = map(int, inputs[1:])

    if op == "union":
        UF.union(u,v)
    else:
        print("YES" if UF.get(u) == UF.get(v) else "NO")
