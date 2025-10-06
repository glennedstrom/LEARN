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

    v = list(map(int, input().split()))

    s = set()
    for i in v:
        if i != 0:
            s.add(i)
    all_set = set(range(1,n+1))
    zeros = all_set - s

    z = sorted(list(zeros),reverse=True)


    j = 0 # zero index
    out = []
    for i in v:
        if i == 0:
            out.append(z[j])
            j+=1
        else:
            out.append(i)


    # print cost(out)
    m_i = 0
    for i,v in enumerate(out):
        if i + 1 != v:
            m_i = i+1
            break

    mx_i = 0
    for i,v in enumerate(out[::-1]):
        if n-i != v:
            mx_i = n-i
            break

    if m_i == mx_i == 0:
        print(0)
    else:
        print(mx_i-m_i+1)


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
