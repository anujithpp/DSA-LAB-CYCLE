#include <iostream>

using namespace std;

template<class T>
class Queue {
    int capacity, size, front, rear;
    T *arr;

public:
    Queue(int);

    ~Queue();

    void enqueue(T);

    T dequeue();

    bool isEmpty();

    bool isFull();

    void display();
};