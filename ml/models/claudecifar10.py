import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torch.utils.data import DataLoader
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
import numpy as np
from tqdm import tqdm
import time
import signal
import sys
import os
import json
from datetime import datetime

# Global flag for graceful shutdown
interrupted = False

def signal_handler(signum, frame):
    global interrupted
    print('\n\nReceived Ctrl+C! Finishing current batch and saving checkpoint...')
    interrupted = True

# Register the signal handler
signal.signal(signal.SIGINT, signal_handler)

# Set device
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(f'Using device: {device}')

# CIFAR-10 classes
classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

# Minimal data preprocessing - no augmentation for faster training
transform_train = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010))
])

transform_test = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010))
])

# Load datasets - increased batch size for efficiency
trainset = torchvision.datasets.CIFAR10(root='./data', train=True, download=True, transform=transform_train)
trainloader = DataLoader(trainset, batch_size=256, shuffle=True, num_workers=2, pin_memory=True)

testset = torchvision.datasets.CIFAR10(root='./data', train=False, download=True, transform=transform_test)
testloader = DataLoader(testset, batch_size=256, shuffle=False, num_workers=2, pin_memory=True)

# Enhanced CNN Architecture - simplified but effective for fast training
class AdvancedCNN(nn.Module):
    def __init__(self, num_classes=10):
        super(AdvancedCNN, self).__init__()
        
        # Block 1: 32x32 -> 16x16
        self.conv1 = nn.Conv2d(3, 64, 3, padding=1)
        self.bn1 = nn.BatchNorm2d(64)
        self.conv2 = nn.Conv2d(64, 64, 3, padding=1)
        self.bn2 = nn.BatchNorm2d(64)
        
        # Block 2: 16x16 -> 8x8
        self.conv3 = nn.Conv2d(64, 128, 3, padding=1)
        self.bn3 = nn.BatchNorm2d(128)
        self.conv4 = nn.Conv2d(128, 128, 3, padding=1)
        self.bn4 = nn.BatchNorm2d(128)
        
        # Block 3: 8x8 -> 4x4
        self.conv5 = nn.Conv2d(128, 256, 3, padding=1)
        self.bn5 = nn.BatchNorm2d(256)
        self.conv6 = nn.Conv2d(256, 256, 3, padding=1)
        self.bn6 = nn.BatchNorm2d(256)
        
        # Block 4: 4x4 -> 4x4
        self.conv7 = nn.Conv2d(256, 512, 3, padding=1)
        self.bn7 = nn.BatchNorm2d(512)
        self.conv8 = nn.Conv2d(512, 512, 3, padding=1)
        self.bn8 = nn.BatchNorm2d(512)
        
        # Global average pooling and classifier
        self.avgpool = nn.AdaptiveAvgPool2d((1, 1))
        self.dropout = nn.Dropout(0.3)
        self.fc = nn.Linear(512, num_classes)
        
        # Initialize weights
        self._initialize_weights()
    
    def _initialize_weights(self):
        """Initialize weights using He initialization"""
        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                nn.init.kaiming_normal_(m.weight, mode='fan_out', nonlinearity='relu')
                if m.bias is not None:
                    nn.init.constant_(m.bias, 0)
            elif isinstance(m, nn.BatchNorm2d):
                nn.init.constant_(m.weight, 1)
                nn.init.constant_(m.bias, 0)
            elif isinstance(m, nn.Linear):
                nn.init.normal_(m.weight, 0, 0.01)
                nn.init.constant_(m.bias, 0)
    
    def forward(self, x):
        # Block 1
        x = F.relu(self.bn1(self.conv1(x)))
        x = F.relu(self.bn2(self.conv2(x)))
        x = F.max_pool2d(x, 2)  # 32x32 -> 16x16
        
        # Block 2
        x = F.relu(self.bn3(self.conv3(x)))
        x = F.relu(self.bn4(self.conv4(x)))
        x = F.max_pool2d(x, 2)  # 16x16 -> 8x8
        
        # Block 3
        x = F.relu(self.bn5(self.conv5(x)))
        x = F.relu(self.bn6(self.conv6(x)))
        x = F.max_pool2d(x, 2)  # 8x8 -> 4x4
        
        # Block 4
        x = F.relu(self.bn7(self.conv7(x)))
        x = F.relu(self.bn8(self.conv8(x)))
        
        # Global average pooling and classification
        x = self.avgpool(x)
        x = torch.flatten(x, 1)
        x = self.dropout(x)
        x = self.fc(x)
        
        return x

