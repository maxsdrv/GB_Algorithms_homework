//
// Created by maksim.sidorov on 11.05.2021.
//

#ifndef SOURCE_MYSTACK_H
#define SOURCE_MYSTACK_H

template <typename T>
class myStack {
public:
    myStack() = default;
    ~myStack() = default;

    bool pushStack(myStack *stack);
    T popStack(myStack *stack);
    bool isEmpty(myStack *stack);
    void Print();
private:
template <typename U>
class Node {
public:
    Node* pNext;
    T data;
private:
    int Size;
    Node<T>* head;
};
};

template <typename T>
bool myStack<T>::pushStack(myStack *stack) {
    return false;
}

template <typename T>
T myStack<T>::popStack(myStack *stack) {
    return this;
}

template <typename T>
bool myStack<T>::isEmpty(myStack *stack) {
    return false;
}

template <typename T>
void myStack<T>::Print() {
    std::cout << "Test successful" << std::endl;
}


#endif //SOURCE_MYSTACK_H











