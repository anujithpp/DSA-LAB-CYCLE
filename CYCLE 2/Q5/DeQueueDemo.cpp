#include "DeQueue.cpp"

using namespace std;

int main() {
    int capacity;
    cout << "Enter the capacity of the dequeue: ";
    cin >> capacity;

    Dequeue<int> dequeue(capacity);
    int choice;
    int element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert elements to the Front of the queue.\n";
        cout << "2. Insert elements to the Rear of the queue.\n";
        cout << "3. Delete elements from the Front of the queue.\n";
        cout << "4. Delete elements from the Rear of the queue.\n";
        cout << "5. Display the queue.\n";
        cout << "6. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert at the front: ";
                cin >> element;
                dequeue.insertFront(element);
                break;
            case 2:
                cout << "Enter the element to insert at the rear: ";
                cin >> element;
                dequeue.insertRear(element);
                break;
            case 3:
                dequeue.deleteFront();
                break;
            case 4:
                dequeue.deleteRear();
                break;
            case 5:
                dequeue.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
