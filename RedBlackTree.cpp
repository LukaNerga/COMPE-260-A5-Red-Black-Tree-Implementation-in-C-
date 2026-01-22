#include "RedBlackTree.h"
#include <iostream>

using namespace std;

RedBlackTree::RedBlackTree() {
    nil = new RedBlackTreeNode(0, BLACK);
    root = nil;
}

RedBlackTree::~RedBlackTree() {
    // Memory cleanup omitted for simplicity
}

void RedBlackTree::insert(int value) {
    RedBlackTreeNode* z = new RedBlackTreeNode(value, RED, nil, nil, nil);
    RedBlackTreeNode* y = nil;
    RedBlackTreeNode* x = root;

    while (x != nil) {
        y = x;
        if (z->value < x->value)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == nil)
        root = z;
    else if (z->value < y->value)
        y->left = z;
    else
        y->right = z;

    insertFixup(z);
}

void RedBlackTree::insertFixup(RedBlackTreeNode* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RedBlackTreeNode* y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            RedBlackTreeNode* y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::leftRotate(RedBlackTreeNode* x) {
    RedBlackTreeNode* y = x->right;
    x->right = y->left;
    if (y->left != nil)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == nil)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(RedBlackTreeNode* y) {
    RedBlackTreeNode* x = y->left;
    y->left = x->right;
    if (x->right != nil)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == nil)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

RedBlackTreeNode* RedBlackTree::search(int value) const {
    return searchNode(root, value);
}

RedBlackTreeNode* RedBlackTree::searchNode(RedBlackTreeNode* node, int value) const {
    if (node == nil || node->value == value)
        return node;
    return value < node->value
        ? searchNode(node->left, value)
        : searchNode(node->right, value);
}

void RedBlackTree::preorder() const { preorderTraversal(root); }
void RedBlackTree::inorder() const { inorderTraversal(root); }
void RedBlackTree::postorder() const { postorderTraversal(root); }

void RedBlackTree::preorderTraversal(RedBlackTreeNode* node) const {
    if (node != nil) {
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void RedBlackTree::inorderTraversal(RedBlackTreeNode* node) const {
    if (node != nil) {
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }
}

void RedBlackTree::postorderTraversal(RedBlackTreeNode* node) const {
    if (node != nil) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }
}
