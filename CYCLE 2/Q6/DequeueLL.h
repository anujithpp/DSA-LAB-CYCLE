#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template<class T>
class LinkedListDEQUEUE {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    LinkedListDEQUEUE();

    ~LinkedListDEQUEUE();

    void insertFront(T value);

    void insertRear(T value);

    T deleteFront();

    T deleteRear();

    bool isEmpty();

    void display();
};