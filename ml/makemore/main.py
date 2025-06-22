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

# print(bigrams)
# print("axis=0", bigrams.sum(0,keepdim=True))
# print("axis=1", bigrams.sum(1,keepdim=True))
# print("check eq: ", torch.all(bigrams.sum(0)==bigrams.sum(1))) # all true

plt.figure(figsize=(16,16))
plt.imshow(bigrams, cmap='Blues')
for i in range(27):
    for j in range(27):
        chstr = itos[i] + itos[j]
        plt.text(j, i, chstr, ha="center", va="bottom", color='gray')
        plt.text(j, i, str(bigrams[i, j].item()), ha="center", va="top", color='gray')
plt.axis('off')

# Start sampling
#p = torch.rand(3, generator=g)

#His
g = torch.Generator().manual_seed(2147483647)
for i in range(10):
    out = []
    ix = 0
    while True:
        p = bigrams[ix].float()
        p =  p/p.sum()
        ix = int(torch.multinomial(p, num_samples=1, replacement=True, generator=g).item())
        if ix == 0:
            break
        out.append(itos[ix])
    print(''.join(out))


#Mine
g = torch.Generator().manual_seed(2147483647)
out = []
ix = 0
for i in range(10):
    out.append("")
    while True:
        p = bigrams[ix]
        p =  p/p.sum()
        ix = int(torch.multinomial(p, num_samples=1, replacement=True, generator=g).item())
        if ix == 0:
            break
        else:
            out[-1] += itos[ix]
print('\n'.join(out))














