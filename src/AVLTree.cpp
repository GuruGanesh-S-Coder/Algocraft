#include "AVLTree.hpp"
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(int val) {
    key = val;
    left = right = nullptr;
    height = 1;
}

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;
}

AVLNode* AVLTree::insertNode(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node; // No duplicates

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Perform rotations
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(int key) {
    root = insertNode(root, key);
}

void AVLTree::inOrderTraversal(AVLNode* node) {
    if (!node) return;
    inOrderTraversal(node->left);
    std::cout << node->key << " ";
    inOrderTraversal(node->right);
}

void AVLTree::displayInOrder() {
    inOrderTraversal(root);
    std::cout << std::endl;
}
