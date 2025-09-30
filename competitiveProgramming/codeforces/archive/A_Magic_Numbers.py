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

s = input()

YES = True

ptr = 0
for i in s:
    if ptr == 0 and i == '1':
        ptr+=1
    elif ptr >= 1 and ptr <= 2 and i == '4':
        ptr+=1
    elif ptr <= 3 and i == '1':
        ptr = 1
    else:
        YES = False

print("YES" if YES else "NO")


