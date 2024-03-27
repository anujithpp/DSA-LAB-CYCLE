#include <iostream>
#include<ostream>

using namespace std;

template<class T>

class Node {
    T data;
    Node *link;
public:
    Node(T);

    T get_data();

    void set_data(T);

    void set_link(Node *link);

    Node *get_link();
};

template<class T>
class LinkedList {
    Node<T> *head;
public:
    void create();

    void display();

    void insertAtBeginning(T);

    void insertAtEnd(T);

    void insertAtPosition(T, int);

    void deleteAtBeginning();

    void deleteAtEnd();

    void deleteAtPosition(int);

    int size();
};