import torch
import torchvision
import torchvision.transforms as transforms
import torch.nn as nn # for torch.nn.Module
import torch.nn.functional as F # activation functions
import torch.optim as optim
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt
import numpy as np
import os



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
    
def train_model():
    """Train the model and return training history"""
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.5,), (0.5,))
    ])
    
    trainset = torchvision.datasets.MNIST(root='./data', train=True, download=True, transform=transform)
    testset = torchvision.datasets.MNIST(root='./data', train=False, download=True, transform=transform)
    
    trainLoader = DataLoader(trainset, batch_size=32, shuffle=True)
    testLoader = DataLoader(testset, batch_size=32, shuffle=False)
    
    model = NumberVerifier()
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.9)
    
    # Track training history
    train_losses = []
    train_accuracies = []
    test_accuracies = []
    
    epochs = 5
    print(f"Training model for {epochs} epochs...")
    
    for epoch in range(epochs):
        model.train()
        running_loss = 0.0
        correct_train = 0
        total_train = 0
        
        for i, (x, y_true) in enumerate(trainLoader):
            optimizer.zero_grad()
            y_pred = model(x)
            loss = criterion(y_pred, y_true)
            loss.backward()
            optimizer.step()
            
            running_loss += loss.item()
            
            # Calculate training accuracy
            _, predicted = torch.max(y_pred.data, 1)
            total_train += y_true.size(0)
            correct_train += (predicted == y_true).sum().item()
            
            if i % 100 == 99:
                avg_loss = running_loss / 100
                print(f"[{epoch+1}, {i+1:5d}] loss: {avg_loss:.3f}")
                train_losses.append(avg_loss)
                running_loss = 0.0
        
        # Calculate epoch accuracies
        train_acc = 100 * correct_train / total_train
        train_accuracies.append(train_acc)
        
        # Test accuracy
        model.eval()
        correct_test = 0
        total_test = 0
        with torch.no_grad():
            for x, y_true in testLoader:
                y_pred = model(x)
                _, predicted = torch.max(y_pred, 1)
                total_test += y_true.size(0)
                correct_test += (predicted == y_true).sum().item()
        
        test_acc = 100 * correct_test / total_test
        test_accuracies.append(test_acc)
        
        print(f'Epoch {epoch+1}: Train Acc: {train_acc:.2f}%, Test Acc: {test_acc:.2f}%')
    
    # Save model and training history
    torch.save({
        'model_state_dict': model.state_dict(),
        'optimizer_state_dict': optimizer.state_dict(),
        'train_losses': train_losses,
        'train_accuracies': train_accuracies,
        'test_accuracies': test_accuracies,
        'epochs': epochs
    }, 'mnist_model.pth')
    
    print("Model saved successfully!")
    return model, train_losses, train_accuracies, test_accuracies

def load_model():
    """Load the trained model and return model + history"""
    checkpoint = torch.load('mnist_model.pth')
    model = NumberVerifier()
    model.load_state_dict(checkpoint['model_state_dict'])
    
    return (model, 
            checkpoint['train_losses'], 
            checkpoint['train_accuracies'], 
            checkpoint['test_accuracies'])

