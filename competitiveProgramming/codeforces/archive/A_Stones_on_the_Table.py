import sys
def input():
    return sys.stdin.readline()
import collections
import queue

n = int(input())
a = input().strip()

cnt = 0

for i in range(1,n):
    if a[i-1] == a[i]:
        cnt += 1

print(cnt)

