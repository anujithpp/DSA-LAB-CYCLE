#include "DeQueue.h"

template<class T>
Dequeue<T>::Dequeue(int capacity) {
    this->capacity = capacity;
    arr = new T[capacity];
    front = rear = -1;
    size = 0;
}

template<class T>
Dequeue<T>::~Dequeue() {
    delete[] arr;
}

template<class T>
void Dequeue<T>::insertFront(T element) {
    if (isFull()) {
        cout << "Overflow.... Dequeue is full." << endl;
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = capacity - 1;
    } else {
        front--;
    }
    arr[front] = element;
    size++;
    display();
}

template<class T>
void Dequeue<T>::insertRear(T element) {
    if (isFull()) {
        cout << "Overflow..... Dequeue is full." << endl;
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else if (rear == capacity - 1) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = element;
    size++;
    display();
}

template<class T>
void Dequeue<T>::deleteFront() {
    if (isEmpty()) {
        cout << "Underflow.... Dequeue is empty." << endl;
        return;
    }
    cout << "Deleted from Front: " << arr[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    size--;
    display();
}

template<class T>
void Dequeue<T>::deleteRear() {
    if (isEmpty()) {
        cout << "Underflow.....Dequeue is empty." << endl;
        return;
    }
    cout << "Deleted from Rear: " << arr[rear] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + capacity) % capacity;
    }
    size--;
    display();
}

template<class T>
bool Dequeue<T>::isEmpty() {
    return size == 0;
}

template<class T>
bool Dequeue<T>::isFull() {
    return size == capacity;
}

template<class T>
void Dequeue<T>::display() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return;
    }
    cout << "Deque: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % capacity;
    }
    cout << endl;
}
