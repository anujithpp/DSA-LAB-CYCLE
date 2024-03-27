#include <iostream>

using namespace std;

class BalancedBrackets {
private:
    struct Node {
        char data;
        Node *next;

        Node(char value) : data(value), next(nullptr) {}
    };

    Node *top;

    bool isEmpty() const;

    void push(char value);

    char pop();

public:
    BalancedBrackets();

    bool checkBalanced(const std::string &expression);
};

