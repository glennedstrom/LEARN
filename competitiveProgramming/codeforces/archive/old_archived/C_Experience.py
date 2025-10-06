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
    def __init__(self, n: int):
        self.p = list(range(n+1))
        self.r = [1] * (n+1)
        self.xp = [0] * (n+1)
        self.poffset = [0] * (n+1)

    def get(self, x: int) -> int:
        if self.p[x] != x:
            root = self.get(self.p[x]) # update offsets and store root here
            self.poffset[x] += self.poffset[self.p[x]] # caluculate local offset relative to the parent changes
            self.p[x] = root # update my parent to point at the root
        return self.p[x]

    def union(self, a: int, b: int):
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return

        if self.r[a] == self.r[b]:
            self.r[a] += 1

        if self.r[a] > self.r[b]: # a is parent
            self.p[b] = a
            self.poffset[b] += self.xp[b] - self.xp[a] # ADJUST FOR THE MERGED SUM
        else: # b is parent
            self.p[a] = self.p[b]
            self.poffset[a] += self.xp[a] - self.xp[b] # ADJUST FOR THE MERGED SUM

    def addxp(self, u: int, xp: int):
        u = self.get(u)
        self.xp[u] += xp

    def getxp(self, u: int) -> int:
        root = self.get(u)
        return self.xp[root] + self.poffset[u] # current xp plus root; don't doulbe count if we are the root


n,m = ints()

UF = UnionFind(n)

for i in range(m):
    inputs = input().split()
    op = inputs[0]


    if op == "join":
        u,v = map(int, inputs[1:])
        UF.union(u,v)
    elif op == "add":
        u,xp = map(int, inputs[1:])
        UF.addxp(u, xp)
    elif op == "get":
        u = int(inputs[1])
        print(UF.getxp(u))
    # print(UF.poffset)
