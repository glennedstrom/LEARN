import torch
import matplotlib.pyplot as plt
torch.set_printoptions(linewidth=183)  # Change pytorch linewidth to my laptop terminal width


words = open('names.txt', 'r').read().splitlines()

bigrams = torch.zeros((27,27), dtype=torch.int32)

chars = sorted(set([c for w in words for c in w]))

stoi = {c: i+1 for i,c in enumerate(chars)} # character to index mapping
itos = {i+1: c for i,c in enumerate(chars)} # index to character mapping
stoi['.'] = 0
itos[0] = '.'

for w in words:
    w = "." + w + "."
    for c1,c2 in zip(w,w[1:]):
        bigrams[stoi[c1],stoi[c2]] += 1

print(bigrams)
print("axis=0", bigrams.sum(0,keepdim=True))
print("axis=1", bigrams.sum(1,keepdim=True))
print("check eq: ", torch.all(bigrams.sum(0)==bigrams.sum(1))) # all true

plt.imshow(bigrams)



# 25:39


#print(a)
#Argument of the type tuple[str,str] cannot be assigned to parameter "indices" of type...



# Notes:
# translation of 2d list comprehension (fors are written in nested loop order)
#
# print([char for word in words[:20] for char in word.strip()])
# 
# b = []
# for word in words[:20]:
#     for char in word.strip():
#         b.append(char)
# print(b)
