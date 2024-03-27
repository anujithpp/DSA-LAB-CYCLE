#include "BalancedBrackets.h"


bool BalancedBrackets::isEmpty() const {
    return top == nullptr;
}

void BalancedBrackets::push(char value) {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

char BalancedBrackets::pop() {
    if (isEmpty()) {
        cerr << "Error: Stack is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    char value = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return value;
}

BalancedBrackets::BalancedBrackets() : top(nullptr) {}

bool BalancedBrackets::checkBalanced(const string &expression) {
    for (char ch: expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{')) {
                return false;
            }
        }
    }
    return isEmpty();
}
