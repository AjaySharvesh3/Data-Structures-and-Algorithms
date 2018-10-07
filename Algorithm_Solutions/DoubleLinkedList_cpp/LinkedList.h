#pragma once
#include <iostream>
template <typename T>

class LinkedList {
    private:
        /* Node struct private, end user doesn't need to know 
         * internal implementation of the nodes
         * Encapsulation
         */
        struct Node {
            const T data;
            Node* next;
            Node* prev;
            Node();
            Node(const T& data);
        };
        Node *head;
        Node *tail;
        int size;
    public:
        int size() const;
        LinkedList();
        ~LinkedList();
        void clear();
        void push_front(const T& data);
        void push_back(const T& data);
        void insert(const T& data, int index);
        void pop_front();
        void pop_back();
        void remove(int index);
        bool empty() const;
        Node* get(int index) const;

};

#include "LinkedList.hpp" //for template instantiation
