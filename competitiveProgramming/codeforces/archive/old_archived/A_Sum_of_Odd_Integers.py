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
    n,k = map(int, input().split())

    if(n % 2 == 0 and k % 2 == 1):
        return False
    if(n % 2 == 1 and k % 2 == 0):
        return False

    #low = pow(k,2)
    #high = pow(ceil(pow(n,0.5)),2)-pow(ceil(pow(n-k,0.5)),2)

    #print(low,high)
    #print(pow(k,2))
    return n >= pow(k,2)

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        print("YES" if solve() else "NO")
