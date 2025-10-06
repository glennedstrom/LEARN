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

    if any(abs(i-j) <= 1 for i,j in zip(nums,nums[1:])):
        print(0)
    else:
        print(1 if any(i<j>k or i>j<k for i,j,k in zip(nums, nums[1:], nums[2:])) else -1)

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
