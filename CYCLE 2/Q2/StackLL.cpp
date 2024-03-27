#include "StackLL.h"

template<class T>
LinkedListStack<T>::LinkedListStack(int maxSize) {
    top = nullptr;
    this->maxSize = maxSize;
    size = 0;
}

template<class T>
LinkedListStack<T>::~LinkedListStack() {
    Node<T> *temp;
    while (top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}

template<class T>
void LinkedListStack<T>::push(T value) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
        return;
    }
    Node<T> *newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    size++;
}

template<class T>
T LinkedListStack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1); // Terminating the program as stack underflow is a critical error
    }
    Node<T> *temp = top;
    T poppedValue = top->data;
    top = top->next;
    delete temp;
    size--;
    return poppedValue;
}

template<class T>
bool LinkedListStack<T>::isEmpty() {
    return top == nullptr;
}

template<class T>
bool LinkedListStack<T>::isFull() {
    return size == maxSize;
}

template<class T>
void LinkedListStack<T>::display() {
    if (isEmpty()) {
        cout << "Stack is Empty." << endl;
        return;
    }
    Node<T> *temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
