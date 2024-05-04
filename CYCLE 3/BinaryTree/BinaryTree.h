#include <iostream>

using namespace std;

class BinaryTree {
private:
    int *tree;
    int size;
    int back;
public:
    BinaryTree(int);

    void pushback(int);

    void insert(int);

    int parentIndex(int);

    int rightchildIndex(int);

    int leftchildIndex(int);

    void inorderTraversal(int index);

    void preorderTraversal(int index);

    void postorderTraversal(int index);
};