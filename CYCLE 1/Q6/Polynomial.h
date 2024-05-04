#include <iostream>

using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term *next;

    Term(int p_coefficient, int p_exponent) : coefficient(p_coefficient), exponent(p_exponent), next(nullptr) {}
};

class Polynomial {
private:
    Term *head;

public:
    Polynomial();

    ~Polynomial();

    void addTerm(int p_coefficient, int p_exponent);

    void display();

    Polynomial add(Polynomial &other);

    Polynomial multiply(Polynomial &other);

};


