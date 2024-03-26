#include "DoublyLinkedList.h"

template<class T>
Node<T>::Node(T data) {
    this->data = data;
}

template<class T>
void Node<T>::set_pLink(Node* pLink) {
    this->pLink=pLink;
}

template<class T>
void Node<T>::set_nLink(Node* nLink) {
    this->nLink=nLink;
}

template<class T>
T Node<T>::get_data() {
    return data;
}

template<class T>
Node<T>* Node<T>::get_pLink() {
    return pLink;
}

template<class T>
Node<T>* Node<T>::get_nLink() {
    return nLink;
}