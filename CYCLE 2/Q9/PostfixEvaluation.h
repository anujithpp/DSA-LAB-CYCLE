#include<iostream>
#include <stack>
#include <string>

using namespace std;

class StackException {
private:
    string message;

public:
    StackException(const string &msg) : message(msg) {}

    const string &what() const { return message; }
};

template<typename T>
class Stack {
private:
    stack<T> data;

public:
    void push(T element);

    T pop();

    T peek();

    bool isEmpty();
};