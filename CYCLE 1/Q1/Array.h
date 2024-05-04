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

    T linearSearch(T);

    template<class U>
    friend ostream &operator<<(ostream &, Array<U>);
};