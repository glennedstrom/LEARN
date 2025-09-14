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
    s = input()

    winner = 1 # 1 is bob, 0 is alice
    prev = [s[0]]
    c0 = 0
    c1 = 0
    for i in range(0,len(s)):
        if s[i] == '0':
            c0+=1
        else:
            c1+=1

    if(min(c0,c1) % 2 == 0):
        print("NET")
    else:
        print("DA")
    return


    for i in range(1,len(s)):
        if len(prev) >= 2 and prev[-1] != prev[-2]:
            prev.pop()
            prev.pop()
            winner = not winner
            prev.append(i)
        elif (len(prev) and s[i] != prev[-1]):
            prev.pop()
            winner = not winner
        else:
            prev.append(i)
    if(len(prev) == 2 and prev[0] != prev[1]):
        winner = not winner


    print("DA" if winner == 0 else "NET")


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