# Checkpoint management
def save_checkpoint(model, optimizer, scheduler, epoch, batch_idx, train_losses, train_accs, 
                   test_losses, test_accs, best_acc, batch_losses, filename='checkpoint.pth'):
    """Save training checkpoint with all necessary information"""
    checkpoint = {
        'epoch': epoch,
        'batch_idx': batch_idx,
        'model_state_dict': model.state_dict(),
        'optimizer_state_dict': optimizer.state_dict(),
        'scheduler_state_dict': scheduler.state_dict(),
        'train_losses': train_losses,
        'train_accs': train_accs,
        'test_losses': test_losses,
        'test_accs': test_accs,
        'best_acc': best_acc,
        'batch_losses': batch_losses,
        'timestamp': datetime.now().isoformat()
    }
    torch.save(checkpoint, filename)
    print(f'Checkpoint saved to {filename}')

def load_checkpoint(filename='checkpoint.pth'):
    """Load training checkpoint"""
    if os.path.exists(filename):
        checkpoint = torch.load(filename, map_location=device)
        print(f'Checkpoint loaded from {filename}')
        print(f'Resuming from epoch {checkpoint["epoch"]}, batch {checkpoint["batch_idx"]}')
        return checkpoint
    return None

def analyze_model(model, train_losses, train_accuracies, test_accuracies, batch_losses=None):
    """Analyze and visualize the trained model with better layout"""
    
    # Create first figure for training metrics
    fig1, axes = plt.subplots(2, 2, figsize=(15, 12))
    
    # Plot 1: Training Loss Over Batches (if available)
    if batch_losses:
        axes[0, 0].plot(batch_losses, 'b-', linewidth=1, alpha=0.7)
        axes[0, 0].set_title('Training Loss Over Batches', fontsize=14, fontweight='bold', pad=20)
        axes[0, 0].set_xlabel('Batch', fontsize=12)
        axes[0, 0].set_ylabel('Loss', fontsize=12)
        axes[0, 0].grid(True, alpha=0.3)
        axes[0, 0].tick_params(labelsize=10)
    
    # Plot 2: Training Loss Over Epochs
    if train_losses:
        axes[0, 1].plot(train_losses, 'r-', linewidth=2, marker='o', markersize=4)
        axes[0, 1].set_title('Training Loss Over Epochs', fontsize=14, fontweight='bold', pad=20)
        axes[0, 1].set_xlabel('Epoch', fontsize=12)
        axes[0, 1].set_ylabel('Loss', fontsize=12)
        axes[0, 1].grid(True, alpha=0.3)
        axes[0, 1].tick_params(labelsize=10)
    
    # Plot 3: Training vs Test Accuracy
    if train_accuracies and test_accuracies:
        epochs = range(1, len(train_accuracies) + 1)
        axes[1, 0].plot(epochs, train_accuracies, 'g-', label='Training Accuracy', linewidth=2, marker='s', markersize=6)
        axes[1, 0].plot(epochs, test_accuracies, 'r-', label='Test Accuracy', linewidth=2, marker='^', markersize=6)
        axes[1, 0].set_title('Training vs Test Accuracy', fontsize=14, fontweight='bold', pad=20)
        axes[1, 0].set_xlabel('Epoch', fontsize=12)
        axes[1, 0].set_ylabel('Accuracy (%)', fontsize=12)
        axes[1, 0].legend(fontsize=11)
        axes[1, 0].grid(True, alpha=0.3)
        axes[1, 0].tick_params(labelsize=10)
    
    # Plot 4: Model Parameters by Layer
    model_params = []
    model_layers = []
    for name, param in model.named_parameters():
        if param.requires_grad:
            # Clean up layer names for better display
            clean_name = name.replace('.weight', ' (weights)').replace('.bias', ' (bias)')
            model_layers.append(clean_name[:25])  # Truncate long names
            model_params.append(param.numel())
    
    colors = plt.cm.Set3(np.linspace(0, 1, len(model_layers)))
    bars = axes[1, 1].barh(range(len(model_layers)), model_params, color=colors)
    axes[1, 1].set_title('Model Parameters by Layer', fontsize=14, fontweight='bold', pad=20)
    axes[1, 1].set_xlabel('Number of Parameters', fontsize=12)
    axes[1, 1].set_yticks(range(len(model_layers)))
    axes[1, 1].set_yticklabels(model_layers, fontsize=8)
    axes[1, 1].tick_params(axis='x', labelsize=10)
    
    # Add value labels on bars
    for i, (bar, value) in enumerate(zip(bars, model_params)):
        axes[1, 1].text(value + max(model_params) * 0.01, bar.get_y() + bar.get_height()/2, 
                f'{value:,}', ha='left', va='center', fontsize=8, fontweight='bold')
    
    plt.tight_layout(pad=3.0)
    plt.savefig('model_analysis.png', dpi=300, bbox_inches='tight')
    plt.show()

