import torch
import torch.nn.functional as F


#x = torch.tensor([[0.5, -0.2, 0.1],[0.2, 0.7, 0.3]])
x = torch.tensor([[0.0,0.0],[0.0,1.0],[1.0,0.0],[1.0,1.0]])

y_true = torch.tensor([[0.0], [1.0], [1.0], [0.0]])


W1 = torch.randn((2,4), requires_grad=True)
b1 = torch.randn((4,), requires_grad=True)
W2 = torch.randn((4,2), requires_grad=True)
b2 = torch.randn((2,), requires_grad=True)
W3 = torch.randn((2,1), requires_grad=True)
b3 = torch.randn((1,), requires_grad=True)

params = [W1,b1,W2,b2,W3,b3]


def forward_pass():
    # forward pass through layer 1:
    z1 = x @ W1 + b1
    a1 = F.tanh(z1) # NOT RELU because in a small network, too many could get zero'd out

    # forward pass through layer 2:
    z2 = a1 @ W2 + b2
    a2 = F.tanh(z2) # NOT RELU because in a small network, too many could get zero'd out

    # forward pass through layer 3:
    z3 = a2 @ W3 + b3
    y_pred = torch.sigmoid(z3) # final probability prediction for a binary classifier

    #loss = F.mse_loss(y_pred, y_true)
    loss = torch.nn.BCEWithLogitsLoss()(z3, y_true) # takes in raw logits instead of y_pred
    #loss = torch.nn.BCELoss()(y_pred, y_true) # takes in raw logits instead of y_pred
    return y_pred, loss

epochs = 5000
learning_rate = 0.25
for i in range(epochs):
    y_pred, loss = forward_pass()

    print(f"{loss.item()=}, {y_pred.tolist()=}")

    loss.backward()

    # gradient descent
    with torch.no_grad():
        for param in params:
            if param.grad != None:
                param -= learning_rate * param.grad

    # zero_grad (zero out the gradients for the next epoch)
    for param in params:
        if param.grad != None:
            param.grad.zero_()

