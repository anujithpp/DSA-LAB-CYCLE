#include "Polynomial.h"

Polynomial::Polynomial() : head(nullptr) {}

Polynomial::~Polynomial() {
    Term *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Polynomial::addTerm(int coef, int exp) {
    if (coef == 0) return;
    Term *newTerm = new Term(coef, exp);
    if (!head || exp > head->exponent) {
        newTerm->next = head;
        head = newTerm;
    } else {
        Term *current = head;
        while (current->next && exp < current->next->exponent) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

void Polynomial::display() {
    if (!head) {
        cout << "0";
        return;
    }
    Term *current = head;
    while (current) {
        cout << current->coefficient << "x^" << current->exponent;
        if (current->next) cout << " + ";
        current = current->next;
    }
}

Polynomial Polynomial::add(Polynomial &other) {
    Polynomial result;
    Term *term1 = head;
    Term *term2 = other.head;
    while (term1 && term2) {
        if (term1->exponent == term2->exponent) {
            result.addTerm(term1->coefficient + term2->coefficient, term1->exponent);
            term1 = term1->next;
            term2 = term2->next;
        } else if (term1->exponent > term2->exponent) {
            result.addTerm(term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else {
            result.addTerm(term2->coefficient, term2->exponent);
            term2 = term2->next;
        }
    }
    while (term1) {
        result.addTerm(term1->coefficient, term1->exponent);
        term1 = term1->next;
    }
    while (term2) {
        result.addTerm(term2->coefficient, term2->exponent);
        term2 = term2->next;
    }
    return result;
}

Polynomial Polynomial::multiply(Polynomial &other) {
    Polynomial result;
    if (!head || !other.head) return result;
    Term *term1 = head;
    while (term1) {
        Term *term2 = other.head;
        while (term2) {
            int coef = term1->coefficient * term2->coefficient;
            int exp = term1->exponent + term2->exponent;
            result.addTerm(coef, exp);
            term2 = term2->next;
        }
        term1 = term1->next;
    }
    return result;
}

Polynomial getPolynomial() {
    Polynomial poly;
    int coef, exp, numTerms;
    cout << "Enter the number of terms: ";
    cin >> numTerms;
    for (int i = 0; i < numTerms; ++i) {
        cout << "Enter coefficient and exponent of " << i + 1 << "term with a space between them: ";
        cin >> coef >> exp;
        poly.addTerm(coef, exp);
    }
    return poly;
}