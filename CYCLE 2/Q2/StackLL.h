#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template<class T>
class LinkedListStack {
private:
    Node<T> *top;
    int maxSize;
    int size;

public:
    LinkedListStack(int);

    ~LinkedListStack();

    void push(T value);

    T pop();

    bool isEmpty();

    bool isFull();

    void display();
};