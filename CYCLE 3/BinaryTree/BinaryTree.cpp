#include "BinaryTree.h"

BinaryTree::BinaryTree(int n) {
    size = n;
    back = n - 1;
    tree = new int[n];
}

void BinaryTree::pushback(int x) { tree[back--] = x; }

void BinaryTree::insert(int val) { pushback(val); }

int BinaryTree::parentIndex(int index) { return (index - 1) / 2; }

int BinaryTree::leftchildIndex(int index) { return 2 * index + 1; }

int BinaryTree::rightchildIndex(int index) { return 2 * index + 2; }

void BinaryTree::inorderTraversal(int index) {
    if (index < size) {
        inorderTraversal(leftchildIndex(index));
        cout << tree[index] << " ";
        inorderTraversal(rightchildIndex(index));
    }
}

void BinaryTree::preorderTraversal(int index) {
    if (index < size) {
        cout << tree[index] << " ";
        preorderTraversal(leftchildIndex(index));
        preorderTraversal(rightchildIndex(index));
    }
}

void BinaryTree::postorderTraversal(int index) {
    if (index < size) {
        postorderTraversal(leftchildIndex(index));
        postorderTraversal(rightchildIndex(index));
        cout << tree[index] << " ";
    }
}