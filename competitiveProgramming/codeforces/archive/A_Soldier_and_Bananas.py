import sys
def input():
    return sys.stdin.readline().strip()
import collections
import queue

k,n,w = map(int,input().split())

print(max((w*(w+1)//2)*k-n,0));
