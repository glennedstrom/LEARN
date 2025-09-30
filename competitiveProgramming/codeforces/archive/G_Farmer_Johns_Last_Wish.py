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
import functools

def fun(a,b):
    return gcd(a,b) > 1

def solve():
    n = int(input())

    nums = list(map(int,input().split()))

    k = 0
    cgcd = gcd(nums[0], nums[1])
    if cgcd == 1:
        print(0)
        return

    # the re-arranging messes mine up
    # sort by gcd?
    for i,v in enumerate(nums):
        print(sorted(nums[:i+1], key=functools.cmp_to_key(fun)))
        #print(k, end=" ")
        if(gcd(cgcd,v) != cgcd):
            k = i
    print(k)




if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
