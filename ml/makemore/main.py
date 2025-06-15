import torch

words = open('names.txt', 'r').read().splitlines()
print(words[0])

a = torch.zeros((27,27), dtype=torch.int32)

# 25:39
