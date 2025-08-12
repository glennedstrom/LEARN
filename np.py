"""
import numpy as np
from matplotlib import pyplot as plt

x = np.arange(0,5*10*15,1)

x = x.reshape((-1,5,10,15))

y = x**2

# print(x.shape)
# print((x[:,:,0,:, np.newaxis] == x[...,0,:, np.newaxis]).all())
# print(x[...,-2:])
# print(x[0,0,0])
# print(f'{x=}')
# print(f'{x[y > 2]=}')
a = np.arange(0,10,1)

print(a)

print(a.reshape((2,5)))
print(a.reshape((5,2)))
# print(a.reshape((10,2)))

print()
a.resize((11,3,5)) # resizes in place and reshapes. Keeps data on the lowest indices overall dimentions
print(a)

a = np.arange(-10,10,.01)
b = np.arange(10,30,.01)
c = np.stack((a,b),axis=1)
print(f'{c=}')
c = c.flatten()
print(f'{c=}')
# c = np.array_split(c,1)
# print(f'{c=}')
# c = np.array_split(c,2)
# print(f'{c=}')
c = len(np.array_split(c,5102))
print(f'{c=}')

plt.plot(a,np.tanh(a))
#plt.show()
"""



import numpy as np

# Create a 2D array
array = np.array([[3, 2, 1],
                  [8, 9, 7],
                  [4, 6, 5]])

# Split into 3 columns
result = np.split(array, 3, axis=1)

print("Original Array:")
print(array)

print("\nResult after np.split(array, 3, axis=1):")
for i, part in enumerate(result):
    print(f"Part {i+1}:\n{part}")


a = np.arange(1,10)
a = 2**a
b = a + 1

print("Bitwise XOR: ", np.bitwise_xor(a,b))

a = np.array([5, 72, 13, 100])
b = np.array([2, 5, 10, 30])

add_ans = np.add(a, b)
add2_ans = a+b
print(add_ans)
print(add2_ans)
a.resize(1,len(a)-1)
print(f'{a.T.shape=} @ {a.shape=} == {(a.T@a).shape=}')
print(f'{a.T=} * {a=} == {a.T*a=}')
print(f'{a.T=} @ {a=} == {a.T@a=}')
print(f'{a.T=} .dot( {a=} ) == {a.T.dot(a)=}')

print(f'{a}')
print(f'{np.sum(a, axis=0, keepdims=True)}')
print(f'{np.sum(a, axis=1, keepdims=True)}')


