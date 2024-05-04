#include <iostream>

using namespace std;

template<typename T>
struct TreeNode {
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<typename T>
class BinarySearchTree {
private:
    TreeNode<T> *root;

    TreeNode<T> *insertRecursive(TreeNode<T> *root, T val);

    TreeNode<T> *deleteRecursive(TreeNode<T> *root, T val);

    T minValue(TreeNode<T> *root);

    bool searchRecursive(TreeNode<T> *root, T val);

    void printInOrderRecursive(TreeNode<T> *root);

public:
    BinarySearchTree();

    void insert(T val);

    void remove(T val);

    bool search(T val);

    void printInOrder();
};