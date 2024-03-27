#include<iostream>

using namespace std;

template<class T>
class Stack {
    T s[50];
    int top;
    int size;

public:
    Stack();

    void createStack();

    void display_stack();

    void push(T);

    void pop();

    bool isEmpty();

    bool isFull();

};