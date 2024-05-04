#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    deleteNode(root);
}

void BinaryTree::deleteNode(Node *node) {
    if (node == nullptr) {
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

void BinaryTree::insertRecursive(Node *current, int value) {
    if (value < current->data) {
        if (current->left == nullptr) {
            current->left = new Node(value);
        } else {
            insertRecursive(current->left, value);
        }
    } else {
        if (current->right == nullptr) {
            current->right = new Node(value);
        } else {
            insertRecursive(current->right, value);
        }
    }
}

void BinaryTree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    insertRecursive(root, value);
}

void BinaryTree::inOrderTraversal(int index) {
    if (root == nullptr) {
        return; // Empty tree
    }

    if (root->left != nullptr) {
        inOrderTraversal(index + 1); // Traverse left subtree
    }

    std::cout << root->data << " ";

    if (root->right != nullptr) {
        inOrderTraversal(index + 1); // Traverse right subtree
    }
}

void BinaryTree::inOrder() {
    inOrderTraversal(1); // Start traversal from root
    std::cout << std::endl;
}

void BinaryTree::preOrderTraversal(int index) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    if (root->left != nullptr) {
        preOrderTraversal(index + 1);
    }
    if (root->right != nullptr) {
        preOrderTraversal(index + 1);
    }
}

void BinaryTree::preOrder() {
    preOrderTraversal(1);
    std::cout << std::endl;
}

void BinaryTree::postOrderTraversal(int index) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        postOrderTraversal(index + 1);
    }
    if (root->right != nullptr) {
        postOrderTraversal(index + 1);
    }
    std::cout << root->data << " ";
}

void BinaryTree::postOrder() {
    postOrderTraversal(1);
    std::cout << std::endl;
}