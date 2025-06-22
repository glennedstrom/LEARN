import torch
import torchvision
import torchvision.transforms as transforms
import torch.nn as nn # for torch.nn.Module
import torch.nn.functional as F # activation functions
import torch.optim as optim
from torch.utils.data import DataLoader
import os
import matplotlib.pyplot as plt



class NumberVerifier(nn.Module):
    def __init__(self): # define all layers in here
        super(NumberVerifier,self).__init__() # call the inherited constructor manually
        self.conv1 = nn.Conv2d(1, 6, 3)
        self.conv2 = nn.Conv2d(6, 16, 3)
        
        self.fc1 = nn.Linear(16*5*5, 120) # ((28-3+1)//2-3+1)//2 = 5 => 5x5 image; 16 channels
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10) # 10 output classes

    def forward(self, x): # use all layers here and compute prediction
        x = F.max_pool2d( F.relu( self.conv1(x) ), 2)
        x = F.max_pool2d( F.relu( self.conv2(x) ), 2)
        #putting x.size(0) instead of 32 lets it auto compute the batch size
        x = x.view(x.size(0), -1) # view it squashed without copying maintaining the batch size of 1
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)

        return x



if __name__ == "__main__":
    transform = transforms.Compose([
        transforms.ToTensor(),transforms.Normalize((.5),(.5))
    ])
    trainset = torchvision.datasets.MNIST(root='./data', train=True, download=True, transform=transform)
    trainLoader = DataLoader(trainset, batch_size=32, shuffle=True) # 32 1 28 28

    model = NumberVerifier()
    Lfunc = nn.CrossEntropyLoss()
    optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=.9)
    print(trainset)

    epochs = 5

    for epoch in range(epochs):
        running_loss = 0.0
        for i, (x, y_true) in enumerate(trainLoader):
            #zero grad
            optimizer.zero_grad() # zero out the gradients
            #forward pass
            y_pred = model(x)
            #loss
            loss = Lfunc(y_pred,y_true)
            #backward
            loss.backward()
            #update weights
            optimizer.step()

            running_loss += loss.item()
            if i % 100 == 99:
                print(f"[{epoch+1}, {i+1:5d}] loss: {running_loss / 100:.3f}")
                running_loss = 0.0
