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
    s = input()
    c = Counter(s)

    for i in range(c['T']):
        print("T", end='')
    for c in s:
        if c != "T":
            print(c, end='')
    print()


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
