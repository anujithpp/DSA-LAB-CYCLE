#include "PostfixEvaluation.h"
#include <stack>
#include <cctype>

int PostfixEvaluation::evaluatePostfix(const std::string &postfix) {
    std::stack<int> operandStack;

    for (char c: postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (c == ' ') {
            continue;
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operandStack.top();
}
