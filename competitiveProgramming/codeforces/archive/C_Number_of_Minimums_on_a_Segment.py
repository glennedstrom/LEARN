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

class SegTree():
    def __init__(self, v):
        self.len = len(v) # true length of original vector
        self.size = 1 << ceil(log2(self.len))
        self.v = [[0, -1]] * (2 * self.size) # one zero
        self.v[self.size:self.size+self.len] = [[i,-1] for i in v]

        for i in range(self.size - 1, 0, -1):
            if self.v[i << 1][0] == self.v[i << 1 | 1][0]:
                self.v[i] = [self.v[i << 1][0], self.v[i << 1][1] + self.v[i << 1 | 1][1]]
            elif self.v[i << 1][0] < self.v[i << 1 | 1][0]:
                self.v[i] = self.v[i << 1]
            else:
                self.v[i] = self.v[i << 1 | 1]

    def assign(self, targeti: int, val: int):
        i = self.size + targeti
        self.v[i] = [val, -1]
        while i > 1:
            if self.v[i][0] == self.v[i^1][0]:
                self.v[i>>1] = [self.v[i][0], self.v[i][1] + self.v[i^1][1]]
            elif self.v[i][0] < self.v[i^1][0]:
                self.v[i>>1] = self.v[i]
            else:
                self.v[i>>1] = self.v[i^1]
            i >>= 1

    def query(self, l, r):
        #print("QB: ", self.v[self.size:self.size+self.len])
        #print(self.v)
        smallest = [inf,inf]
        l += self.size
        r += self.size

        while l < r:

            if l & 1:
                if smallest[0] == self.v[l][0]:
                    smallest[1] += self.v[l][1]
                else:
                    smallest = deepcopy(min(smallest,self.v[l]))
                l+=1

            if r & 1:
                r-=1
                if smallest[0] == self.v[r][0]:
                    smallest[1] += self.v[r][1]
                else:
                    smallest = deepcopy(min(smallest,self.v[r]))

            l >>= 1
            r >>= 1
        
        return smallest


n,m = ints()
nums = list(ints())
st = SegTree(nums)

for _ in range(m):
    query = list(ints())

    if query[0] == 1:
        i,v = query[1:]
        st.assign(i,v)

    else:
        l,r = query[1:]
        smallest, count = st.query(l,r)
        print(smallest, -count)
