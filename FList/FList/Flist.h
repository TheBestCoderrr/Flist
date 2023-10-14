#pragma once
#include "Node.h"
template <class type>
class FList {
public:
    FList() :head(nullptr), tail(nullptr), counter(0) {}
    ~FList();

    size_t size() const { return counter; }
    void push_back(type v);
    void push_front(type v);
    void pop_front();
    void pop_back();
    void DeleteAll();
    Node<type>* findNode(size_t index) const;
    void insert(size_t index, type v);
    void pop_position(size_t index);
    int Replace(type fv, type v);
    void Reverse();
    void print() const;
private:
    Node<type>* head;
    Node<type>* tail;
    size_t counter;
};

template <class type>
FList<type>::~FList() { DeleteAll(); }


template <class type>
void FList<type>::push_back(type v)
{
    Node<type>* temp = new Node<type>(v);
    if (tail)
        tail->setNext(temp);
    else
        head = temp;
    tail = temp;
    ++counter;
}

template <class type>
void FList<type>::push_front(type v)
{
    head = new Node<type>(v, head);
    if (!tail) tail = head;
    ++counter;
}

template <class type>
void FList<type>::pop_front()
{
    if (head) {
        Node<type>* temp = head;
        head = head->getNext();
        delete temp;
        --counter;
        if (!head) tail = nullptr;
    }
}


template <class type>
void FList<type>::pop_back()
{
    if (!head) return;
    else if (head == tail) {
        delete head;
        head = nullptr;
        counter = 0;
        return;
    }
    Node<type>* temp = head;
    while (temp->getNext() != tail)
        temp = temp->getNext();
    tail = temp;
    tail->setNext(nullptr);
    delete temp->getNext();
    --counter;
}

template <class type>
void  FList<type>::DeleteAll() { while (counter > 0) { pop_back(); } }

template <class type>
Node<type>* FList<type>::findNode(size_t index) const {
    if (index >= counter) return nullptr;
    size_t n = 0;
    Node<type>* cur = head;
    while (cur) {
        if (n == index) break;
        cur = cur->getNext();
        n++;
    }
    return cur;
}

template <class type>
void FList<type>::insert(size_t index, type v) {
    if (index >= counter) return;
    if (index == 0) { push_front(v); return; }
    if (index == counter - 1) { push_back(v); return; }
    Node<type>* prev = findNode(index - 1);
    Node<type>* temp = new Node<type>(v, prev->getNext());
    prev->setNext(temp);
    ++counter;
}

template <class type>
void FList<type>::pop_position(size_t index) {
    if (index >= counter) return;
    if (index == 0) { pop_front(); return; }
    if (index == counter - 1) { pop_back(); return; }
    Node<type>* prev = findNode(index - 1);
    Node<type>* temp = prev->getNext();
    prev->setNext(temp->getNext());
    delete temp;
    --counter;
}

template <class type>
int FList<type>::Replace(type fv, type v){
    Node<type>* cur = head;
    int count = 0;
    while (cur) {
        if (cur->getValue() == fv) {
            count++;
            cur->setValue(v);
        }
        cur = cur->getNext();
    }
    return count > 0 ? count : -1;
}

template <class type>
void FList<type>::Reverse() {
    if (head == nullptr || head == tail) return;

    Node<type>* prev = nullptr;
    Node<type>* next = nullptr;
    Node<type>* current = head;

    while (current) {
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    Node<type>* temp = head;
    head = tail;
    tail = temp;
}

template <class type>
void FList<type>::print() const {
    Node<type>* cur = head;
    while (cur) {
        cur->Print();
        cur = cur->getNext();
    }
    cout << endl;
}