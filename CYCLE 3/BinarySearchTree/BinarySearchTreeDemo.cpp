#include "BinarySearchTree.cpp"

int main() {
    BinarySearchTree<int> bst;

    int n;
    cout << "Enter the number of values to insert: " << endl;
    cin >> n;

    cout << "Enter the values: " << endl;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.insert(value);
    }

    cout << "In-order traversal of the BST: ";
    bst.printInOrder();


    int searchValue;
    cout << "Enter value to search: " << endl;
    cin >> searchValue;
    cout << "Search for value " << searchValue << ": " << bst.search(searchValue) << endl;


    int deleteValue;
    cout << "Enter the value to delete: " << endl;
    cin >> deleteValue;
    bst.remove(deleteValue);
    cout << "After deleting " << deleteValue << ": ";
    bst.printInOrder();

    return 0;
}