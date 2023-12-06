#ifndef MYSTACK_H
#define MYSTACK_H
#include "MyLinkedList.h"

class MyStack
{
    private:
        MyLinkedList lista;
    public:
        ~MyStack();
        void push(int data);
        void pop();
        int top();
        bool isEmpty();
        void flush();
};

#endif