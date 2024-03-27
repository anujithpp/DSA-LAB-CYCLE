#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

bool isOperator(char c);

int precedence(char op);

std::string infixToPostfix(const std::string &infix);

std::string infixToPrefix(const std::string &infix);

