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

# first generate an example array of numbers without single-digit primes with trial division to find any patterns
is_210prime = [True for _ in range(210)] # we care about the range 0 to 210 because both 0 and 210 modulo our "primes" are 0, making a repeated cycle

d1_primes = [2,3,5,7]

for p in d1_primes:
    for i in range(0,len(is_210prime),p): # handle 0-10 ranges by subtractin 10 or whatever
        is_210prime[i] = False

prime210 = sum(is_210prime)

def solve():
    l,r = map(int, input().split())

    # Every 210 there is a repeated cycle

    softleft = l + 210-(l % 210)
    softright = r - (r % 210)

    tot = 0
    if(softleft <= softright ): # if there is a big range to add, add it
        tot += (softright-softleft) // 210 * prime210

    # subtract 210 to take advantage of negative indexing to get outer bounds
    if l%210 > r%210:
        tot += sum(is_210prime[(l%210)-210:] + is_210prime[:r%210+1])
    elif l // 210 == r // 210: # r // 210 == l // 210: # in the same chunk
        tot += sum(is_210prime[l%210:r%210+1]) # works if they are in the same range. otherwise you need to do to the ends
    else:
        tot += sum(is_210prime[l%210:] + is_210prime[:r%210+1]) # works if they are in the same range. otherwise you need to do to the ends
    print(tot)

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
