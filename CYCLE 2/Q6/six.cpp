#include "DequeueLL.cpp"

using namespace std;

int main() {
    LinkedListDEQUEUE<int> dequeue;
    int choice, value;

    do {
        cout << "\n---- Menu ----" << endl;
        cout << "1. Insert element at the front" << endl;
        cout << "2. Insert element at the rear" << endl;
        cout << "3. Delete element from the front" << endl;
        cout << "4. Delete element from the rear" << endl;
        cout << "5. Display the dequeue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the front: ";
                cin >> value;
                dequeue.insertFront(value);
                cout << "Element " << value << " inserted at the front." << endl;
                break;
            case 2:
                cout << "Enter value to insert at the rear: ";
                cin >> value;
                dequeue.insertRear(value);
                cout << "Element " << value << " inserted at the rear." << endl;
                break;
            case 3:
                if (!dequeue.isEmpty()) {
                    value = dequeue.deleteFront();
                    cout << "Element " << value << " deleted from the front." << endl;
                } else {
                    cout << "Dequeue is empty. Cannot delete from front." << endl;
                }
                break;
            case 4:
                if (!dequeue.isEmpty()) {
                    value = dequeue.deleteRear();
                    cout << "Element " << value << " deleted from the rear." << endl;
                } else {
                    cout << "Dequeue is empty. Cannot delete from rear." << endl;
                }
                break;
            case 5:
                cout << "Displaying the dequeue: ";
                dequeue.display();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}
