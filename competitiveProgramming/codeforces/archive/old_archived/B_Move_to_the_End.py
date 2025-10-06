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

    pre_max = [nums[0]]
    for i in range(1,len(nums)):
        pre_max.append(max(nums[i],pre_max[i-1]))

    postsum = nums.copy()

    for i in range(n-2,-1,-1):
        postsum[i] += postsum[i+1]

    postsum.append(0) # for not goin out of bounds
    for k in range(n):
        #print(pre_max[n-k-1] + sum(nums[n-k:]), end=" ") # n^2 solution
        print(pre_max[n-k-1] + postsum[n-k], end=" ")
    print()

    # store an array containing the indices of what's the best to move to the back at each point in the array. then just do a running total moving backwards



if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
