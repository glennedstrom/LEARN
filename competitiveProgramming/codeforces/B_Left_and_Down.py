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
    x,y,k = map(int, input().split());
    if x == y == 1:
        print(1)
        return

    xygcd = gcd(x,y) 

    #if k >= max(x,y): # do one easy step
    #    print(1)
    #    return;
    if max(x,y) <= k*xygcd > 1: # at least one of x,y could be over k; Must be divisible in the same number of steps to work in 1 move
         print(1)
         return
    print(2)
    return;


    # NOTE:
    # WORST CASE: do 1 1 until one is zero then 0 1 to finish the other off
    # HARD PART: Figure out if you can do it in one. Otherwise it is 2

    # X * (a,b) ; where a,b <= k

    # NOTE: First try a,b straight up if they are less than k, then try multiples of a,b. If you run out after trying up to root n, print 2
    # What you are dividing by is the multiple, the result of the division (if divisible) would be the step size.
    one = False

    # This is too slow, maybe find some sort of binary search based on numbers and modulos? I don't think it is strictly increasing. Maybe it is for larger ranges between 0's 

    for i in range(2, isqrt(min(x,y))):
        if x % i == 0 and y % i == 0:
            one = True
            break
        

    print(1 if one else 2)
    # for(int i = 2; i*i <= min(x,y); i++){

    # }


    # It is either something that divides in evenly for a cost of 1, or something that minimizes the modulo

    #THIS IS ALMOST A VARIANT ON EUCLID

    #not quite minimizes the modulo, but has the same modulo for both numbers


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
