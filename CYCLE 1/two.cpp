#include "Array.cpp"

using namespace std;

int main() {
    Array<int> arr;

    int choice, key, index, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Linear Search\n";
        cout << "8. Binary Search\n";
        cout << "9. Quick Sort\n";
        cout << "10. Bubble Sort\n";
        cout << "11. Insertion Sort\n";
        cout << "12. Merge Sort\n";
        cout << "13. Selection Sort\n";
        cout << "14. Display Array\n";
        cout << "15. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at the beginning: ";
                cin >> key;
                arr.insertAtBeginning(key);
                break;
            case 2:
                cout << "Enter element to insert at the end: ";
                cin >> key;
                arr.insertAtEnd(key);
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> key;
                cout << "Enter position to insert at: ";
                cin >> position;
                arr.insertAtPosition(key, position);
                break;
            case 4:
                arr.deleteAtBeginning();
                break;
            case 5:
                arr.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                arr.deleteAtPosition(position);
                break;
            case 7:
                cout << "Enter element to search for: ";
                cin >> key;
                index = arr.linearSearch(key);
                if (index != -1) {
                    cout << "Element found at position " << index << endl;
                } else {
                    cout << "Element not found in the array." << endl;
                }
                break;
            case 8:
                cout << "Enter element to search for: ";
                cin >> key;
                index = arr.binarySearch(key);
                if (index != -1) {
                    cout << "Element found at position " << index << endl;
                } else {
                    cout << "Element not found in the array." << endl;
                }
                break;
            case 9:
                arr.quickSort(0, arr.size() - 1);
                cout << "Array sorted using Quick Sort." << endl;
                break;
            case 10:
                arr.bubbleSort();
                cout << "Array sorted using Bubble Sort." << endl;
                break;
            case 11:
                arr.insertionSort();
                cout << "Array sorted using Insertion Sort." << endl;
                break;
            case 12:
                arr.mergeSort(0, arr.size() - 1);
                cout << "Array sorted using Merge Sort." << endl;
                break;
            case 13:
                arr.selectionSort();
                cout << "Array sorted using Selection Sort." << endl;
                break;
            case 14:
                cout << "Array: " << arr << endl;
                break;
            case 15:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 15);

    return 0;
}
