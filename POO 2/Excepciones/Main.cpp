#include "MyException.h"
#include <iostream>

void metodoD()
{
    bool errorEx=true;
    if(errorEx)
    {
        throw MyException("Error en D");
    }
}

void metodoC()
{
    metodoD();
}

void metodoB()
{
    metodoC();
}

void metodoA()
{
    metodoB();
}

int main()
{
    try
    {
        cout<<"Iniciando ejecucion "<<endl;
        metodoA();
        cout<<"Exito en la finalizacion "<<endl;
    }
    catch(MyException& ex)
    {
        cout<<"Ocurrio un error inesperado. Intenta despues"<<endl;
        cout<<ex.what()<<endl;
    }
    return 0;
}