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
        self.conv1 = nn.Conv2d(1, 2, 3)
        self.conv2 = nn.Conv2d(2, 1, 3)
        # self.conv3 = nn.Conv2d(6, 12, 3)
        
        self.fc1 = nn.Linear(1*5*5, 20) # ((28-3+1)//2-3+1)//2 = 5 => 5x5 image; 16 channels
        self.fc2 = nn.Linear(20, 10)
        #self.fc3 = nn.Linear(20, 10) # 10 output classes

    def forward(self, x): # use all layers here and compute prediction
        x = F.max_pool2d( F.relu( self.conv1(x) ), 2)
        x = F.max_pool2d( F.relu( self.conv2(x) ), 2)
        # x = F.max_pool2d( F.relu( self.conv3(x) ), 2)
        #putting x.size(0) instead of 32 lets it auto compute the batch size
        x = x.view(x.size(0), -1) # view it squashed without copying maintaining the batch size of 1
        x = F.relu(self.fc1(x))
        #x = F.relu(self.fc2(x))
        #x = self.fc3(x)
        x = self.fc2(x) # end with two layers

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
    
    epochs = 3
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
    """Analyze and visualize the trained model with better layout"""
    
    # Create first figure for training metrics
    fig1, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))
    
    # Plot 1: Training Loss
    ax1.plot(train_losses, 'b-', linewidth=2, marker='o', markersize=4)
    ax1.set_title('Training Loss Over Time', fontsize=14, fontweight='bold', pad=20)
    ax1.set_xlabel('Batch (x100)', fontsize=12)
    ax1.set_ylabel('Loss', fontsize=12)
    ax1.grid(True, alpha=0.3)
    ax1.tick_params(labelsize=10)
    
    # Plot 2: Training vs Test Accuracy
    epochs = range(1, len(train_accuracies) + 1)
    ax2.plot(epochs, train_accuracies, 'g-', label='Training Accuracy', linewidth=2, marker='s', markersize=6)
    ax2.plot(epochs, test_accuracies, 'r-', label='Test Accuracy', linewidth=2, marker='^', markersize=6)
    ax2.set_title('Training vs Test Accuracy', fontsize=14, fontweight='bold', pad=20)
    ax2.set_xlabel('Epoch', fontsize=12)
    ax2.set_ylabel('Accuracy (%)', fontsize=12)
    ax2.legend(fontsize=11)
    ax2.grid(True, alpha=0.3)
    ax2.tick_params(labelsize=10)
    
    plt.tight_layout(pad=3.0)
    plt.show()
    
    # Create second figure for model architecture
    fig2, ax3 = plt.subplots(1, 1, figsize=(12, 8))
    
    model_params = []
    model_layers = []
    for name, param in model.named_parameters():
        if param.requires_grad:
            # Clean up layer names for better display
            clean_name = name.replace('.weight', ' (weights)').replace('.bias', ' (bias)')
            model_layers.append(clean_name)
            model_params.append(param.numel())
    
    colors = ['#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4', '#FFEAA7', '#DDA0DD']
    bars = ax3.barh(model_layers, model_params, color=colors[:len(model_layers)])
    ax3.set_title('Model Parameters by Layer', fontsize=16, fontweight='bold', pad=20)
    ax3.set_xlabel('Number of Parameters', fontsize=12)
    ax3.tick_params(axis='y', labelsize=10)
    ax3.tick_params(axis='x', labelsize=10)
    
    # Add value labels on bars
    for i, (bar, value) in enumerate(zip(bars, model_params)):
        ax3.text(value + max(model_params) * 0.01, bar.get_y() + bar.get_height()/2, 
                f'{value:,}', ha='left', va='center', fontsize=10, fontweight='bold')
    
    plt.tight_layout(pad=3.0)
    plt.show()
    
    # Create third figure for sample predictions
    fig3 = plt.figure(figsize=(16, 10))
    
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.5,), (0.5,))
    ])
    testset = torchvision.datasets.MNIST(root='./data', train=False, download=True, transform=transform)
    testLoader = DataLoader(testset, batch_size=12, shuffle=True)
    
    model.eval()
    with torch.no_grad():
        images, labels = next(iter(testLoader))
        outputs = model(images)
        _, predicted = torch.max(outputs, 1)
    
    # Create a grid of sample predictions
    for i in range(min(12, len(images))):
        ax = plt.subplot(3, 4, i + 1)
        img = images[i].squeeze().numpy()
        plt.imshow(img, cmap='gray')
        
        is_correct = labels[i].item() == predicted[i].item()
        title_color = 'green' if is_correct else 'red'
        status = '✓' if is_correct else '✗'
        
        plt.title(f'{status} True: {labels[i].item()}, Pred: {predicted[i].item()}', 
                 fontsize=12, fontweight='bold', color=title_color, pad=10)
        plt.axis('off')
    
    plt.suptitle('Sample Predictions', fontsize=18, fontweight='bold', y=0.98)
    plt.tight_layout(rect=[0, 0, 1, 0.95])
    plt.show()
    
    # Print model summary
    total_params = sum(p.numel() for p in model.parameters())
    trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
    
    print(f"\n{'='*50}")
    print(f"{'MODEL SUMMARY':^50}")
    print(f"{'='*50}")
    print(f"Total parameters: {total_params:,}")
    print(f"Trainable parameters: {trainable_params:,}")
    print(f"Final training accuracy: {train_accuracies[-1]:.2f}%")
    print(f"Final test accuracy: {test_accuracies[-1]:.2f}%")
    print(f"{'='*50}")

