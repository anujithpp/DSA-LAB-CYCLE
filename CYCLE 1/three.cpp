#include "Array.cpp"

using namespace std;

int main() {
    Array<int> arr;
    int lRotate,rRotate;

    arr.insertAtEnd(1);
    arr.insertAtEnd(2);
    arr.insertAtEnd(3);
    arr.insertAtEnd(4);
    arr.insertAtEnd(5);
    arr.insertAtEnd(5);
    arr.insertAtEnd(3);
    arr.insertAtEnd(5);

    cout << "Original Array:";
    cout << arr << endl;

    cout<<"How much position to rotate to left?: ";
    cin>>lRotate;
    arr.leftRotate(lRotate);
    cout << "After Left Rotating "<<lRotate<<"position";
    cout << arr << endl;

    cout<<"How much position to rotate to right?: ";
    cin>>rRotate;
    arr.rightRotate(rRotate);
    cout << "After right Rotating "<<rRotate<<"position";
    cout << arr << endl;

    cout << "Frequency Count of Elements:"<<endl;
    arr.frequencyCount();
    cout<<endl;


    cout << "Distinct Elements:";
    arr.distinctElements();
    cout<<endl;

    return 0;
}
