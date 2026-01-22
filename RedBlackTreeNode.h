#ifndef REDBLACKTREENODE_H
#define REDBLACKTREENODE_H

enum ColorType { RED, BLACK };

class RedBlackTreeNode {
    friend class RedBlackTree;

private:
    int value;
    ColorType color;
    RedBlackTreeNode* parent;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;

public:
    RedBlackTreeNode()
        : value(0), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}

    RedBlackTreeNode(int inValue, ColorType inColor,
                     RedBlackTreeNode* inLeft = nullptr,
                     RedBlackTreeNode* inRight = nullptr,
                     RedBlackTreeNode* inParent = nullptr)
        : value(inValue), color(inColor),
          parent(inParent), left(inLeft), right(inRight) {}

    int getValue() const { return value; }
    ColorType getColor() const { return color; }
};

#endif // REDBLACKTREENODE_H
