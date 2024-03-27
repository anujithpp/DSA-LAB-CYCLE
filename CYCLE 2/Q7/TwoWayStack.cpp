#include "TwoWaystack.h"

template <class T>
TwoWayStack<T>::TwoWayStack() {
    front = nullptr;
    rear = nullptr;
}

template <class T>
TwoWayStack<T>::~TwoWayStack() {
    while (front != nullptr) {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
void TwoWayStack<T>::pushFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

template <class T>
void TwoWayStack<T>::pushRear(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

template <class T>
T TwoWayStack<T>::popFront() {
    if (isEmpty()) {
        cerr << "Underflow: The stack is empty." << endl;
        exit(1);
    }

    T value = front->data;
    Node<T>* temp = front;
    front = front->next;
    if (front != nullptr) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }
    delete temp;
    return value;
}

template <class T>
T TwoWayStack<T>::popRear() {
    if (isEmpty()) {
        cerr << "Underflow: The stack is empty." << endl;
        exit(1);
    }

    T value = rear->data;
    Node<T>* temp = rear;
    rear = rear->prev;
    if (rear != nullptr) {
        rear->next = nullptr;
    } else {
        front = nullptr;
    }
    delete temp;
    return value;
}

template <class T>
bool TwoWayStack<T>::isEmpty() {
    return front == nullptr;
}

template <class T>
void TwoWayStack<T>::display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node<T>* current = front;
    cout << "Stack: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}