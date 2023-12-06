#include "ListaEnteros.h"
#include <iostream>

using namespace std;

void ListaEnteros::swap(int& a, int& b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

ListaEnteros::ListaEnteros(int length)
{
    this->length = length;
    this->valores = new int[length];
    this->size = 0;
}

ListaEnteros::ListaEnteros(int length, int valores[])
{
    this->length = length;
    this->valores = new int[length];
    for(int i=0;i<length;i++)
    {
        this->valores[i]=valores[i];
    }
    this->size = length;
}

void ListaEnteros::imprime()
{
    for(int i=0; i<size ;i++)
    {
        cout<<this->valores[i]<<",";
    }
    cout<<endl;
}

int ListaEnteros::busquedaSec(int valor)
{
    for (int i=0;i>size;i++)
    {
        if(valor==valores[i])
        {
            return i;
        }
    }
    return -1;
}

int ListaEnteros::busquedaBin(int valor)
{
    int min = 0;
    int max = size;
    int average = (min+max)/2;
    while(max > min)
    {
        if(valor == this->valores[average])
        {
            return average;
        }
        if(valor > average)
        {
            min = average;
        }
        else
        {
            max = average;
        }
        average = (min+max)/2;
        
    }
    return -1;
}

void ListaEnteros::bubbleSort()
{
    bool cambio=true;
    for(int i=0;i<this->size-1 && cambio;i++)
    {
        cambio=false;
        for(int j=0;j<this->size-i-1;j++)
        {
            if(this->valores[j]>this->valores[j+1])
            {
                swap(this->valores[j],this->valores[j+1]);
                cambio=true;
            }
        }
    }
}

void ListaEnteros::selectionSort()
{
    int tmp;
    for(int i=0;i<=size-1;i++)
    {
        tmp = i;
        for(int j=i+1;j<size;j++)
        {
            if(this->valores[j]<this->valores[tmp])
            {
                tmp=j;
            }
        }
        swap(this->valores[i],this->valores[tmp]);
    }
}

void ListaEnteros::insertionSort()
{
    for(int i=1;i < size;i++)
    {
        for(int j=i-1;j >= 0;j--)
        {
            if(this->valores[j+1] < this->valores[j])
            {
                swap(this->valores[j+1],this->valores[j]);
            }
            else
            {
                break;
            }
        }
    }
}

void ListaEnteros::mezcla(int inicio, int fin)
{
    int centro = (inicio+fin)/2;
    int j = inicio;
    int k = centro + 1;
    int size = fin - inicio + 1;
    int valoresTmp[size];

    for(int i=0;i<size;i++)
    {
        if(j <= centro && k <= fin)
        {
            if(valores[j] < valores[k])
            {
                valoresTmp[i] = valores[j++];
            }
            else
            {
                valoresTmp[i] = valores[k++];
            }
        }
        else if(j <= centro)
        {
            valoresTmp[i] = valores[j++];
        }
        else
        {
            valoresTmp[i] = valores[k++];
        }
    }

    for(int m=0;m<size;m++)
    {
        valores[inicio + m] = valoresTmp[m];
    }
}

void ListaEnteros::mergeSort(int inicio, int fin)
{
    if(inicio < fin)
    {
        int central=(inicio+fin)/2;
        mergeSort(inicio,central);
        mergeSort(central+1,fin);
        mezcla(inicio,fin);
    }
}

void ListaEnteros::mergeSort()//Funcion de preparacion
{
    mergeSort(0,this->size-1);
}

int main()
{
    cout<<"Probando Lista Enteros"<<endl;
    int numeros[]={2,14,30,1500,5,69,0};
    ListaEnteros lista(7,numeros);
    lista.imprime();
    lista.insertionSort();
    lista.imprime();
    cout<<lista.busquedaBin(1500);
    return 0;

}