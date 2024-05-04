#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int);

    int get_data();
};

class BinaryTree {
private:
    Node *root;

    void insert_node(Node *&, int);

    void in_order(Node *);

    void pre_order(Node *);

    void post_order(Node *);

public:
    BinaryTree();

    void insert(int);

    void inorder();

    void preorder();

    void postorder();

    void level_order();
};