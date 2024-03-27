#include "InfixToPreAndPostFix.cpp"

int main() {
    std::string infixExpression;

    std::cout << "Enter an infix expression: ";
    getline(std::cin, infixExpression);

    std::string postfix = infixToPostfix(infixExpression);
    std::string prefix = infixToPrefix(infixExpression);

    std::cout << "Postfix expression: " << postfix << std::endl;
    std::cout << "Prefix expression: " << prefix << std::endl;

    return 0;
}
