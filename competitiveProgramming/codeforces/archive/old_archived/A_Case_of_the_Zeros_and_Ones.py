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
    s = input()

    prev = [s[0]]

    c0 = 0
    c1 = 0
    for i in range(0,len(s)):
        if s[i] == '0':
            c0+=1
        else:
            c1+=1

    o = min(c1,c0)

    print(n-o*2)
    return

    for i in range(1,len(s)):
        if len(prev) >= 2 and prev[-1] != prev[-2]:
            prev.pop()
            prev.pop()
            prev.append(s[i])
        elif (len(prev) and s[i] != prev[-1]):
            prev.pop()
            continue
        else:
            prev.append(s[i])

    if len(prev) >= 2 and s[-1] != s[-2]:
        prev.pop()
        prev.pop()

    print(len(prev))


solve()
