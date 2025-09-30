import sys
def input():
    return sys.stdin.readline().strip()
import collections
import queue
from functools import cmp_to_key

def gcd(a,b):
    if(a == 0):return b;
    return gcd(b%a,a)

def comp(a,b):
    if a%2==0: #if a%2==0 and b%2 == 1: a is even, push left
        return -1
    if a%2 > b%2: #if a%2==1 and b%2 == 0:
        return 1

    g = gcd(a,b*2)
    if g > 1:
        return -1
    else:
        return 1
# lambda a, b: (gcd(a,2*b) > 1)*2-1

def solve():
    n = int(input())
    nums = map(int,input().split())
    mod = sorted(nums,key=cmp_to_key(comp))

    tot = 0
    for i,v in enumerate(mod):
        if v % 2 == 0:
            tot += n - i - 1
            continue
        for j in range(i+1,n):
            if gcd(v,mod[j]) > 1:
                tot+=1
    #print(*mod)
    print(tot)
    # NOTE: Evens can GCD with each other and all odds in front of them from the *2
    # ODDS require multiples of prime factors to be in front.
    # EX: 3,9,15
    # 5,15,25



if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
