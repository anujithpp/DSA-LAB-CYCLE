#include <iostream>
#include <ostream>

using namespace std;

template<class T>
class Array {
    int LB;
    int UB;
    T A[100];

public:
    Array();

    Array(int, int, T[]);

    //insertion Operations
    void insertAtBeginning(T);

    void insertAtEnd(T);

    void insertAtPosition(T, int);

    //deletion Operations
    void deleteAtBeginning();

    void deleteAtEnd();

    void deleteAtPosition(int);

    //Searching Algorithms
    T linearSearch(T);

    int binarySearch(T key);


    //Sorting algorithms
    void quickSort(int LB, int UB);

    void bubbleSort();

    void insertionSort();

    void mergeSort(int LB, int UB);

    void selectionSort();


    //additional methods used inside other methods
    int partition(int, int);

    int size();

    void swap(T &a, T &b);

    void merge(int LB, int mid, int UB);


    template<class U>
    friend ostream &operator<<(ostream &, Array<U>);


    //Advance Array Operations
    void leftRotate(int lRotate);

    void rightRotate(int rRotate);

    void frequencyCount();

    void distinctElements();
};