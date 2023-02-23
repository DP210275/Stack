#ifndef STACK
#define STACK
#include <cstddef>
#include <memory>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <exception>

class bad_stack_op : public std::logic_error {
    public:
    bad_stack_op(std::string msg) : logic_error(msg) {}
};

template <typename T>
struct StackNodeT {
	T data;
	std::shared_ptr<StackNodeT<T>> link;
};

template <typename T>
class StackT {
   public:
       StackT<T>();
       StackT<T>(const StackT<T>&);

       ~StackT<T>();
       StackT<T>& operator=(const StackT<T>&);

       StackT<T>(StackT<T>&&) noexcept;
       StackT<T>& operator=(StackT<T>&& rhs) noexcept;

       void Push(T);
       void Pop();
       T Top() const;

       std::size_t Size() const;

       bool IsEmpty() const;

   private:
        std::shared_ptr<StackNodeT<T>> stack;
        std::size_t size;
};

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
        throw bad_stack_op("Pop attempted on Empty Stack");  
    } else {
        std::shared_ptr<StackNodeT<T>> temp {stack};
        stack = stack->link;
        size--;   
    }
 
}

template <typename T>
T StackT<T>::Top() const {
    if(IsEmpty()){
        throw bad_stack_op("Top attempted on Empty Stack");
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

/*
template <typename T>
void AttemptPop(std::shared_ptr<StackNodeT<T>> stack) {
    std::shared_ptr<StackNodeT<T>> temp {stack};
    bool empty;
    try{
        if (temp == nullptr) {
            bool empty = {false};
        }
        TryPop(bool empty);
    } catch(const bad_stack_op& le) {
        std::cout << "Logic Error: " << le.what() << std::endl; 
    }
    return;
}

template <typename T>
void AttemptTop(std::shared_ptr<StackNodeT<T>> stack){
    std::shared_ptr<StackNodeT<T>> temp{stack};
    bool empty;
    try {
        if (temp == nullptr) {
            bool empty = {false};
        }
        TryTop(bool empty);
    } catch(const bad_stack_op& le) {
        std::cout << "Logic Error: " << le.what() << std::endl; 
    }
    return;
}
*/
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

//#include "Stack.cpp"
#endif