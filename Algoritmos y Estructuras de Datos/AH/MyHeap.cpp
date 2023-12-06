//Francisco Javier Romo Juárez
//A01643189
//31/10/2023
//Act 3.2 - Árbol Heap: Implementación una fila priorizada
#include "MyHeap.h"
#include <iostream>

using namespace std;

MyHeap::MyHeap(){ //Complejidad en todos los casos: O(1) 
      this->values = new int[7];
      this->size = 0;
      this->len = 7;
}

MyHeap::MyHeap(int* valores, int size){ //Complejidad en el mejor de los casos: O(n), esto pasa cuando no es necesario hacer ningún swap y solo se hace un recorrido por posición.
                                        //Complejidad en el pero de los casos: O(n log n), esto pasa cuando es necesario hacer el proceso de swap y esto conlleva a hacer un heapify recursivo.
      this->values = valores;
      this->len = this->size = size;
      heapify();
}

void MyHeap::swap(int& large, int& realLarge){ //Complejidad en todos los casos: O(1)
      int tmp = large;
      large = realLarge;
      realLarge = tmp;
}

void MyHeap::heapify(){ //Complejidad en el mejor de los casos: O(n), esto pasa cuando no es necesario hacer ningún swap y solo se hace un recorrido por posición.
                        //Complejidad en el pero de los casos: O(n log n), esto pasa cuando es necesario hacer el proceso de swap y esto conlleva a hacer un heapify recursivo.
      for(int i=(size - 1)/2; i >= 0; i--){
            heapify(i);
      }
}

void MyHeap::heapify(int index){ //Complejidad en el mejor de los casos: O(n), esto pasa cuando no es necesario hacer ningún swap y solo se hace un recorrido por posición.
                                 //Complejidad en el pero de los casos: O(n log n), esto pasa cuando es necesario hacer el proceso de swap y esto conlleva a hacer un heapify recursivo.
      int large = index;
      int leftSon = 2*index + 1;
      int rightSon = 2*index + 2;
      if(leftSon < this->size && this->values[large] < this->values[leftSon]){
            large = leftSon;
      }

      if(rightSon < this->size && this->values[large] < this->values[rightSon]){
            large = rightSon;
      }
      
      if(large != index){
            swap(this->values[index], this->values[large]);
            heapify(large);
      }


}

void MyHeap::push(int n){ // Complejidad en el mejor de los casos: O(log n), sí no es necesario crecer el arreglo
                          // Complejidad en el peor de los casos: O(n log n), sí es necesario crecer el arreglo
      if(this->size == this->len){
            int* temporal = new int[2*this->len+1];
            for(int i=0;i<size;i++){
                  temporal[i] = this->values[i];
            }
            delete this->values;
            this->values = temporal;
            this->len = 2*this->len+1;
      }
      this->values[size] = n;
      this->size++;
      int current = size-1;
      int fatherCurrent = (current-1)/2;
      while(current>0){
            if(this->values[fatherCurrent] < this->values[current]){
                  swap(this->values[fatherCurrent], this->values[current]);
                  current = fatherCurrent;
                  fatherCurrent = (current-1)/2;
            }     
            else{
                  break;
            }
      }
}

void MyHeap::pop(){ //Complejidad en todos los casos: O(log n), debido a que siempre se va a tener que hacer el mismo proceso para reorganizar el arbol depues del pop.
      if(isEmpty()){
            throw invalid_argument("No es posible hacer pop en una lista vacía");
      }
      swap(this->values[0], this->values[this->size-1]);
      this->size--;
      heapify(0);
}

int MyHeap::top(){ //Complejidad en todos los casos: O(1)
      if(isEmpty()){
            throw invalid_argument("No hay valores iniciales en una lista vacía");
      }
      return this->values[0];
}

bool MyHeap::isEmpty(){ //Complejidad en todos los casos: O(1)
      if(this->size == 0){
            return true;
      }
      return false;
}

int MyHeap::length(){ //Complejidad en todos los casos: O(1)
      return this->size;
}

void MyHeap::imprimir(){ //Complejidad en el peor de los casos: O(n), recorre toda lista
                         //Complejidad en el mejor de los casos: O(1), en caso de ser una lista vacía solo hace dos cout y no entra al for
      cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
      for(int i=0; i<this->size; i++){
            cout<<values[i]<<",";
      }
      cout<<endl;
}

