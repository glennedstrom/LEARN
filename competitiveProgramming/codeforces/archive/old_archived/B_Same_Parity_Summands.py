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
    n,k = map(int,input().split())
    # print(f"{n=}, {k=}")

    # make n out of k odd/even
    # first cut out impossible cases

    # Evens solution:
    if n%2 == 0 and n >= 2*k:
        print("YES")
        for i in range(k-1):
            print("2", end=" ")
        print(n-(k-1)*2)
        return

    if n >= k and (n-(k-1)) % 2 == 1: # odd so you can put one more odd in
        print("YES")
        for i in range(k-1):
            print("1", end=" ")
        print(n-(k-1))
        return

    print("NO")
    return



    # if(n < k^2 and n % 2 == 1):
    #     return -1
    # else:
    #     # CAN BE SOLVED WITH ODDS, ALL CASES
    #     pass
    # if(n < (2*k+2)*k/2 and n % 2 == 0):
    #     return -1
    # else:
    #     # CAN BE SOLVED WITH EVENS, EVEN CASES
    #     pass

    

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()




# sum(evens to n) = 2 4 6  8  10 ... n*2
# sum(evens to n)[i] 2 6 12 20 30 ... sum(evens to n-1) + n*2
#
# sum(evens to n) = 2 4 6  8  10 ... n*2
# sum(evens to n) + rev(sum(evens to n)) = 2+n 4+n-1 6+n-2  8+n-3  10+n-4 ... n+[n-(n-1) or -2]
#
# example: n=5 (one-indexed)
#
# 2+10 + 4+8 + ... 10 + 2
# 2+n*2 + 4*((n-1)*2) + ... n*2 + (n-(n-1))*2
# n terms.
#
#
# 2*sum(evens to n) = n*(n+2)
#
# sum(evens to n) = n*(n+2)/2

# n+2 for all numbers in the sum times n numbers. This is in the sum(evens to n) plus (sum(evens to n, reversed)) which is 2*sum(evens to n)
#
# #2*n in the beginning because the nth number is equal to 2*n plus the 2 from the start, divided by 2 because we doubled the numbers.
#
# Math:
# (2*n+2)*n == sum(evens to n)*2
# (2*n+2)*n/2 == sum(evens to n)
# (n+1)*n == sum(evens to n)