# Training function with interrupt handling
def train_epoch(model, trainloader, criterion, optimizer, device, epoch, batch_losses):
    global interrupted
    model.train()
    running_loss = 0.0
    correct = 0
    total = 0
    
    pbar = tqdm(trainloader, desc=f'Epoch {epoch+1}')
    for batch_idx, (inputs, targets) in enumerate(pbar):
        if interrupted:
            return running_loss/(batch_idx+1) if batch_idx > 0 else 0, 100.*correct/total if total > 0 else 0, batch_idx
        
        inputs, targets = inputs.to(device), targets.to(device)
        
        optimizer.zero_grad()
        outputs = model(inputs)
        loss = criterion(outputs, targets)
        loss.backward()
        optimizer.step()
        
        # Update learning rate every batch for OneCycleLR
        scheduler.step()
        
        running_loss += loss.item()
        batch_losses.append(loss.item())
        _, predicted = outputs.max(1)
        total += targets.size(0)
        correct += predicted.eq(targets).sum().item()
        
        pbar.set_postfix({
            'Loss': f'{running_loss/(batch_idx+1):.3f}',
            'Acc': f'{100.*correct/total:.2f}%'
        })
    
    return running_loss/len(trainloader), 100.*correct/total, len(trainloader)

# Testing function
def test_epoch(model, testloader, criterion, device):
    model.eval()
    test_loss = 0
    correct = 0
    total = 0
    
    with torch.no_grad():
        for inputs, targets in tqdm(testloader, desc='Testing'):
            inputs, targets = inputs.to(device), targets.to(device)
            outputs = model(inputs)
            loss = criterion(outputs, targets)
            
            test_loss += loss.item()
            _, predicted = outputs.max(1)
            total += targets.size(0)
            correct += predicted.eq(targets).sum().item()
    
    return test_loss/len(testloader), 100.*correct/total

# Enhanced training loop with resume capability
def train_model(model, trainloader, testloader, criterion, optimizer, scheduler, epochs=100, resume=True):
    global interrupted
    
    # Initialize tracking variables
    train_losses, train_accs = [], []
    test_losses, test_accs = [], []
    batch_losses = []
    best_acc = 0
    start_epoch = 0
    
    # Try to resume from checkpoint
    if resume:
        checkpoint = load_checkpoint()
        if checkpoint:
            model.load_state_dict(checkpoint['model_state_dict'])
            optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
            scheduler.load_state_dict(checkpoint['scheduler_state_dict'])
            start_epoch = checkpoint['epoch']
            train_losses = checkpoint['train_losses']
            train_accs = checkpoint['train_accs']
            test_losses = checkpoint['test_losses']
            test_accs = checkpoint['test_accs']
            best_acc = checkpoint['best_acc']
            batch_losses = checkpoint.get('batch_losses', [])
            
            print(f'Resumed training from epoch {start_epoch + 1}')
            print(f'Previous best accuracy: {best_acc:.2f}%')
    
    print(f'Starting/Resuming training for {epochs - start_epoch} epochs...\n')
    
    try:
        for epoch in range(start_epoch, epochs):
            if interrupted:
                break
                
            start_time = time.time()
            
            print(f'Epoch {epoch+1}/{epochs}')
            print('-' * 50)
            
            # Training
            train_loss, train_acc, batches_completed = train_epoch(
                model, trainloader, criterion, optimizer, device, epoch, batch_losses
            )
            
            if interrupted:
                # Save checkpoint and break
                save_checkpoint(model, optimizer, scheduler, epoch, batches_completed,
                              train_losses, train_accs, test_losses, test_accs, best_acc, batch_losses)
                break
            
            # Testing
            test_loss, test_acc = test_epoch(model, testloader, criterion, device)
            current_lr = optimizer.param_groups[0]['lr']
            
            # Save best model
            if test_acc > best_acc:
                best_acc = test_acc
                torch.save(model.state_dict(), 'best_cifar10_model.pth')
                print(f'New best model saved! Accuracy: {best_acc:.2f}%')
            
            # Record metrics
            train_losses.append(train_loss)
            train_accs.append(train_acc)
            test_losses.append(test_loss)
            test_accs.append(test_acc)
            
            epoch_time = time.time() - start_time
            
            print(f'Train Loss: {train_loss:.4f}, Train Acc: {train_acc:.2f}%')
            print(f'Test Loss: {test_loss:.4f}, Test Acc: {test_acc:.2f}%')
            print(f'Best Acc: {best_acc:.2f}%, LR: {current_lr:.6f}')
            print(f'Epoch time: {epoch_time:.2f}s\n')
            
            # Save checkpoint every 5 epochs
            if (epoch + 1) % 5 == 0:
                save_checkpoint(model, optimizer, scheduler, epoch + 1, 0,
                              train_losses, train_accs, test_losses, test_accs, best_acc, batch_losses)
            
            # Early stopping if accuracy is very high
            if test_acc > 95.0:
                print(f'Achieved high accuracy of {test_acc:.2f}%. Stopping early.')
                break
    
    except KeyboardInterrupt:
        print("Training interrupted by user")
    
    finally:
        # Always save final checkpoint and show analysis
        if not interrupted:
            save_checkpoint(model, optimizer, scheduler, epoch + 1, 0,
                          train_losses, train_accs, test_losses, test_accs, best_acc, batch_losses)
        
        print(f'\nTraining completed! Best test accuracy: {best_acc:.2f}%')
        
        # Show analysis graphs
        print("\nGenerating analysis graphs...")
        analyze_model(model, train_losses, train_accs, test_accs, batch_losses)
        
        # Class-wise accuracy analysis
        if len(test_accs) > 0:
            class_accuracy(model, testloader, classes, device)
    
    return train_losses, train_accs, test_losses, test_accs, best_acc

