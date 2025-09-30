import sys
def input():
    return sys.stdin.readline().strip()
import collections
import queue

def solve():
    k = int(input())
    months = map(int,input().split())

    months = sorted(months,reverse=True)

    tot = 0
    cnt = 0;
    for val in months:
        if tot >= k:
            break;
        cnt += 1
        tot += val

    print(cnt if tot >= k else -1)



solve()
