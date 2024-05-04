#include "StackRecursion.cpp"

int main() {
    factorialWithStack sr;
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    int factorial = sr.FactorialCalculator(n);
    std::cout << "Factorial of " << n << " is: " << factorial << std::endl;

    return 0;
}
