// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T data[size];
    int top;
public:
    TStack() : top(0) {}
    void push(const T& item) {
        if (top <= size - 1) data[top++] = item;
        else throw std::string("Full");
    }
    T pop() {
        if (top > 0) return data[--top];
        else throw std::string("Empty");
    }
};

#endif  // INCLUDE_TSTACK_H_
