#include"PostfixEvaluation.cpp"

int evaluatePostfix(const string &postfix) {
    Stack<int> stack;
    string token;
    int operand1, operand2;
    for (char c: postfix) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (c == ' ') {
            continue;
        } else {
            operand2 = stack.pop();
            operand1 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    throw StackException("Invalid operator");
            }
        }
    }
    return stack.pop();
}

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    getline(cin, postfix);
    try {
        int result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;
    } catch (const StackException &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}