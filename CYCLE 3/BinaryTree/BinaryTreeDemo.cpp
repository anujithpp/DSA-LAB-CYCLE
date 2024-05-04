#include "BinaryTree.cpp"

int
main() {
    int num;
    cout << "Enter the number of nodes for the tree:";
    cin >> num;
    int val;
    BinaryTree t(num);
    for (int i = 0; i < num; i++) {
        cout << "Enter the value for the node:";
        cin >> val;
        t.insert(val);
    }
    cout << "Inorder traversal:";
    t.inorderTraversal(0);
    cout << endl;
    cout << "Preorder Traversal:";
    t.preorderTraversal(0);
    cout << "\n";
    cout << "Postorder Traversal:";
    t.postorderTraversal(0);
}