def analyze_model(model, train_losses, train_accuracies, test_accuracies):
    """Analyze and visualize the trained model"""
    
    # Create subplots
    fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(15, 12))
    
    # Plot 1: Training Loss
    ax1.plot(train_losses, 'b-', linewidth=2)
    ax1.set_title('Training Loss Over Time', fontsize=14, fontweight='bold')
    ax1.set_xlabel('Batch (x100)')
    ax1.set_ylabel('Loss')
    ax1.grid(True, alpha=0.3)
    
    # Plot 2: Training vs Test Accuracy
    epochs = range(1, len(train_accuracies) + 1)
    ax2.plot(epochs, train_accuracies, 'g-', label='Training Accuracy', linewidth=2)
    ax2.plot(epochs, test_accuracies, 'r-', label='Test Accuracy', linewidth=2)
    ax2.set_title('Training vs Test Accuracy', fontsize=14, fontweight='bold')
    ax2.set_xlabel('Epoch')
    ax2.set_ylabel('Accuracy (%)')
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    
    # Plot 3: Model Architecture Visualization
    model_params = []
    model_layers = []
    for name, param in model.named_parameters():
        if param.requires_grad:
            model_layers.append(name)
            model_params.append(param.numel())
    
    ax3.barh(model_layers, model_params, color=['skyblue', 'lightcoral', 'lightgreen', 'gold', 'plum', 'orange'])
    ax3.set_title('Model Parameters by Layer', fontsize=14, fontweight='bold')
    ax3.set_xlabel('Number of Parameters')
    ax3.tick_params(axis='y', labelsize=8)
    
    # Plot 4: Sample Predictions
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.5,), (0.5,))
    ])
    testset = torchvision.datasets.MNIST(root='./data', train=False, download=True, transform=transform)
    testLoader = DataLoader(testset, batch_size=8, shuffle=True)
    
    model.eval()
    with torch.no_grad():
        images, labels = next(iter(testLoader))
        outputs = model(images)
        _, predicted = torch.max(outputs, 1)
    
    # Show sample predictions
    ax4.axis('off')
    ax4.set_title('Sample Predictions', fontsize=14, fontweight='bold')
    
    # Create a grid of images
    for i in range(min(8, len(images))):
        plt.subplot(2, 8, i + 9)  # Position in the grid
        img = images[i].squeeze().numpy()
        plt.imshow(img, cmap='gray')
        plt.title(f'True: {labels[i].item()}\nPred: {predicted[i].item()}', 
                 fontsize=8, 
                 color='green' if labels[i].item() == predicted[i].item() else 'red')
        plt.axis('off')
    
    plt.tight_layout()
    plt.show()
    
    # Print model summary
    total_params = sum(p.numel() for p in model.parameters())
    trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
    
    print(f"\n--- Model Summary ---")
    print(f"Total parameters: {total_params:,}")
    print(f"Trainable parameters: {trainable_params:,}")
    print(f"Final training accuracy: {train_accuracies[-1]:.2f}%")
    print(f"Final test accuracy: {test_accuracies[-1]:.2f}%")

def test_single_prediction(model):
    """Test the model on a single random image"""
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.5,), (0.5,))
    ])
    testset = torchvision.datasets.MNIST(root='./data', train=False, download=True, transform=transform)
    
    # Get a random sample
    idx = np.random.randint(0, len(testset))
    image, true_label = testset[idx]
    
    model.eval()
    with torch.no_grad():
        # Add batch dimension
        image_batch = image.unsqueeze(0)
        output = model(image_batch)
        probabilities = F.softmax(output, dim=1)
        predicted_label = int(torch.argmax(output, dim=1).item())
        confidence = probabilities[0][predicted_label].item()
    
    # Visualize
    plt.figure(figsize=(12, 4))
    
    # Show image
    plt.subplot(1, 3, 1)
    plt.imshow(image.squeeze().numpy(), cmap='gray')
    plt.title(f'True Label: {true_label}\nPredicted: {predicted_label}\nConfidence: {confidence:.3f}')
    plt.axis('off')
    
    # Show probability distribution
    plt.subplot(1, 3, 2)
    probs = probabilities[0].numpy()
    bars = plt.bar(range(10), probs)
    bars[predicted_label].set_color('red')
    plt.title('Prediction Probabilities')
    plt.xlabel('Digit')
    plt.ylabel('Probability')
    
    # Show top 3 predictions
    plt.subplot(1, 3, 3)
    top3_idx = torch.topk(probabilities[0], 3).indices.numpy()
    top3_probs = torch.topk(probabilities[0], 3).values.numpy()
    
    plt.barh(range(3), top3_probs)
    plt.yticks(range(3), [f'Digit {idx}' for idx in top3_idx])
    plt.title('Top 3 Predictions')
    plt.xlabel('Probability')
    
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    model_path = 'mnist_model.pth'

    # Check if model exists
    if os.path.exists(model_path):
        print("Loading existing model...")
        model, train_losses, train_accuracies, test_accuracies = load_model()
        print("Model loaded successfully!")
    else:
        print("No existing model found. Training new model...")
        model, train_losses, train_accuracies, test_accuracies = train_model()

    # Analyze the model
    analyze_model(model, train_losses, train_accuracies, test_accuracies)

    # Test a single prediction
    print("\nTesting single prediction...")
    test_single_prediction(model)
