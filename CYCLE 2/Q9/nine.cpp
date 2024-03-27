#include "PostfixEvaluation.cpp"

int main() {
    PostfixEvaluation pe;
    std::string postfix;

    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, postfix);

    int result = pe.evaluatePostfix(postfix);                           //Not working check***
    std::cout << "Result of evaluation: " << result << std::endl;

    return 0;
}
