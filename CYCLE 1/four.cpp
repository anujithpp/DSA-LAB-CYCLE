#include "LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<int> list{}; // Creating a linked list of integers

    int choice, key, position;

    cout << "LINKED LIST" ;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at a specified Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from a specified Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at the beginning: ";
                cin >> key;
                list.insertAtBeginning(key);
                break;
            case 2:
                cout << "Enter element to insert at the end: ";
                cin >> key;
                list.insertAtEnd(key);
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> key;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtPosition(key, position);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 7:
                cout << "Linked List: ";
                list.display();
                cout << endl;
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
