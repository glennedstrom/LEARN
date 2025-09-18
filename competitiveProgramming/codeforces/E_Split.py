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
import random

# Custom hash function for integers to avoid malicious hash collision attacks
class HashInt:
    def __init__(self, val):
        self.val = val
        if not hasattr(HashInt, '_initialized'):
            HashInt.p1 = random.randrange(10**9, 2*10**9) | 1
            HashInt.p2 = random.randrange(10**9, 2*10**9) | 1
            HashInt.mod = 2**61 - 1
            HashInt._initialized = True
    
    def __hash__(self):
        return ((self.val * HashInt.p1) ^ HashInt.p2) % HashInt.mod
    
    def __eq__(self, other):
        if isinstance(other, HashInt):
            return self.val == other.val
        return self.val == other
    
    def __getattr__(self, name):
        return getattr(self.val, name)

def solve():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    hashed_nums = [HashInt(x) for x in nums]
    
    c = Counter(hashed_nums)
    works = True
    for i in c:  # all must be divisible by k
        if c[i] % k != 0:
            works = False
            break
    
    if not works:
        print(0)
        return
    
    cur = Counter()  # running total of how many we have so far
    
    l = 0
    out = 0
    for r in range(len(hashed_nums)):  # l and r inclusive
        cur[hashed_nums[r]] += 1  # push the right bound forwards
        while cur[hashed_nums[r]] > c[hashed_nums[r]] // k:  # shrink from the left if invalid
            cur[hashed_nums[l]] -= 1
            l += 1
        out += r - l + 1
    print(out)

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
