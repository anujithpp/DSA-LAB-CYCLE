#include "Queue.cpp"

using namespace std;

int main() {
    int choice, capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue<int> queue(capacity);

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Insert element to the Rear of the queue\n";
        cout << "2. Delete element from the Front of the queue\n";
        cout << "3. Check if the queue is empty\n";
        cout << "4. Check if the queue is full\n";
        cout << "5. Underflow the queue \n";
        cout << "6. Overflow the queue \n";
        cout << "7. Display the queue\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter the element to insert: ";
                cin >> element;
                queue.enqueue(element);
                break;
            }
            case 2: {
                int removedElement = queue.dequeue();
                if (removedElement != -1) {
                    cout << "Element removed from the queue: " << removedElement << endl;
                }
                break;
            }
            case 3:
                if (queue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                if (queue.isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
            case 5: {
                while (!queue.isEmpty()) {
                    queue.dequeue();
                }
                cout << "Queue is Underflow\n";
                break;
            }
            case 6: {
                int value;
                cout << "Enter the Value to enqueue until queue is full: ";
                cin >> value;
                while (!queue.isFull()) {
                    queue.enqueue(value);
                }
                cout << "Queue is Overflow\n";
                break;
            }
            case 7: {
                cout << "\nElements of Queue: ";
                queue.display();
                break;
            }
            case 8: {
                cout << "Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 8);

    return 0;
}
