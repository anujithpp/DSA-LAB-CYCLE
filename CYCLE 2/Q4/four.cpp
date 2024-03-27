#include "QueueLL.cpp"

using namespace std;

int main() {
    int choice;
    LinkedListQueue<int> l1;
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
                l1.enqueue(element);
                break;
            }
            case 2: {
                int removedElement = l1.dequeue();
                if (removedElement != -1) {
                    cout << "Element removed from the queue: " << removedElement << endl;
                }
                break;
            }
            case 3:
                if (l1.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                cout<<"Queue implemented using linked list have no size (memory is dynamically allocated) \n";
                break;
            case 5: {
                while (!l1.isEmpty()) {
                    l1.dequeue();
                }
                cout << "Queue is Underflow\n";
                break;
            }
            case 6: {
                cout<<"Not Applicable--Queue implemented with Linked list doesn't have max size\n";
                break;
            }
            case 7: {
                cout << "\nElements of Queue: ";
                l1.display();
                break;
            }
            case 8:{
                cout << "Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 8);

    return 0;
}
