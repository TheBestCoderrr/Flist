#pragma once

#include <iostream>
using namespace std;
template <class type>
class Node
{
public:
    explicit Node(type v, Node* n = nullptr) :value(v), next(n) {};
    type getValue() const { return value; }
    void setValue(type v) { value = v; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }

    void Print() const {
        cout << value << "\t";
    }

private:
    type value;
    Node* next;
};
