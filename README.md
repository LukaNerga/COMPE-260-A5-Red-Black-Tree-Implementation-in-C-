# Red-Black Tree Implementation (C++)

A full **Red-Black Tree** implementation in **C++**, designed to demonstrate advanced **data structures**, **pointer-based tree manipulation**, and **self-balancing binary search trees**.

This project separates code cleanly into header (`.h`) and source (`.cpp`) files following good C++ practices.

---

## Overview

- **Language:** C++
- **Data Structure:** Red-Black Tree
- **Type:** Self-balancing Binary Search Tree
- **Purpose:** Educational / Academic use

---

## Features

- Insert nodes while maintaining Red-Black Tree properties
- Delete nodes with proper rebalancing
- Search for values
- Tree traversals:
  - Preorder
  - Inorder
  - Postorder
- Automatic rotations and recoloring
- Sentinel `nil` node implementation

---

## Red-Black Tree Properties

This implementation enforces all Red-Black Tree rules:

1. Every node is either **RED** or **BLACK**
2. The root is always **BLACK**
3. All leaves (`nil`) are **BLACK**
4. Red nodes cannot have red children
5. Every path from a node to its leaves contains the same number of black nodes

---

## Project Structure

├── main.cpp # Program entry & tests
├── RedBlackTree.h # Tree class declaration
├── RedBlackTree.cpp # Tree logic & algorithms
├── RedBlackTreeNode.h # Node structure & color enum
└── README.md


---

## File Descriptions

### `main.cpp`
- Creates a Red-Black Tree
- Inserts test values
- Prints all tree traversals
- Searches for a value
- Deletes a node and prints the tree again

---

### `RedBlackTreeNode.h`
- Defines:
  - Node structure
  - Color enum (`RED`, `BLACK`)
- Stores:
  - Value
  - Color
  - Parent, left, and right pointers

---

### `RedBlackTree.h`
- Declares the `RedBlackTree` class
- Public API:
  - `insert(int)`
  - `deleteNode(int)`
  - `search(int)`
  - Traversal functions
- Private helpers:
  - Rotations
  - Fix-up logic
  - Utility traversal and search functions

---

### `RedBlackTree.cpp`
- Implements:
  - Insertion algorithm
  - Rotation logic
  - Fix-up procedures
  - Search and traversal logic
- Maintains tree balance automatically

---

## Build & Run

### Compile

```bash
g++ -std=c++17 main.cpp RedBlackTree.cpp -o rbtree

./rbtree

Preorder: 12 3 18 15 25
Inorder: 3 12 15 18 25
Postorder: 3 15 25 18 12
15 Found in the tree
After Deletion of 15, Inorder: 3 12 18 25



Notes
Uses a sentinel nil node instead of nullptr
Designed for clarity over performance optimizations
Suitable for:
Data Structures coursework
Interview preparation
Learning self-balancing trees
