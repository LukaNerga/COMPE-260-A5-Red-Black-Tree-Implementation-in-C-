#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "RedBlackTreeNode.h"

class RedBlackTree {
private:
    RedBlackTreeNode* root;
    RedBlackTreeNode* nil;

    void leftRotate(RedBlackTreeNode* x);
    void rightRotate(RedBlackTreeNode* y);
    void insertFixup(RedBlackTreeNode* z);
    void deleteFixup(RedBlackTreeNode* x);
    void transplant(RedBlackTreeNode* u, RedBlackTreeNode* v);
    RedBlackTreeNode* minimum(RedBlackTreeNode* node) const;

    void preorderTraversal(RedBlackTreeNode* node) const;
    void inorderTraversal(RedBlackTreeNode* node) const;
    void postorderTraversal(RedBlackTreeNode* node) const;
    RedBlackTreeNode* searchNode(RedBlackTreeNode* node, int value) const;

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(int value);
    void deleteNode(int value);
    RedBlackTreeNode* search(int value) const;

    void preorder() const;
    void inorder() const;
    void postorder() const;
};

#endif // REDBLACKTREE_H
