import queue
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
from queue import Empty, Queue, PriorityQueue

def solve():
    n = int(input())

    pq = [0,0,0]
    #heapq.heapify(pq)
    #pq = PriorityQueue() pq.put(0) pq.put(0) pq.put(0)

    cnt = 0
    while pq:
        u = heapq.heappop(pq)
        #print(u)
        next = int(1e9) # can finish it off if no next
        if pq:
            #next = pq.get()
            next = heapq.heappop(pq)


        if u != n:
            u = min(n, next*2+1)
            #pq.put(u)
            heapq.heappush(pq,u)
            cnt += 1 # count every new operation; when I push new values to the queue
        if next != int(1e9):
            #pq.put(next) # put the next back
            heapq.heappush(pq,next)
        
    print(cnt)




if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
