#include "Caja.h"
#include <iostream>
using namespace std;

Caja::Caja(double largo, double ancho, double alto):Rectangulo(largo, ancho)
{
    this -> alto = alto;
}

Caja::Caja():Caja(2.0,3.0,4.0){}

double Caja::perimetro()
{
    return 8.0*this->alto+4*this->largo+2*this->ancho;
}

double Caja::area()
{
    return 2.0*(this->largo*this->alto+this->ancho*this->alto+Rectangulo::area());
}

double Caja::volumen()
{
    return Rectangulo::area()*this->alto;
}

void Caja::imprimir()
{
    cout<<"Soy una caja de ancho "<<this->ancho<<", largo "<<this->largo<<" y alto "<<this->alto<<endl;
}