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
    n = int(input())

    nums = list(map(int, input().split()))

    # Brute force:
    # cnt = 0
    # for i in range(n):
    #     for j in range(i+1,n):
    #         if j-i == nums[j] - nums[i]:
    #             cnt+=1

    # two pointers method?
    c = Counter([v-i for i,v in enumerate(nums)])
    
    tot = 0
    for i in c:
        if c[i] <= 1: continue
        x = c[i]-1
        tot += x*(x+1)//2
    print(tot)


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
