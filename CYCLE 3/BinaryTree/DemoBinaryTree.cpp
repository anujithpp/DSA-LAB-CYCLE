#include "BinaryTree.cpp"

int main() {
    BinaryTree tree;

    // Insert some test values
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);

    std::cout << "In-order traversal: ";
    tree.inOrder();

    std::cout << "Pre-order traversal: ";
    tree.preOrder();
    std::cout << "Post-order traversal: ";
    tree.postOrder();

    return 0;
}
