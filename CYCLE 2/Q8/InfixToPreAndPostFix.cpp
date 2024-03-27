#include "InfixToPreAndPostFix.h"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

std::string infixToPostfix(const std::string &infix) {
    std::string postfix = "";
    std::stack<char> opStack;

    for (char c: infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop
                        ();
            }
            opStack.pop();
        } else if (isOperator(c)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

std::string infixToPrefix(const std::string &infix) {
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    for (char &c: reversedInfix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    std::string reversedPostfix = infixToPostfix(reversedInfix);
    std::string prefix = reversedPostfix;
    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}
