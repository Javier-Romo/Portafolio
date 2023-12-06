//Francisco Javier Romo Juárez 
//A01643189
//Act1_1

#include <iostream>
using namespace std;

int sumaIterativa(int n) // ORDEN = O(n)
{
    int suma = 0;
    for(int i=1; i < n+1 ;i++)
    {
        suma = suma + i;
    }
    return suma;
}

int sumaRecursiva(int n) // ORDEN = O(n^2)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n+sumaRecursiva(n-1);
    }
}

int sumaDirecta(int n) //ORDEN = O(1)
{
    return (n*(n+1))/2;
}

int main()
{
    int n;
    cout<<"Suma de 1 hasta un numero n"<<endl<<endl;
    cout<<"introduzca un numero entero:"<<endl;
    cin>>n;
    cout<<"Resultado de funcion Iterativa: "<<sumaIterativa(n)<<endl<<endl;
    cout<<"Resultado de funcion Recursiva: "<<sumaRecursiva(n)<<endl<<endl;
    cout<<"Resultado de funcion Directa: "<<sumaDirecta(n);
    return 0;
}
