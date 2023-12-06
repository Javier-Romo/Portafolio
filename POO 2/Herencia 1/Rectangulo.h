#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "Figura.h"

class Rectangulo:public Figura
{
    protected:
        double largo;
        double ancho;
    public:
        Rectangulo(double largo, double ancho);
        Rectangulo();
        void imprimir();
        double perimetro();
        double area();
        double volumen();
};
#endif