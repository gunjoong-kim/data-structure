#include "StackA.hpp"
#include <iostream>

StackClass::StackClass() {
    this->top = -1;
}

StackClass::StackClass(const StackClass &s) {
    this->top = s.top;
    for (int i = 0; i <= this->top; i++) {
        this->stack[i] = s.stack[i];
    }
}

StackClass &StackClass::operator=(const StackClass &s) {
    this->top = s.top;
    for (int i = 0; i <= this->top; i++) {
        this->stack[i] = s.stack[i];
    }

    return *this;
}

void StackClass::push(int item) {
    this->top++;
    this->stack[this->top] = item;
}

int StackClass::pop() {
    int result = this->stack[this->top];
    this->top--;

    return result;
}

int StackClass::peek() {
    return this->stack[this->top];
}

bool StackClass::is_empty() {
    if (this->top + 1 >= STACK_MAX)
        return true;
    return false;
}

bool StackClass::is_full() {
    if (this->top == -1)
        return true;
    return false;
}
 