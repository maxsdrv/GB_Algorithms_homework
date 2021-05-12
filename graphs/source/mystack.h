//
// Created by maksim.sidorov on 11.05.2021.
//

#ifndef SOURCE_MYSTACK_H
#define SOURCE_MYSTACK_H

template <typename T>
class myStack {
public:
    myStack() {
        Size = 0;
        head = nullptr;
    }
    ~myStack() {
        std::cout << "Destructor" << std::endl;
    }

    bool pushStack(T value);
    T popStack(myStack *stack);
    bool isEmpty(myStack<T> &stack);
    int GetSize() { return Size; }
    void PrintStack(myStack<T> &stack);

private:
template <typename U>
class Node {
public:
    explicit Node (T data = T(), Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
    Node* pNext;
    T data;
private:
};
    Node<T> *head;
    int Size;
};

template <typename T>
bool myStack<T>::pushStack(T value) {
    auto *temp = new Node<T>;
    if (temp == nullptr) {
        std::cout << "Stack overflow";
        return false;
    }
    temp->data = value;
    temp->pNext = head;

    head = temp;
    Size++;
    return true;
}

template <typename T>
T myStack<T>::popStack(myStack<T> *stack) {
    if (isEmpty()) {
        return false;
    }
    Node<T> *temp = stack->head;
    T data = stack->head->data;
    stack->head = stack->head->pNext;
    delete temp;
    stack->Size--;
    return data;
}

template <typename T>
bool myStack<T>::isEmpty(myStack<T> &stack) {
    if (stack.Size == 0) {
        std::cout << "Stack is empty" << std::endl;
        return false;
    }
    return true;
}

template <typename T>
void myStack<T>::PrintStack(myStack<T> &stack) {
    if (stack.isEmpty(stack)) {
        return;
    }

}




#endif //SOURCE_MYSTACK_H











