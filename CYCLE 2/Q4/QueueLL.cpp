#include "QueueLL.h"

template <class T>
LinkedListQueue<T>::LinkedListQueue() {
    front = nullptr;
    rear = nullptr;
}

template <class T>
LinkedListQueue<T>::~LinkedListQueue() {
    while (front != nullptr) {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
void LinkedListQueue<T>::enqueue(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <class T>
T LinkedListQueue<T>::dequeue() {
    if (isEmpty()) {
        cerr << "Que underflow" << endl;
        exit(1);
    }

    T value = front->data;
    Node<T>* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return value;
}

template <class T>
bool LinkedListQueue<T>::isEmpty() {
    return front == nullptr;
}

template <class T>
void LinkedListQueue<T>::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node<T>* current = front;
    cout << "Queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}