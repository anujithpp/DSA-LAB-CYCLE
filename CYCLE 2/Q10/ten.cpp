#include "BalancedBrackets.cpp"

int main() {
    BalancedBrackets test;
    string expression;
    cout << "Enter an expression containing brackets: ";
    getline(cin, expression);
    if (test.checkBalanced(expression)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }
    return 0;
}