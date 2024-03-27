#include "TwoWaystack.cpp"

using namespace std;

int main() {
    TwoWayStack<int> stack;
    int choice, value;

    do {
        cout << "\n\nTwo-Way Stack Menu\n";
        cout << "1. Push to Front\n";
        cout << "2. Push to Rear\n";
        cout << "3. Pop from Front\n";
        cout << "4. Pop from Rear\n";
        cout << "5. Display Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push to Front: ";
                cin >> value;
                stack.pushFront(value);
                break;
            case 2:
                cout << "Enter value to push to Rear: ";
                cin >> value;
                stack.pushRear(value);
                break;
            case 3:
                if (!stack.isEmpty())
                    cout << "Popped element from Front: " << stack.popFront() << endl;
                else
                    cout << "Stack is empty.\n";
                break;
            case 4:
                if (!stack.isEmpty())
                    cout << "Popped element from Rear: " << stack.popRear() << endl;
                else
                    cout << "Stack is empty.\n";
                break;
            case 5:
                stack.display();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
