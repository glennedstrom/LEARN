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
    """
        find clumps of numbers, then n-clump*a[i] is the cost to make everything else match
        just compare the costs of each clump and you're good.
    """


    n = int(input())
    nums = list(map(int, input().split()))

    cur = nums[0]
    num_count = 0

    best = inf

    for i in nums:
        if i == cur:
            num_count += 1
        else:
            # reset, found a new group. Check the last one for a new best
            best = min(best, (n-num_count)*cur)
            # print("BEST", best, n, num_count, cur)
            num_count = 1
        cur = i
    # print("BEST", best)
    best = min(best, (n-num_count)*cur)

    print(best)




if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
