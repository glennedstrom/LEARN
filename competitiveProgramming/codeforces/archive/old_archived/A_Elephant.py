import sys
def input():
    return sys.stdin.readline().strip()
import collections
import queue

dist = int(input())

print(dist // 5 + (dist % 5 != 0))


