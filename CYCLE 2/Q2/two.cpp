#include "StackLL.cpp"

using namespace std;

int main() {
    LinkedListStack<int> stack(50);

    int choice;
    int value;

    do {
        cout << "\nMenu:\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. IS EMPTY\n";
        cout << "4. IS FULL\n";
        cout << "5. UNDERFLOW\n";
        cout << "6. OVERFLOW\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                if (!stack.isEmpty())
                    cout << "Popped value: " << stack.pop() << endl;
                else
                    cout << "Stack is empty." << endl;
                break;
            case 3:
                if (stack.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 4:
                if (stack.isFull())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 5:{
                while (!stack.isEmpty()) {
                    stack.pop();
                }
                break;
            }
            case 6: {
                int x;
                cout << "Enter value to push until overflow: ";
                cin >> x;
                while (!stack.isFull()) {
                    stack.push(x);
                }
                break;
            }
            case 7:
                cout << "Stack Contents: ";
                stack.display();
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
