/*
 * Linked List - Data Structure
 *
 *  Created on: 30 Aug 2021
 *      Author: Thomas Corr
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>


template <typename T>
struct Node {
    T data;
    Node* next;
};


template <typename T>
class LinkedList {
public:
    int length_;
    Node<T>* head;
    Node<T>* tail;

    LinkedList();
    ~LinkedList();

    bool isEmpty() {
        return this->head == nullptr;
    }
    int length() {
        return this->length_;
    }
    void prependNode(T data);
    void appendNode(T data);
    void deleteNodeAt(int idx);
    void deleteNodesByValue(T value);
    void printSequence();
};


template <typename T>
LinkedList<T>::LinkedList() {
    this->length_ = 0;
    std::cout << this->length_ << std::endl;
    this->head = nullptr;
    this->tail = nullptr;
}


template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* next = this->head;
    Node<T>* curr = nullptr;

    while (next != nullptr) {
        curr = next;
        curr = next->next;
        delete curr;
    }

    std::cout << "List Deleted" << std::endl;
}


template <typename T>
void LinkedList<T>::prependNode(T data) {
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = this->head;
    if (isEmpty()) {
        this->tail = node;
    }
    this->head = node;
    this->length_++;
}


template <typename T>
void LinkedList<T>::appendNode(T data) {
    Node<T>* node = nullptr;
    if (isEmpty()) {
        node = new Node<T>;
        this->head = node;
    }
    else {
        node = this->tail;
        node->next = new Node<T>;
        node = node->next;
    }
    node->data = data;
    node->next = nullptr;
    this->tail = node;
    this->length_++;
}


template <typename T>
void LinkedList<T>::deleteNodeAt(int idx) {
    if ((idx < 0) || (idx >= this->length_)) {
        std::cout << "Index " << idx << " exceeds current list length of "
            << this->length_ << '.' << std::endl;
    }
    else {
        Node<T>* node = this->head;
        if (idx == 0) {  // Update head
            this->head = node->next;
            delete node;
            if (isEmpty()) {
                this->tail = nullptr;
            }
        }
        else {
            for (int i = 0; i < idx - 1; i++) {
                node = node->next;
            }
            Node<T>* tmp = node->next;
            node->next = node->next->next;
            delete tmp;
            if (idx == this->length_ - 1) {  // Update tail to point to end node
                this->tail = node;
            }
        }
        this->length_--;
    }
}



template <typename T>
void LinkedList<T>::deleteNodesByValue(T value) {
    int num_deleted = 0;
    Node<T>* curr = this->head;
    Node<T>* tmp;
    while (!isEmpty() && curr->data == value) {
        tmp = curr;
        this->head = curr->next;
        curr = curr->next;
        delete tmp;
        num_deleted++;
    }
    while (!isEmpty() && curr->next != nullptr) {
        if (curr->next->data == value) {
            tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            if (curr->next == nullptr) {  // Update tail
                this->tail = curr;
            }
            num_deleted++;
        }
        curr = curr->next;
    }
    if (isEmpty()) {
        this->tail = nullptr;
    }
    if (num_deleted) {
        std::cout << "Deleted " << num_deleted
            << " nodes with value " << value << '.' << std::endl;
    }
    else {
        if (!isEmpty()) {
            std::cout << "Value " << value << " not found in list."
                << std::endl;
        }
        else {
            std::cout << "List is empty." << std::endl;
        }
    }
}


template <typename T>
void LinkedList<T>::printSequence() {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
    }
    else {
        Node<T>* node = this->head;
        std::cout << "Singly linked list sequence:" << std::endl;
        while (node != nullptr) {
            std::cout << node->data << ' ';
            node = node->next;
        }
        std::cout << std::endl;
    }
}


#endif /* LIST_H_ */
