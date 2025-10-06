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


rectw,recth,n = map(int,input().split())

def rects_fit(square): # function returning how many rectangles fit in each direction
    #print(square, rectw, recth)
    width_fits = square // rectw
    height_fits = square // recth
    return width_fits*height_fits

# we want fits to fit n rectangles or more, (lower bound)


l,r = 0,int(1e18+1) # 1e9 rects with size 1e9 worst case?

while l<r:
    mid = (r-l)//2 + l

    #print(mid, rects_fit(mid))
    if rects_fit(mid) < n:
        l = mid + 1
    else:
        r = mid



print(l) # l == h
