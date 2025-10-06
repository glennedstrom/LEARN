import sys
def input():
    return sys.stdin.readline().strip()
import collections
import queue
from math import *

def solve():
    n = int(input())
    nums = list(map(int,input().split()))
    target = abs(nums[0])
    if n < 3:
        print("YES")
        return;

    absnums = sorted(list(map(abs,nums)))
    m1,m2 = absnums[ceil(n/2)-1], absnums[ceil(n/2)]

    if (n%2==1 and target > m1) or (n % 2 == 0 and target > m2):
        print("NO")
        return

    print("YES")


if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
