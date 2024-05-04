#include "BinaryTreeLL.cpp"

int main() {
    BinaryTree tree;
    int val, num;
    cout << "Enter the number of nodes:";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Enter the value of node:";
        cin >> val;
        tree.insert(val);
    }
    cout << "In-order Traversal: ";
    tree.inorder();
    cout << "Pre-order Traversal: ";
    tree.preorder();
    cout << "Post-order Traversal: ";
    tree.postorder();
    return 0;
}