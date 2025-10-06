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
    a = input()
    l = u = 0
    for i in a:
        if i.islower():
            l+=1
        else:
            u+=1
    if l >= u:
        print(a.lower())
    else:
        print(a.upper())

solve()
