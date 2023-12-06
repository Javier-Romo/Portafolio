#ifndef CAJA_H
#define CAJA_H
#include "Rectangulo.h"
class Caja:public Rectangulo
{
    private:
        double alto;
    public:
        Caja(double largo, double ancho, double alto);
        Caja();
        double perimetro();
        double area();
        double volumen();
        void imprimir();
};
#endif