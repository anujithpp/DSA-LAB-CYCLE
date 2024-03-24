#include "Array.cpp"

using namespace std;

int main() {
    Array<int> arr;

    int choice, key, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Linear Search\n";
        cout << "8. Display Array\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at the beginning: ";
                cin >> key;
                arr.insertAtBeginning(key);
                break;
            case 2:
                cout << "Enter element to insert at the end: ";
                cin >> key;
                arr.insertAtEnd(key);
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> key;
                cout << "Enter position to insert at: ";
                cin >> index;
                arr.insertAtPosition(key, index);
                break;
            case 4:
                arr.deleteAtBeginning();
                break;
            case 5:
                arr.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> index;
                arr.deleteAtPosition(index);
                break;
            case 7:
                cout << "Enter element to search for: ";
                cin >> key;
                index = arr.linearSearch(key);
                if (index != -1) {
                    cout << "Element found at position " << index << endl;
                } else {
                    cout << "Element not found in the array." << endl;
                }
                break;
            case 8:
                cout << "Array: " << arr << endl;
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
