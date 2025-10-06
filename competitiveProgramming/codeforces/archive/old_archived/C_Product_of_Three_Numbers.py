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
from queue import Queue, PriorityQueue
from collections import deque

# ANSWER: find the first divisor, then n / first is M
# Find the first divisor of M that isn't the first divisor, then divide to get the last one?


def solve():
    n = int(input())

    num = n
    i = 2

    pf = set()
    dupsset = set()

    first = -1
    intermediate = 1
    while i*i <= n:
        if n % i == 0:
            first = i
            intermediate = n // first
            break
        i+=1

    second = -1
    third = -1
    i = 2
    while i*i <= intermediate:
        if intermediate % i == 0 and i != first and intermediate // i != first and intermediate // i != i:
            second = i
            third = intermediate // i
            break
        i+=1

    if third == -1 or second == -1 or first == -1:
        print("NO")
        return

    print("YES")
    print(first, second, third)











    return;

    while num > 1:
        mult = 1 # multiplier for skipping duplicates
        flag = False
        while num % i == 0:
            if flag:
                dupsset.add(i)
            #print(num, i)
            num //= i
            mult *= i
            if not(mult in pf):
                pf.add(mult)
                mult = 1
            flag = True
        i+=1

    dups = list(dupsset)
    # could still have pfs multiplied with each other IF they have duplicates; NOTE: OLD SLOW CODE HANDLED THIS
    for i in range(len(dups)):
        for j in range(i+1,len(dups)):
            if n % (dups[i] * dups[j]) == 0 and n / (dups[i] * dups[j]) > 2:
                pf.add(dups[i]*dups[j]) # still always need to compute the third number.
                #print("DUPS: ", dups[i]*dups[j])

    pfl = list(pf)
    if len(pf) < 3:
        print("NO")
        return
    else:
        #cnt = 1
        for i in range(len(pfl)):
            for j in range(i+1, len(pfl)):
                c = n // pfl[i] // pfl[j]
                #if n // pfl[i] % pfl[j] == 0:
                #    print(pfl[i], pfl[j], n // pfl[i] // pfl[j])
                if n // pfl[i] % pfl[j] == 0 and c > 1 and c != pfl[i] and c != pfl[j]:
                    print("YES")
                    print(pfl[i], pfl[j], n // pfl[i] // pfl[j])
                    return




        print("NO", end="")
        print("IMPOSSIBLE")
    return
    answers = set() # store all possible unique numbers in here that can be generated from singular primes first
    c = Counter(pf)

    # Basic case, 3 prime numbers:
    # if len(c) >= 3:
    #     j = 1
    #     print("YES")
    #     carry = 1
    #     for i in c:
    #         print(carry*i, end=' ')
    #         if carry != 1:
    #             print(carry*i, end=' ')
    #             carry = c[i] - 2 > 0
    #         if j == 3:
    #             break
    #         j+=1
    #     return

    ac = 0
    twos = []
    for i in c:
        if c[i] >= 6: # one for me, two for the next, three for the next
            answers.add(i)
            answers.add(i*i)
            answers.add(i*i*i)
            print("YES")
            print(i, i*i, i*i*i)
            return
            #ac += 3 # this right here is an answer
            #c[i] = 1
            #c[i*i] = 1
            #c[i*i*i] = 1
        elif c[i] >= 3:
            answers.add(i)
            answers.add(i*i)
            ac += 2
            if n // (i*i*i) > 1 and n // (i*i*i) != i and n // (i*i*i) != i*i:
                print("YES")
                print(i, i*i, n//(i*i*i))
                return
            else:
                print("NO") # pretty sure this is impossible
                return
        elif c[i] >= 1:
            answers.add(i)
            ac += 1
        if c[i] >= 2:
            twos.append(i)

    #TODO: Now merge if multiple have a count of 2
    for i in range(len(twos)):
        for j in range(i+1,len(twos)):
            answers.add(twos[i]*twos[j])
            ac+=1
            #print("TWOS: ", twos[i]*twos[j])


    if ac < 3:
        print("NO")
        return

    #loop through the set to find some answers.
    q = deque()

    # print(f"Answers {n}: ", end="")
    for ans in answers:
        #print(ans, end=" ")
        if(len(q) < 2):
            q.append(ans)
        elif(len(q) == 2):
            if n % q[0] != 0 or n//q[0] % q[1] != 0:
                q.popleft()
                continue

            num = n // q[0] // q[1]

            if num > 1 and num != q[0] and num != q[1]:
                print("YES")
                print(q[0], q[1], num)
                return
        else:
            q.popleft()


        

    print()
    print("NONE RETURNED")

    return

    #for i in pf:
    #    print(i,end=' ')


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
