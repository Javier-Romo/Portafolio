//Francisco Javier Romo Juárez
//A01643189
//29/09/2023
//Act 2.1 - Implementación de un ADT de estructura de datos lineales
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <ostream>

struct MyNodoLL
{
    int data;
    MyNodoLL* next;

    MyNodoLL(int data, MyNodoLL* next)
    {
        this->data=data;
        this->next=next;
    }

    MyNodoLL(int data):MyNodoLL(data,nullptr){}

};

class MyLinkedList
{
    public:
        int size;
        MyNodoLL* head;
        MyNodoLL* tail;
        MyLinkedList();
        ~MyLinkedList();
        int length();
        bool isEmpty();
        int first(); //Exc invalid_argument
        int last(); //Exc invalid_argument
        int getAt(int pos); //Exc invalid_argument
        void setAt(int pos,int data); //Exc invalid_argument
        void insertFirst(int data);
        void insertLast(int data);
        void insertAt(int pos,int data); //pos:[0,size] Exc invalid_argument
        void removeFirst(); //Exc invalid_argument
        void removeLast(); //Exc invalid_argument
        void removeAt(int pos); //pos:[0,size] Exc invalid_argument
        friend std::ostream& operator<<(std::ostream& os,const MyLinkedList& ll) //Imprime los elementos de la lista separados por coma y sin ningún espacio entre los elementos y la coma. Ejemplo: 1,2,3,4,5,
        //Complejidad Computacional = O(n)
        {
            MyNodoLL*current = ll.head;
            for(int i=0;i<ll.size;i++)
            {
                os<<current->data<<",";
                current = current->next;
            }
            return os;
        }
};
#endif