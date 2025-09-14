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
    a,b,c = map(int, input().split())

    ab = b-a
    ac = (c-a)/2
    bc = c-b
    
    at = b-bc
    bt = ac+a
    ct = ab + b

    o=False
    if at % a == 0 and at/a > 0:
        o=True
    if (c-a) % 2 == 0 and bt % b == 0 and bt/b > 0:
        o=True
    if ct % c == 0 and ct/c > 0:
        o=True


    print("YES") if o else print("NO")






if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
