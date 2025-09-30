import sys
def input():
    return sys.stdin.readline().strip()
from math import *
ints = lambda: map(int, input().split())



class SegTree():
    def __init__(self, v=None, n=0):
        if v:
            n = len(v)
            self.size = 1 << ceil(log2(n))
            self.v = [0] * (2 * self.size)
            self.v[self.size:self.size+n] = v

            for i in range(self.size - 1, 0, -1) : 
                self.v[i] = self.v[i << 1] + self.v[i << 1 | 1]; 

        elif n:
            self.size = 1 << ceil(log2(n))
            self.v = [0] * (2*self.size)

    def assign(self, targeti: int, val: int):
        i = self.size + targeti
        self.v[i] = val
        while i > 1:
            self.v[i>>1] = self.v[i] + self.v[i^1]
            i >>= 1

    def query(self, l, r):
        tot = 0
        l += self.size
        r += self.size

        while l < r:

            if l & 1:
                tot += self.v[l]
                l+=1

            if r & 1:
                r-=1
                tot += self.v[r]

            l >>= 1
            r >>= 1
        
        return tot



n,m = ints()

nums = list(ints())

st = SegTree(v=nums)

for i in range(m):
    ops = list(ints())

    if ops[0] == 1:
        idx,val = ops[1:]
        st.assign(idx,val)
    else:
        l,r = ops[1:]
        print(st.query(l,r))




