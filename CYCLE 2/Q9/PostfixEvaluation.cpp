#include "PostfixEvaluation.h"

template<typename T>
void Stack<T>::push(T element) {
    data.push(element);
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw StackException("Stack is empty");
    }
    T topElement = data.top();
    data.pop();
    return topElement;
}

template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw StackException("Stack is empty");
    }
    return data.top();
}

template<typename T>
bool Stack<T>::isEmpty() {
    return data.empty();
}