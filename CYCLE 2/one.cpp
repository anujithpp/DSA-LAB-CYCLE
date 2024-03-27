#include "Stack.cpp"

using namespace std;

int main() {
    Stack<int> stack;
    int choice;

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
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                stack.pop();
                break;
            }
            case 3: {
                cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            }
            case 4: {
                cout << (stack.isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;
            }
            case 5: {
                stack.pop();
                break;
            }
            case 6: {
                int value;
                cout << "Enter value to push until overflow: ";
                cin >> value;
                while (!stack.isFull()) {
                    stack.push(value);
                }
                break;
            }
            case 7: {
                cout << "Stack contents: ";
                stack.display_stack();
                break;
            }
            case 8: {
                cout << "Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 8);

    return 0;
}
