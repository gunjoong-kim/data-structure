
#include "StackP.hpp"
#include <iostream>

StackClass::StackClass() {
    top = nullptr;
}

StackClass::StackClass(const StackClass &s) {
    node *tmp = s.top;
    while (tmp != nullptr) {
        this->push(tmp->data);
        tmp = tmp->next;
    }
}

StackClass::~StackClass() {
    while (is_empty()) {
        pop();
    }
}

void StackClass::push(int item) {
    node *new_top = new node;
    new_top->data = item;
    new_top->next = this->top;
    this->top = new_top;
}

int StackClass::pop() {
    if (is_empty())
        std::cout << "Deletion on Emtpy stack\n";
    else {
        node *tmp = this->top;
        int ret = tmp->data;
        this->top = tmp->next;
        delete tmp;
        return ret;
    }
}

bool StackClass::is_empty() {
    if (this->top == nullptr)
        return true;
    return false;
}