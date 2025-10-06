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

fibonacci = [1,1] # global, don't recompute
def solve():

    n,m = map(int,input().split())

    for i in range(len(fibonacci),n+1):
        fibonacci.append(fibonacci[-1] + fibonacci[-2])

    f = fibonacci[n]
    fp = fibonacci[n-1]

    for i in range(m): # can fibs fit in the i'th box
        w,l,h = map(int,input().split())

        if w >= f and l >= f and h >= f + fp:
            print('1', end="")
        elif w >= f and l >= f+fp and h >= f: # NOTE: You also need to try placing them on the sides
            print('1', end="")
        elif w >= f+fp and l >= f and h >= f:
            print('1', end="")
        else:
            print('0', end="")




    print()

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
