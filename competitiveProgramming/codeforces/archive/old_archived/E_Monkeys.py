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

class UnionFind():
    def __init__(self, n):
        self.p = list(range(0,n)) # parent map
        self.r = [1] * n # rank
        self.ts = [-2] * n
        self.ts[1] = -1


    def get(self, a: int) -> int:
        if a != self.p[a]:
            root = self.get(self.p[a])

            if self.ts[a] == -2 and a != 1: # avoid updating node 1
                self.ts[a] = self.ts[self.p[a]] # if not set, try setting to the time your parent got dropped (most recently added to group 1)

            self.p[a] = root
        return self.p[a]

    def union(self, a: int, b: int, timestamp=-1): # on merge, I need to log the timestamp in the NON GROUP 1 group if one is group 1
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return

        if b == self.get(1): # if it exists, group 1 is group a!
            a,b = b,a

        if self.r[a] == self.r[b]:
            self.r[a]+=1

        if timestamp != -1 and a == self.get(1) and self.ts[b] == -2: # attach b to group 1 (a) (last condition not needed)
            self.ts[b] = timestamp
            # self.p[b] = a # NOTE: Override default heuristic to always join into group 1
            # return

        if self.r[a] > self.r[b]: # a is parent
            self.p[b] = a
        else:
            self.p[a] = b

n,m = ints()

# original monkeys
monkeys = [[-1,-1]] + [list(ints()) for _ in range(n)]

monkeysDropped = deepcopy(monkeys) # ISSUE: You had a lot of issues because you don't know how to properly deepcopy in python
dropStack = []

# Read in inputs into stack to process in reverse order & drop monkeys in monkeysDropped
for i in range(m):
    monkey, hand = ints()
    dropStack.append((monkey, hand))
    monkeysDropped[monkey][hand-1] = -1

UF = UnionFind(n+1)

# Initialize from the dropped monkeys state
for i, (l,r) in enumerate(monkeysDropped):
    if l != -1:
        UF.union(i, l)
    if r != -1:
        UF.union(i, r)


# Process the nodes in reverse order to re-connect monkeys
for revtime, (monkey,hand) in enumerate(dropStack[::-1]):
    dropTime = m-revtime-1
    a = UF.get(monkey)
    b = UF.get(monkeys[monkey][hand-1])
    UF.union(monkey, monkeys[monkey][hand-1], dropTime)

# Read timestamps in order
for i in range(1,n+1):
    UF.get(i) # make sure it's updated (lazy updates)
    #assert(UF.ts[i] != -2)
    if UF.ts[i] == -2:
        UF.ts[i] = -1
    print(UF.ts[i])

