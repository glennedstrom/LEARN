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

# max from the left and max from the right then compare.

def solve():
    n = int(input())

    dnum = set()
    dnumpfs = []
    s = input()

    for c in s:
        dnum.add(c)
        dnumpfs.append(len(dnum))


    dnumrev = set()
    dnumpfsrev = []

    for c in s[::-1]:
        dnumrev.add(c)
        dnumpfsrev.append(len(dnumrev))


    dnumpfsrev = dnumpfsrev[::-1]
    o = 0
    [o := max(o, a+b) for a,b in zip(dnumpfs,dnumpfsrev[1:])]
    # print([o := max(o, a+b) for a,b in zip(dnumpfs,dnumpfsrev[1:])])
    # for a,b in zip(dnumpfs,dnumpfsrev[1:]):
    #     print(f"{a=}, {b=}")

    print(o)











if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
