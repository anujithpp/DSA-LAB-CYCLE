#include "Queue.h"

template<class T>
Queue<T>::Queue(int capacity) {
    this->capacity = capacity;
    arr = new T[capacity];
    front = 0;
    rear = -1;
    size = 0;

}

template<class T>
Queue<T>::~Queue() {
    delete[] arr;
}


template<class T>
void Queue<T>::enqueue(T element) {
    if (isFull()) {
        cout << "Overflow: Queue is full." << endl;
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = element;
    size++;
}

template<class T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Underflow: Queue is empty." << endl;
        return T();
    }
    T element = arr[front];
    front = (front + 1) % capacity;
    size--;
    return element;
}

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

template<class T>
bool Queue<T>::isFull() {
    return size == capacity;
}

template<class T>
void Queue<T>::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    int i = front;
    cout << "Queue: ";
    while (i != rear) {
        cout << arr[i] << " ";
        i = (i + 1) % capacity;
    }
    cout << arr[rear] << endl;
}