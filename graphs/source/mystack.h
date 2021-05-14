//
// Created by maksim.sidorov on 11.05.2021.
//

#ifndef SOURCE_MYSTACK_H
#define SOURCE_MYSTACK_H

#define T int

class Node {
public:
    Node() {
        data = 0;
        next = nullptr;
    }
    T data;
    Node *next;
private:
};

class Stack {
public:
    Stack() : head(nullptr), size(0) {}

    static bool pushStack(Stack *stack, T value);
    void Displayed(Stack *stack) const;

    Node *head;
    int size;
private:
};


bool Stack::pushStack(Stack *stack, T value) {
    auto *temp = new Node;

    temp->data = value;
    temp->next = stack->head;

    stack->head = temp;
    stack->size++;
    return true;

}

T popStack(Stack *stack) {
    if (stack->size == 0) {
        std::cout << "Stack is empty" << std::endl;
        return false;
    }
    Node *temp = stack->head;
    T data = stack->head->data;
    stack->head = stack->head->next;
    delete temp;
    stack->size--;
    return data;
}

void Stack::Displayed(Stack *stack) const{
    
}

#endif //SOURCE_MYSTACK_H











