#include "StackRecursion.h"

int factorialWithStack::FactorialCalculator(int n) {
    std::stack<int> stack;
    stack.push(n);

    int result = 1;
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        if (current > 1) {
            stack.push(current - 1);
            result *= current;
        }
    }
    return result;
}


