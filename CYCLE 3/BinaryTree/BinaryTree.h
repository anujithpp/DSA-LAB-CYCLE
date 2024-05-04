#include <iostream>

class Node {
public:
    Node *left;
    Node *right;
    int data;

    Node(int value) {
        data = value;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *newRight) {
        right = newRight;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *newLeft) {
        left = newLeft;
    }
};

class BinaryTree {
private:
    Node *root;

    void inOrderTraversal(int index);

    void preOrderTraversal(int index);

    void postOrderTraversal(int index);

public:
    BinaryTree();

    ~BinaryTree();

    void insert(int value);

    void inOrder();

    void preOrder();

    void postOrder();

    void deleteNode(Node *node);

    void insertRecursive(Node *current, int value);
};