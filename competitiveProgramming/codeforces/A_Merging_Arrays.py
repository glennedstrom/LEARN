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

n,m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i = j = 0
while i < len(a) or j < len(b):
    if i < len(a) and j < len(b):
        if a[i] < b[j]:
            print(a[i], end=" ")
            i+=1
        else:
            print(b[j], end=" ")
            j+=1
    elif j < len(b):
        print(b[j], end=" ")
        j+=1
    elif i < len(a) :
        print(a[i], end=" ")
        i+=1