def test_single_prediction(model):
    """Test the model on a single random image with better visualization"""
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
    
    # Create a better visualization
    fig, axes = plt.subplots(1, 3, figsize=(16, 5))
    
    # Show image
    axes[0].imshow(image.squeeze().numpy(), cmap='gray')
    is_correct = true_label == predicted_label
    title_color = 'green' if is_correct else 'red'
    status = '✓ Correct' if is_correct else '✗ Incorrect'
    
    axes[0].set_title(f'{status}\nTrue: {true_label} | Predicted: {predicted_label}\nConfidence: {confidence:.1%}', 
                     fontsize=14, fontweight='bold', color=title_color, pad=15)
    axes[0].axis('off')
    
    # Show probability distribution
    probs = probabilities[0].numpy()
    colors = ['red' if i == predicted_label else 'lightblue' for i in range(10)]
    bars = axes[1].bar(range(10), probs, color=colors, edgecolor='black', linewidth=1)
    axes[1].set_title('Prediction Probabilities', fontsize=14, fontweight='bold', pad=15)
    axes[1].set_xlabel('Digit', fontsize=12)
    axes[1].set_ylabel('Probability', fontsize=12)
    axes[1].set_xticks(range(10))
    axes[1].grid(True, alpha=0.3, axis='y')
    
    # Add percentage labels on bars
    for bar, prob in zip(bars, probs):
        if prob > 0.01:  # Only show labels for probabilities > 1%
            axes[1].text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.01, 
                        f'{prob:.1%}', ha='center', va='bottom', fontsize=10, fontweight='bold')
    
    # Show top 3 predictions
    top3_idx = torch.topk(probabilities[0], 3).indices.numpy()
    top3_probs = torch.topk(probabilities[0], 3).values.numpy()
    
    colors_top3 = ['gold', 'silver', '#CD7F32']  # Gold, silver, bronze
    bars = axes[2].barh(range(3), top3_probs, color=colors_top3, edgecolor='black', linewidth=1)
    axes[2].set_yticks(range(3))
    axes[2].set_yticklabels([f'#{i+1}: Digit {idx} ({prob:.1%})' for i, (idx, prob) in enumerate(zip(top3_idx, top3_probs))])
    axes[2].set_title('Top 3 Predictions', fontsize=14, fontweight='bold', pad=15)
    axes[2].set_xlabel('Probability', fontsize=12)
    axes[2].grid(True, alpha=0.3, axis='x')
    
    plt.tight_layout(pad=3.0)
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
