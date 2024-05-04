#include "BinaryTreeLL.h"

using namespace std;

Node::Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
}

int Node::get_data() { return data; }

BinaryTree::BinaryTree() { root = NULL; }

void BinaryTree::insert_node(Node *&node, int data) {
    if (node == NULL) {
        node = new Node(data);
    } else {
        if (data < node->get_data()) {
            insert_node(node->left, data);
        } else {
            insert_node(node->right, data);
        }
    }
}

void BinaryTree::insert(int val) { insert_node(root, val); }

void BinaryTree::in_order(Node *node) {
    if (node == NULL) {
        return;
    }
    in_order(node->left);
    cout << node->get_data() << " ";
    in_order(node->right);
}

void BinaryTree::inorder() {
    in_order(root);
    cout << endl;
}

void BinaryTree::pre_order(Node *node) {
    if (node == NULL) {
        return;
    }
    cout << node->get_data() << " ";
    pre_order(node->left);
    pre_order(node->right);
}

void BinaryTree::preorder() {
    pre_order(root);
    cout << endl;
}

void BinaryTree::post_order(Node *node) {
    if (node == NULL) {
        return;
    }
    post_order(node->left);
    post_order(node->right);
    cout << node->get_data() << " ";
}

void BinaryTree::postorder() {
    post_order(root);
    cout << endl;
}