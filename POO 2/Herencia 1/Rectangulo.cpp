#include "Rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo(double largo, double ancho)
{
    this-> largo = largo;
    this-> ancho  = ancho;
}

Rectangulo::Rectangulo():Rectangulo(2.0,3.0){}

void Rectangulo::imprimir()
{
    cout<<"Soy un rectangulo de largo"<<this->largo<<" y ancho "<<this->ancho<<endl;
}

double Rectangulo::perimetro()
{
    return 2.0*(this->largo+this->ancho);
}

double Rectangulo::area()
{
    return this->largo*this->ancho;
}

double Rectangulo::volumen()
{
    return 0.0;
}