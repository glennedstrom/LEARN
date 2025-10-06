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

vertices,edges,ops = ints()

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
        
        if self.r[a] == self.r[b]:
            self.r[a]+=1

        if self.r[a] > self.r[b]: # a is parent
            self.p[b] = a
        else:
            self.p[a] = b




for i in range(edges):
    input()

s = []
for i in range(ops):
    s.append(input().split())


UF = UnionFind(vertices)

out = []
for op in s[::-1]:
    if op[0] == "ask":
        out.append("YES" if UF.get(int(op[1])) == UF.get(int(op[2])) else "NO")
    else:
        UF.union(int(op[1]), int(op[2]))

[print(i) for i in out[::-1]]

