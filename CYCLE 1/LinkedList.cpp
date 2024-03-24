#include"LinkedList.h"

template<class T>

Node<T>::Node(T data) {
    this->data = data;
    this->link = nullptr;
}

template<class T>
T Node<T>::get_data() {
    return data;
}

template<class T>
void Node<T>::set_data(T data) {
    this->data = data;
}

template<class T>
void Node<T>::set_link(Node *link) {
    this->link = link;
}

template<class T>
Node<T> *Node<T>::get_link() {
    return link;
}

template<class T>
void LinkedList<T>::create() {
    string choice;
    T x;
    Node<T> *current = nullptr;
    do {
        cout << "Enter the data: ";
        cin >> x;
        cout << endl;
        Node<T> *node = new Node<T>(x);
        if (head == nullptr) {
            head = node;
            current = head;
        } else {
            current->set_link(node);
            current = node;
        }
        cout << "Do you want to enter more values? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == "y");
}

template<class T>
void LinkedList<T>::display() {
    Node<T> *t = head;
    while (t != NULL) {
        cout << t->get_data() << " ";
        t = t->get_link();
    }
}

template<class T>
void LinkedList<T>::insertAtBeginning(T key) {
    Node<T> *node = new Node<T>(key);
    node->set_data(key);
    node->set_link(head);
    head = node;
}

template<class T>
void LinkedList<T>::insertAtEnd(T key) {
    Node<T> *q = head;
    while (q->get_link() != NULL) {
        q = q->get_link();
    }
    Node<T> *node = new Node<T>(key);
    node->set_data(key);
    q->set_link(node);
}

template<class T>
void LinkedList<T>::insertAtPosition(T data, int position) {
    int listSize = size();
    if (position < 1 || position > listSize + 1) {
        cout << "Invalid position. Insertion not possible." << endl;
        return;
    }

    Node<T> *newNode = new Node<T>(data);

    if (position == 1) {
        newNode->set_link(head);
        head = newNode;
    } else {
        Node<T> *temp = head;
        for (int i = 1; i < position - 1; ++i) {
            temp = temp->get_link();
        }
        newNode->set_link(temp->get_link());
        temp->set_link(newNode);
    }

    cout << "Node inserted successfully at position " << position << endl;
}


template<class T>
void LinkedList<T>::deleteAtBeginning() {
    Node<T> *temp = head;
    head = head->get_link();
    delete (temp);
}

template<class T>
void LinkedList<T>::deleteAtEnd() {
    Node<T> *p = head;
    Node<T> *q = p->get_link();
    while (q->get_link() != NULL) {
        p = q;
        q = q->get_link();
    }
    p->set_link(NULL);
    delete (q);
}

template<class T>
void LinkedList<T>::deleteAtPosition(int position) {
    if (position < 1 || position > size()) {
        cout << "Invalid position. Deletion not possible." << endl;
        return;
    }

    Node<T> *temp = head;
    if (position == 1) {
        head = head->get_link();
    } else {
        for (int i = 1; i < position - 1; ++i) {
            temp = temp->get_link();
        }
        Node<T> *nextNode = temp->get_link()->get_link();
        delete temp->get_link();
        temp->set_link(nextNode);
    }
    cout << "Node deleted successfully from position " << position << endl;
}

template<class T>
int LinkedList<T>::size() {
    int count = 0;
    Node<T> *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->get_link();
    }
    return count;
}

