#include "Array.h"

template<class T>
Array<T>::Array() {
    LB = 1;
    UB = 0;
}

template<class T>
Array<T>::Array(int LB, int UB, T X[]) {
}

template<class T>
void Array<T>::insertAtBeginning(T key) {
    UB += 1;
    int k = UB - 1;
    while (k >= LB) {
        A[k + 1] = A[k];
        k--;
    }
    A[LB] = key;
}

template<class T>
void Array<T>::insertAtEnd(T key) {
    UB += 1;
    A[UB] = key;
}

template<class T>
void Array<T>::insertAtPosition(T key, int index) {
    UB += 1;
    int k = UB - 1;
    while (k >= index) {
        A[k + 1] = A[k];
        k--;
    }
    A[index] = key;
}

template<class T>
void Array<T>::deleteAtBeginning() {
    LB += 1;
}

template<class T>
void Array<T>::deleteAtEnd() {
    UB -= 1;
}

template<class T>
void Array<T>::deleteAtPosition(int index) {
    if (LB <= index && index <= UB) {
        for (int i = index; i < UB; ++i) {
            A[i] = A[i + 1];
        }
        UB--;
    } else {
        cout << "Out of Bound";
    }
}


//Searching algorithms
template<class T>
T Array<T>::linearSearch(T key) {
    int index = -1;
    int i = LB;
    while (i <= UB) {
        if (A[i] == key) {
            index = i;
            break;
        }
        i++;
    }
    return index;
}

template<class T>
int Array<T>::binarySearch(T key) {
    int left = LB;
    int right = UB;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (A[mid] == key) {
            return mid;
        }

        if (A[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}


//Sorting algorithms
template<class T>
void Array<T>::quickSort(int LB, int UB) {
    if (LB < UB) {
        int pi = partition(LB, UB);
        quickSort(LB, pi - 1);
        quickSort(pi + 1, UB);
    }
}

template<class T>
void Array<T>::bubbleSort(){
    int n = UB +1;

    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

template<class T>
void Array<T>::insertionSort(){
    int n = UB+1;
    for (int i = 1; i < n; ++i) {
        T key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

template<class T>
void Array<T>::mergeSort(int LB, int UB) {
    if (LB < UB) {
        int mid = (LB + UB) / 2;
        mergeSort(LB, mid);         // Sort first half
        mergeSort(mid + 1, UB);     // Sort second half
        merge(LB, mid, UB);         // Merge the sorted halves
    }
}

template<class T>
void Array<T>::selectionSort() {
    int n = UB + 1; // Size of the array

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        swap(A[i], A[minIndex]);
    }
}


//additional methods used inside other methods
template<class T>
int Array<T>::partition(int LB, int UB) {
    T pivot = A[UB];
    int i = LB - 1;
    for (int j = LB; j < UB; ++j) {
        if (A[j] <= pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[UB]);
    return i + 1;
}

template<class T>
int Array<T>::size()  {
    return UB + 1;
}                 //returns the size of array *( size-1 = upperbound)

template<class T>
void Array<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void Array<T>::merge(int LB, int mid, int UB) {
    int n1 = mid - LB + 1;
    int n2 = UB - mid;

    // Create temporary arrays
    T L[n1], R[n2];


    for (int i = 0; i < n1; i++)
        L[i] = A[LB + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = LB;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}


//Operator Overloading of output stream
template<class U>
ostream &operator<<(ostream &os, Array<U> M) {
    int i;
    os << endl;
    for (i = M.LB; i <= M.UB; i++) {
        os << M.A[i] << " ";
    }
    os << endl;
    return os;
}

//Advance Array Operations
template<class T>
void Array<T>::leftRotate(int lRotate) {
    int n = UB - LB + 1;
    lRotate = lRotate % n;
    for (int i = 0; i < lRotate; ++i) {
        T temp = A[LB];
        for (int j = LB; j < UB; ++j) {
            A[j] = A[j + 1];
        }
        A[UB] = temp;
    }
}

template<class T>
void Array<T>::rightRotate(int rRotate) {
    int n = UB - LB + 1;

    rRotate = rRotate % n;

    for (int i = 0; i < rRotate; ++i) {
        T temp = A[UB];
        for (int j = UB; j > LB; --j) {
            A[j] = A[j - 1];
        }
        A[LB] = temp;
    }
}

template<class T>
void Array<T>::frequencyCount() {
    cout << "Element\tFrequency" << endl;
    for (int i = LB; i <= UB; ++i) {
        int count = 0;
        for (int j = LB; j <= UB; ++j) {
            if (A[i] == A[j]) {
                count++;
            }
        }
        cout << A[i] << "\t" << count << endl;
    }
}

template<class T>
void Array<T>::distinctElements() {
    cout << "Distinct Elements:" << endl;

    for (int i = LB; i <= UB; ++i) {
        int count = 0;
        for (int j = LB; j <= UB; ++j) {
            if (A[i] == A[j]) {
                count++;
            }
        }
        if (count == 1) {
            cout << A[i] << ",";
        }
    }
}