# Class-wise accuracy analysis
def class_accuracy(model, testloader, classes, device):
    model.eval()
    class_correct = list(0. for i in range(10))
    class_total = list(0. for i in range(10))
    
    with torch.no_grad():
        for inputs, targets in testloader:
            inputs, targets = inputs.to(device), targets.to(device)
            outputs = model(inputs)
            _, predicted = torch.max(outputs, 1)
            c = (predicted == targets).squeeze()
            
            for i in range(targets.size(0)):
                label = targets[i]
                class_correct[label] += c[i].item()
                class_total[label] += 1
    
    print('\nClass-wise Accuracy:')
    print('-' * 30)
    for i in range(10):
        accuracy = 100 * class_correct[i] / class_total[i] if class_total[i] > 0 else 0
        print(f'{classes[i]}: {accuracy:.2f}%')

# Initialize model
model = AdvancedCNN().to(device)
print(f'Model parameters: {sum(p.numel() for p in model.parameters()):,}')

# Loss function and optimizer - adjusted for no augmentation
criterion = nn.CrossEntropyLoss(label_smoothing=0.1)  # Label smoothing for regularization
optimizer = optim.AdamW(model.parameters(), lr=0.002, weight_decay=5e-4)  # AdamW with higher LR

# More aggressive learning rate scheduler since no augmentation
scheduler = optim.lr_scheduler.OneCycleLR(optimizer, max_lr=0.01, 
                                        steps_per_epoch=len(trainloader), 
                                        epochs=100, pct_start=0.3)

print("\n" + "="*60)
print("CIFAR-10 CNN Training with Interrupt Handling")
print("="*60)
print("Press Ctrl+C to gracefully stop training and save checkpoint")
print("The program will finish the current batch and save progress")
print("="*60 + "\n")

# Start training
train_losses, train_accs, test_losses, test_accs, best_acc = train_model(
    model, trainloader, testloader, criterion, optimizer, scheduler, epochs=100, resume=True
)

# Load best model and evaluate
if os.path.exists('best_cifar10_model.pth'):
    model.load_state_dict(torch.load('best_cifar10_model.pth'))
    _, final_acc = test_epoch(model, testloader, criterion, device)
    print(f'\nFinal test accuracy with best model: {final_acc:.2f}%')

print("\nTraining session completed!")
print("Files saved:")
print("- checkpoint.pth: Resume training from this point")
print("- best_cifar10_model.pth: Best performing model")
print("- model_analysis.png: Analysis graphs")
