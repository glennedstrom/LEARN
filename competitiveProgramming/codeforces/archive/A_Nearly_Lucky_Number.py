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

flag = False
cnt = 0
for c in s:
    if c == '4' or c == '7':
        cnt+=1

if cnt == 4 or cnt == 7:
    print("YES")
else:
    print("NO")
