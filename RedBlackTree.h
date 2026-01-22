include "RedBlackTree.h"
#include <iostream>
using namespace std;
int main() {
RedBlackTree tree;
// Test Insert
tree.insert(12);
tree.insert(18);
tree.insert(3);
tree.insert(15);
tree.insert(25);
// Test Traversals
cout << "Preorder: ";
tree.preorder();
cout << endl;
cout << "Inorder: ";
tree.inorder();
cout << endl;
cout << "Postorder: ";
tree.postorder();
cout << endl;
// Test Search
if (tree.search(15)) {
cout << "15 Found in the tree" << endl;
} else {
cout << "15 Not Found in the tree" << endl;
}
// Test Delete
tree.deleteNode(15);
cout << "After Deletion of 15, Inorder: ";
tree.inorder();
cout << endl;
return 0;
}
