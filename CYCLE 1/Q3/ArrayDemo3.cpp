#include "Array.cpp"

using namespace std;

int main() {
    Array<int> arr;

    int choice;
    int a, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insertion at Beginning\n";
        cout << "2. Insertion at End\n";
        cout << "3. Insertion at a specified position\n";
        cout << "4. Deletion from Beginning\n";
        cout << "5. Deletion from End\n";
        cout << "6. Deletion from a specified position\n";
        cout << "7. Find the index of a given element\n";
        cout << "8. Display\n";
        cout << "9. Left Rotate\n";
        cout << "10. Right Rotate\n";
        cout << "11. Frequency Count\n";
        cout << "12. Count Distinct Elements\n";
        cout << "0. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> a;
                arr.insertAtBeginning(a);
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> a;
                arr.insertAtEnd(a);
                break;
            case 3:
                cout << "Enter position to insert element: ";
                cin >> pos;
                cout << "Enter element to insert: ";
                cin >> a;
                arr.insertAtPosition(pos, a);
                break;
            case 4:
                arr.deleteAtBeginning();
                break;
            case 5:
                arr.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete element: ";
                cin >> pos;
                arr.deleteAtPosition(pos);
                break;
            case 7:
                cout << "Enter element to find index: ";
                cin >> a;
                cout << "Index of element: " << arr.linearSearch(a) << endl;
                break;
            case 8:
                cout << arr;
                break;
            case 9:
                cout<<"Enter how much to rotate left"<<endl;
                int lValue;
                cin>>lValue;
                arr.leftRotate(lValue);
                cout << "Array left rotated." << endl;
                break;
            case 10:
                cout<<"Enter how much to rotate right"<<endl;
                int rvalue;
                cin>>rvalue;
                arr.rightRotate(rvalue);
                cout << "Array right rotated." << endl;
                break;
            case 11:
                cout << "Frequency of element: " << endl;
                arr.frequencyCount();
                break;
            case 12:
                cout << "Distinct elements: "<< endl;
                arr.distinctElements();
                break;
            case 0:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 0);

    return 0;
}