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

n,m = map(int,input().split())

smol = n // 2 + n % 2
big = n
a = ((smol // m) + (smol % m != 0)) * m
print(a if a <= n and a >= smol else -1)

