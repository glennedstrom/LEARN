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

# Definetly too slow. O(N^3)
def iter():
    for num in unums:
        maxn = 3
        for _ in range(c[num]):
            if maxn == 0:
                break
            yield num
            maxn-=1

def solve():
    n = int(input())

    global unums
    nums = list(map(int, input().split()))
    unums = sorted(list(set(nums)), reverse=True)

    global c
    c = Counter(nums)
    out = 0

    # TODO: Divide it up into win/lose, then use combinatorics to compute
    # If n >= 3 then nCk; otherwise, it is 0 or impossible
    # Where n is "winner" options

    #print(c.most_common(3))
    #print()


    gen = iter()

    x = next(gen, None)
    y = next(gen, None)
    z = next(gen, None)

    out = 0
    while x and y and z: # undercounting because I'm not doing every combo; overcounting because I didn't finish the first_not_xyz condition
        print(x,y,z)
        ic = Counter((x,y,z))

        for i in ic:
            first_not_xyz = True
            possible = (x+y+z - max(x,y,z)*2 > 0) and x+y+z > first_not_xyz
            out += possible*comb(c[i], ic[i])

        #TODO: Check if it's valid, and use combinatorics to compute the total
        #oversimplification like mad
        #out += comb(c[x], 1)*comb(c[y], 1)*comb(c[z], 1)

        # rotation
        x,y,z = y,z,next(gen, None)

    print(out)
    

    # NOTE: Optimal choice for bob is always either: unums[0] or max(top3) to recolor it


"""
For each count of the highest value, max(c[unums[0]], 3)

loop through every possible combination.
3 with nothing else;
2 with one of the others;
1 with two coming from others;

Can do this recursively to compute. Loop throuh trying all combos


By hand:
3
1 2 3
0*3c3???

4
1 1 2 4

5
7 7 7 7 7
1*5c3 == 10

5
1 1 2 2 4
(possible) * 2c2 * 2c1

posssibilities:
1   2 2
  1 2 2

6
2 3 3 4 5 5

5
1 1 1 1 3

"""


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
