import sys

def input():
    return sys.stdin.readline()

test_cases = int(input())

for test_case in range(test_cases):
    pizza_num = int(input())

    fnout = []

    out = []

    for i in range(pizza_num):
        name = input().strip()

        fnvec = input().strip().split()[1:]
        fnout.append(fnvec)

        rnvec = input().strip().split()[1:]

        out.append({fn:set(rnvec) for fn in fnvec})

    keysa = out[0].keys()
    #print(keysa)
    for s in out[1:]:
        for k in keysa:
            if k in s:
                out[0][k].intersection(s[k])
            else:
                print("else", k)
                out[0][k].intersection(set())
    #print(fnout)
    #print(settot)
    print(out[0])





