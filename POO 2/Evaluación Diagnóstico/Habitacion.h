#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

class Habitacion
{
    private:
     int numero;
     string nombre;
     int adultos;
     int infantes;
     double credito;
     double cargo;
     bool disponible;

    public:
     Habitacion();
     Habitacion(int nuevoNumero);
     int getNumero();
     string getNombre();
     int getAdultos();
     int getInfantes();
     double getCredito();
     double getCargo();
     bool getDisponible();
     void setGlobal(int nuevoNumero,string nuevoNombre,int nuevoAdultos,int nuevoInfantes,double nuevoCredito,double nuevoCargo,bool nuevoDisponible);
     bool checkIn(string nuevoNombre,int nuevoAdultos,int nuevoInfantes,double nuevoCredito);
     bool checkOut();
     double getTarifaBase();
     bool realizarCargo(double nuevoCargo);
     string toString();
};

#endif
