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

    void set_plink(Node *);

    void set_nlink(Node *);

    T get_data();

    Node *get_plink();

    Node *get_nlink();
};

template<class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList();

    int get_count();

    void insert_at_beginning(T);

    void insert_at_end(T);

    void insert_at_position(int, T);

    void delete_from_front();

    void delete_from_end();

    void delete_from_position(int);

    void display();
};