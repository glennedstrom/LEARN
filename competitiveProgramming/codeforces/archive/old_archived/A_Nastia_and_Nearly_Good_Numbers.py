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

class pset:
    def __init__(self, n):
        self.n = n
        self.init_primes(n)

    
    def init_primes(self, n):
        pset = []
        for i in range(2, int(isqrt(n))):
            while n % i == 0:
                pset.append(i)
                n /= i
        self.pset = Counter(pset)


def solve():
    a,b = map(int, input().split())

    apset = pset(a)
    bpset = pset(a)
    for i in apset.pset:
        print(i)
    return 

    print(gcd(a,b))
    if a % b == 0:
        print("NO") # can't make almost good numbers
        return

    # if b divides into any of your answers, it is wrong and stop the loop. No need to compute prime factors and stuff

    good = a*b

    almost_good = 0
    almost_good2 = 0

    print("YES")
    print(good, almost_good, almost_good2)

    


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
