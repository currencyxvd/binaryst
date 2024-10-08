#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> bst;

    // Insert nodes into the tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal (LNR): ";
    bst.inOrderTraversal();
    std::cout << std::endl;

    // Search for nodes
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 100: " << (bst.search(100) ? "Found" : "Not Found") << std::endl;

    // Remove a node
    std::cout << "Delete 40" << std::endl;
    bst.remove(40);

    std::cout << "Inorder Traversal after deletion (LNR): ";
    bst.inOrderTraversal();
    std::cout << std::endl;

    return 0;
}
