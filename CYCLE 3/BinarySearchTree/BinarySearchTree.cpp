#include "BinarySearchTree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template<typename T>
void BinarySearchTree<T>::insert(T val) {
    root = insertRecursive(root, val);
}

template<typename T>
TreeNode<T> *BinarySearchTree<T>::insertRecursive(TreeNode<T> *root, T val) {
    if (root == nullptr) {
        root = new TreeNode<T>(val);
        return root;
    }

    if (val < root->val) {
        root->left = insertRecursive(root->left, val);
    } else if (val > root->val) {
        root->right = insertRecursive(root->right, val);
    }

    return root;
}

template<typename T>
void BinarySearchTree<T>::remove(T val) {
    root = deleteRecursive(root, val);
}

template<typename T>
TreeNode<T> *BinarySearchTree<T>::deleteRecursive(TreeNode<T> *root, T val) {
    if (root == nullptr) {
        return root;
    }

    if (val < root->val) {
        root->left = deleteRecursive(root->left, val);
    } else if (val > root->val) {
        root->right = deleteRecursive(root->right, val);
    } else {
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }

        root->val = minValue(root->right);

        root->right = deleteRecursive(root->right, root->val);
    }

    return root;
}

template<typename T>
T BinarySearchTree<T>::minValue(TreeNode<T> *root) {
    T minVal = root->val;
    while (root->left != nullptr) {
        minVal = root->left->val;
        root = root->left;
    }
    return minVal;
}

template<typename T>
bool BinarySearchTree<T>::search(T val) {
    return searchRecursive(root, val);
}

template<typename T>
bool BinarySearchTree<T>::searchRecursive(TreeNode<T> *root, T val) {
    if (root == nullptr) {
        return false;
    }

    if (val == root->val) {
        return true;
    }

    if (val < root->val) {
        return searchRecursive(root->left, val);
    }

    return searchRecursive(root->right, val);
}

template<typename T>
void BinarySearchTree<T>::printInOrder() {
    printInOrderRecursive(root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::printInOrderRecursive(TreeNode<T> *root) {
    if (root != nullptr) {
        printInOrderRecursive(root->left);
        cout << root->val << " ";
        printInOrderRecursive(root->right);
    }
}