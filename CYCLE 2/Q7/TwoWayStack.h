#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *prev;
    Node *next;

    Node(T value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

template<class T>
class TwoWayStack {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    TwoWayStack();

    ~TwoWayStack();

    void pushFront(T value);

    void pushRear(T value);

    T popFront();

    T popRear();

    bool isEmpty();

    void display();
};