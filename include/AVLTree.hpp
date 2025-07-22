#ifndef AVLTREE_HPP
#define AVLTREE_HPP

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val);
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insertNode(AVLNode* node, int key);
    void inOrderTraversal(AVLNode* node);

public:
    AVLTree();
    void insert(int key);
    void displayInOrder();
};

#endif // AVLTREE_HPP
