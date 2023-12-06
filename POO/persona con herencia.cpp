#include <iostream>
#include "persona.h"

using namespace std;


int main()
{
    string nombre;
    int edad;
    Persona objeto;

    /*Pedir Datos*/
    cout<<"Bienvenido al programa"<<endl;
    cout<<"Dime tu nombre: ";
    cin>>nombre;
    cout<<"Dime tu edad: ";
    cin>>edad;
    /*Guardar Datos*/
    objeto.setNombre(nombre);
    objeto.setEdad(edad);
    /*Mostrar Datos*/
     cout<<endl<<"-----------------"<<endl;
     cout<<"Los datos guardados son:"<<endl;
     cout<<"Nombre:"<<objeto.getNombre()<<endl;
     cout<<"Edad:"<<objeto.getEdad()<<endl;

    return 0;
}

