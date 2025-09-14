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

def solve():
    n,k = map(int, input().split())
    nums = list(map(int, input().split()))

    c = Counter(nums)

    works = True
    for i in c: # all must be divisible by k
        if c[i] % k != 0:
            works = False

    if not works:
        print(0)
        return

    # if so, any subarrays that don't exceed count / k is valid.
    cur = Counter() # running total of how many we have so far
    
    #for i,v in enumerate(nums): # left and right pointers for subarray, if you have too many, remove one. keep increasing too
    l = 0
    out = 0
    for r in range(len(nums)): # l and r inclusive
        cur[nums[r]] += 1 # push the right bound forwards

        while cur[nums[r]] > c[nums[r]]//k: # shrink from the left if invalid
            cur[nums[l]] -= 1
            l += 1

        #out += rnge*(rnge+1)/2
        out += r-l+1

    print(out)






if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
