#include "DoublyLinkedList.h"

template<class T>
Node<T>::Node(T data) : data(data), pLink(nullptr), nLink(nullptr) {}

template<class T>
void Node<T>::set_plink(Node *pLink) {
    this->pLink = pLink;
}

template<class T>
void Node<T>::set_nlink(Node *nLink) {
    this->nLink = nLink;
}

template<class T>
T Node<T>::get_data() {
    return data;
}

template<class T>
Node<T> *Node<T>::get_plink() {
    return pLink;
}

template<class T>
Node<T> *Node<T>::get_nlink() {
    return nLink;
}

template<class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template<class T>
int LinkedList<T>::get_count() {
    Node<T> *p = head;
    int count = 0;
    while (p != nullptr) {
        count++;
        p = p->get_nlink();
    }
    return count;
}

template<class T>
void LinkedList<T>::insert_at_beginning(T key) {
    Node<T> *node = new Node<T>(key);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        node->set_nlink(head);
        node->set_plink(nullptr);
        head = node;
    }
}

template<class T>
void LinkedList<T>::insert_at_end(T key) {
    if (head == nullptr) {
        Node<T> *node = new Node<T>(key);
        head = node;
        tail = node;
    } else {
        Node<T> *p = head;
        while (p->get_nlink() != nullptr) {
            p = p->get_nlink();
        }
        Node<T> *node = new Node<T>(key);
        node->set_plink(p);
        p->set_nlink(node);
        tail = node;
    }
}

template<class T>
void LinkedList<T>::insert_at_position(int pos, T key) {
    if (pos == 1) {
        insert_at_beginning(key);
    } else {
        int count = 1;
        Node<T> *p = head;
        while (p->get_nlink() != nullptr and count < pos - 1) {
            p = p->get_nlink();
            count++;
        }
        Node<T> *q = p->get_nlink();
        Node<T> *node = new Node<T>(key);
        node->set_nlink(q);
        p->set_nlink(node);
        node->set_plink(p);
        q->set_plink(node);
    }
}

template<class T>
void LinkedList<T>::delete_from_front() {
    if (head == nullptr) {
        cout << "List Empty" << endl;
        return;
    } else {
        Node<T> *p = head;
        head = head->get_nlink();


        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->set_plink(nullptr);
        }

        delete p;
    }
}

template<class T>
void LinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List Empty" << endl;
        return;
    }

    Node<T> *p = head;
    if (p->get_nlink() == nullptr) {
        head = nullptr;
        delete p;
        return;
    }

    Node<T> *q = p->get_nlink();
    while (q->get_nlink() != nullptr) {
        p = q;
        q = q->get_nlink();
    }
    p->set_nlink(nullptr);
    delete q;
}

template<class T>
void LinkedList<T>::delete_from_position(int pos) {
    if (head == nullptr) {
        cout << "List Empty" << endl;
        return;
    }

    if (pos <= 0 || pos > get_count()) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        delete_from_front();
        return;
    }

    int count = 1;
    Node<T> *p = head;
    Node<T> *q = p->get_nlink();
    while (q != nullptr && count < pos - 1) {
        p = q;
        q = q->get_nlink();
        count++;
    }

    if (q == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }

    p->set_nlink(q->get_nlink());
    if (q->get_nlink() != nullptr) {
        q->get_nlink()->set_plink(p);
    }
    delete q;
}

template<class T>
void LinkedList<T>::display() {
    Node<T> *p = head;
    while (p != nullptr) {
        cout << p->get_data() << " ";
        p = p->get_nlink();
    }
    cout << endl;
}
