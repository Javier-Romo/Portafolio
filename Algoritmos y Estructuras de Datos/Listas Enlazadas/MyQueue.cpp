#include "MyQueue.h"

bool MyQueue::isEmpty()
{
    return this->lista.isEmpty();
}

int MyQueue::length()
{
    return this->lista.length();
}

void MyQueue::enqueue(int data)
{
    this->lista.insertLast(data);
}

void MyQueue::dequeue()
{
    this->lista.removeFirst();
}


