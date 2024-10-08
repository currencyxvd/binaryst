#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions for working with the tree
    Node* insert(Node* node, T value) {
        if (!node) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    Node* search(Node* node, T value) {
        if (!node || node->data == value) return node;

        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    Node* remove(Node* node, T value) {
        if (!node) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node found
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void inOrderTraversal(Node* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    bool search(T value) {
        return search(root, value) != nullptr;
    }

    void remove(T value) {
        root = remove(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
    }
};

#endif
