//Francisco Javier Romo Juárez
//A01643189
//29/09/2023
//Act 2.1 - Implementación de un ADT de estructura de datos lineales
#include "MyLinkedList.h"
#include <iostream>

using namespace std;

MyLinkedList::MyLinkedList()//Complejidad Computacional = O(1)
{
    this->size=0;
    this->head=this->tail=nullptr;
}

MyLinkedList::~MyLinkedList()//Complejidad Computacional = O(n)
{
    MyNodoLL* current = this->head;
    for(int i=0;i<this->size;i++)
    {
        delete current;
        current = current->next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;

}

int MyLinkedList::length()//Complejidad Computacional = O(1)
{
    return this->size;
}

bool MyLinkedList::isEmpty()//Complejidad Computacional = O(1)
{
    return this->size == 0;
}

int MyLinkedList::first()//Complejidad Computacional = O(1)
{
    if(this->size!=0)
    {
        return this->head->data;
    }
    else
    {
        throw invalid_argument("No se puede obtener el primer valor de una lista vacia");
    }
}

int MyLinkedList::last()//Complejidad Computacional = O(1)
{
    if(this->size!=0)
    {
        return this->tail->data;
    }
    else
    {
        throw invalid_argument("No se puede obtener el ultimo valor de una lista vacia");
    }
}

int MyLinkedList::getAt(int pos)//Complejidad Computacional = O(n)
{
    if(!isEmpty())
    {
        MyNodoLL* current = this->head;
        for(int i=0;i<pos;i++)
        {
            current = current->next;
        }
        return current->data;
    }
    else
    {
        throw invalid_argument("No se puede obtener el valor en esa posicion de una lista vacia");
    }
}

void MyLinkedList::setAt(int pos, int data)//Complejidad Computacional = O(n)
{
    if(!isEmpty())
    {
        MyNodoLL* current = this->head;
        for(int i=0;i<pos;i++)
        {
            current = current->next;
        }
        current->data = data;
    }
    else
    {
        throw invalid_argument("No se puede poner el valor en esa posicion de una lista vacia");
    }
}

void MyLinkedList::insertFirst(int data)//Complejidad Computacional = O(1)
{
    this->head = new MyNodoLL(data,this->head);
    this->size++;
    if(this->size==1)
    {
        this->tail=this->head;
    }
}

void MyLinkedList::insertLast(int data)//Complejidad Computacional = O(1)
{
    this->tail->next = new MyNodoLL(data,nullptr);
    this->tail = this->tail->next;
    this->size++;
    if(this->size==1)
    {
        this->head=this->tail;
    }
}

void MyLinkedList::insertAt(int pos, int data)//Complejidad Computacional = O(n)
{
    if(pos==0)
    {
        insertFirst(data);
    }
    else if(pos==this->size)
    {
        insertLast(data);
    }
    else if(pos<this->size && pos > 0)
    {
        MyNodoLL* current = this->head;
        for(int i=1;i<pos;i++)
        {
            current = current->next;
        }
        current->next = new MyNodoLL(data,current->next);
        this->size++;
    }
    else
    {
        throw invalid_argument("No se puede insertar un valor en una posicion mayor al tamano y una posicion negativa");
    }
}

void MyLinkedList::removeFirst()//Complejidad Computacional = O(1)
{
    if(!isEmpty())
    {
        MyNodoLL*aux = this->head;
        this->head=this->head->next;
        delete aux;
        size--;
        if(this->size == 0)
        {
            this->tail=nullptr;
        }
    }
    else
    {
        throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
    }
}

void MyLinkedList::removeLast()//Complejidad Computacional = O(n)
{
    if(this->size == 1)
    {
        removeFirst();
    }
    else if(!isEmpty())
    {
        MyNodoLL*current = this->head;
        for(int i=1;i<this->size-1;i++)
        {
            current = current->next;
        }
        this->tail=current;
        delete current->next;
        size--;
    }
    else
    {
        throw invalid_argument("No se puede borrar el ultimo elemento de una lista vacia");
    }
}

void MyLinkedList::removeAt(int pos)//Complejidad Computacional = O(n)
{
    if(pos==0)
    {
        removeFirst();
    }
    else if(pos==this->size)
    {
        removeLast();
    }
    else if(pos<this->size && pos > 0)
    {
        MyNodoLL* current = this->head;
        for(int i=1;i<pos;i++)
        {
            current = current->next;
        }
        MyNodoLL* aux = current->next;
        current->next = current->next->next;
        delete aux;
        size--;
    }
    else
    {
        throw invalid_argument("No se puede borrar un valor en una posicion mayor al tamano y en una posicion menor a cero");
    }
}

/*int main()
{
    int first;
    int last;
    int length;
    int get;
    bool empty;
    system("cls");
    MyLinkedList a;
    a.insertFirst(8);
    a.insertLast(4);
    a.insertLast(2);
    a.insertFirst(10);
    a.insertAt(2,20);
    cout<<a<<endl;
    a.removeAt(2);
    cout<<a<<endl;
    a.setAt(1,13);
    first = a.first();
    last = a.last();
    length = a.length();
    empty = a.isEmpty();
    get = a.getAt(1);
    cout<<last<<" "<<first<<" "<<length<<" "<<empty<<" "<<get;
    return 0;
}
*/