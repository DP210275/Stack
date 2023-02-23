//David Pittman
//CSCI 330
//Implementing a stack/Improving the Stack

#include "Stack.h"

//std::shared_ptr<StackNodeT> temp {stack};
// <T>
/*
template <typename T>
void TryPop(std::shared_ptr<StackNodeT<T>> stack) {
    std::shared_ptr<StackNodeT<T>> temp {stack};
    try{
        if(temp == nullptr){
            throw std::logic_error ("Pop attempted on Empty Stack");
        }
    } catch(const std::logic_error& le) {
        std::cout << "Logic Error: " << le.what() << std::endl; 
    }
    return;
}

template <typename T>
void TryTop(std::shared_ptr<StackNodeT<T>> stack){
    std::shared_ptr<StackNodeT<T>> temp{stack};
    try {
        if (temp == nullptr){
            throw std::logic_error("Top attempted on Empty Stack");  
        }
    } catch(const std::logic_error& le) {
        std::cout << "Logic Error: " << le.what() << std::endl; 
    }
    return;
}

template <typename T>
void FreeNodes(std::shared_ptr<StackNodeT<T>> stack) {
    std::shared_ptr<StackNodeT<T>> temp {stack};
    while (temp != nullptr) {
        stack = stack->link;
        temp = stack;
        }
    }

template <typename T>
void CopyNodes(std::shared_ptr<StackNodeT<T>> fromStack, std::shared_ptr<StackNodeT<T>> & toStack) {
    std::shared_ptr<StackNodeT<T>> rhsCurrent {fromStack};
    std::shared_ptr<StackNodeT<T>> lhsCurrent {nullptr};

    if (fromStack != nullptr) {
        toStack = {std::make_shared<StackNodeT<T>>()};
        toStack->data = rhsCurrent->data;
        rhsCurrent = rhsCurrent->link;
        lhsCurrent = toStack;
        while(rhsCurrent != nullptr) {
            lhsCurrent->link = {std::make_shared<StackNodeT<T>>()};
            lhsCurrent = lhsCurrent->link;
            lhsCurrent->data = rhsCurrent->data;
            rhsCurrent = rhsCurrent->link;
        }
        lhsCurrent->link = nullptr;
    }
}
~~~~~~~~~~
template <typename T>
StackT<T>::StackT() :  stack(nullptr),
                    size(0) {

}

template <typename T>
StackT<T>::StackT(const StackT& rhs) :
    stack(nullptr),
    size(rhs.size) {

    CopyNodes(rhs.stack, stack);
}

template <typename T>
StackT<T>::~StackT() {
    FreeNodes(stack);
}

template <typename T>
StackT<T>& StackT<T>::operator=(const StackT<T>& rhs){
    if(this != &rhs) {
        FreeNodes(stack);
        stack = nullptr;
        size = rhs.size;

        CopyNodes(rhs.stack, stack);
    }
    return *this;
}

template <typename T>
StackT<T>::StackT(StackT<T>&& other) noexcept {
    size = std::exchange(other.size, 0);
    stack = std::exchange(other.stack, nullptr);
}

template <typename T>
StackT<T>& StackT<T>::operator=(StackT<T>&& rhs) noexcept {
    if (this != &rhs) {
        size = std::exchange(rhs.size, 0);
        stack = std::exchange(rhs.stack, stack);
    }
    return *this;
}

template <typename T>
void StackT<T>::Push(T newItem) {
    std::shared_ptr<StackNodeT<T>> newNode {std::make_shared<StackNodeT<T>>()};
    newNode->link = stack;
    newNode->data = newItem;
    stack = newNode;
    size++;
}
template <typename T>
void StackT<T>::Pop(){
    if (IsEmpty()){
        TryPop(stack);
        //throw std::logic_error ("Pop attempted on Empty Stack");  
    } else {
        std::shared_ptr<StackNodeT<T>> temp {stack};
        stack = stack->link;
        size--;   
    }
 
}

template <typename T>
T StackT<T>::Top() const {
    if(IsEmpty()){
        TryTop(stack);
        //throw std::logic_error("Top attempted on Empty Stack");
    } else {
        return stack->data;
    }
    return 0;
}

template <typename T>
size_t StackT<T>::Size() const {
    return size;
}

template <typename T>
bool StackT<T>::IsEmpty() const {
    return (size == 0);
}
*/