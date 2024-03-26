#include <iostream>

using namespace std;

template<class T>
class Node {
private:
    T data;
    Node *pLink;
    Node *nLink;
public:
    Node(T);

    void set_pLink(Node *);

    void set_nLink(Node *);

    T get_data();

    Node *get_pLink();

    Node *get_nLink();
};

template<class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList();

    int get_count();

    void insert_at_beginning();

    void insert_at_end();

    void insert_at_position();

    void delete_from_front();

    void delete_from_end();

    void delete_from_position();

    void display();
};