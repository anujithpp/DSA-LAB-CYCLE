#include <iostream>

using namespace std;

template<class T>
class Dequeue {
    T *arr;
    int capacity;
    int front, rear;
    int size;

public:
    Dequeue(int);

    ~Dequeue();

    void insertFront(T);

    void insertRear(T);

    void deleteFront();

    void deleteRear();

    bool isEmpty();

    bool isFull();

    void display();
};