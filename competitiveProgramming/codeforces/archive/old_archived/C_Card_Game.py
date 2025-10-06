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

    deal = input()
    pA = PriorityQueue()
    pB = PriorityQueue()

    aliceHand = [i == 'A' for i in deal]
    for i,alice_turn in enumerate(aliceHand):
        if alice_turn:
            pA.put(i)
        else:
            pB.put(i)

    # either the highest wins or the person with 1

    # ALICE:
    # ONLY PLAY N IF YOU HAVE 1; otherwise play N-1 and below.

    #BOB: Just easily respond with the optimal play, you see the answer

    aSpecial = aliceHand[0] # special card 1 beats N
    print(aliceHand)
    if aSpecial and aliceHand[-1]: # auto win for alice
        print("Alice")
        return

    if aliceHand[-2] and aliceHand[-1]: # auto win for alice: use -2 to win all cards
        print("Alice")
        return

    # too hyperspecific. Do the real alorithm now
    # if aSpecial and len(pB) == 1: # auto win for alice: use -2 to win all cards
    #     print("Alice")
    #     return




    while not pA.empty() and not pB.empty():
        alice_plays = None
        turn_a = pA.get()
        

    print("Bob")



if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
