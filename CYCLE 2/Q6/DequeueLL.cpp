#include "DequeueLL.h"

template<class T>
LinkedListDEQUEUE<T>::LinkedListDEQUEUE() {
    front = nullptr;
    rear = nullptr;
}

template<class T>
LinkedListDEQUEUE<T>::~LinkedListDEQUEUE() {
    while (front != nullptr) {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }
}

template<class T>
void LinkedListDEQUEUE<T>::insertFront(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

template<class T>
void LinkedListDEQUEUE<T>::insertRear(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template<class T>
T LinkedListDEQUEUE<T>::deleteFront() {
    if (isEmpty()) {
        cerr << "Underflow: The queue is empty." << endl;
        exit(1);
    }

    T value = front->data;
    Node<T> *temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return value;
}

template<class T>
T LinkedListDEQUEUE<T>::deleteRear() {
    if (isEmpty()) {
        cerr << "Underflow: The queue is empty." << endl;
        exit(1);
    }

    T value;
    if (front == rear) {
        value = front->data;
        delete front;
        front = nullptr;
        rear = nullptr;
    } else {
        Node<T> *current = front;
        while (current->next != rear) {
            current = current->next;
        }
        value = rear->data;
        delete rear;
        rear = current;
        rear->next = nullptr;
    }
    return value;
}

template<class T>
bool LinkedListDEQUEUE<T>::isEmpty() {
    return front == nullptr;
}

template<class T>
void LinkedListDEQUEUE<T>::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node<T> *current = front;
    cout << "Queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}