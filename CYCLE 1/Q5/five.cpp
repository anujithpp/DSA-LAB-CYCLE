#include "DoublyLinkedList.cpp"

using namespace std;

int main() {
    LinkedList<int> list;
    int choice, element, position;

    do {
        cout << "\nDoubly Linked List:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at a specified Position" << endl;
        cout << "4. Delete from Beginning" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete from a specified Position" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> element;
                list.insert_at_beginning(element);
                cout << "Element inserted successfully at the beginning." << endl;
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> element;
                list.insert_at_end(element);
                cout << "Element inserted successfully at the end." << endl;
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insert_at_position(position, element);
                cout << "Element inserted successfully at position " << position << "." << endl;
                break;
            case 4:
                list.delete_from_front();
                cout << "Element deleted successfully from the beginning." << endl;
                break;
            case 5:
                list.delete_from_end();
                cout << "Element deleted successfully from the end." << endl;
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.delete_from_position(position);
                cout << "Element deleted successfully from position " << position << "." << endl;
                break;
            case 7:
                cout << "Doubly Linked List elements: ";
                list.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
