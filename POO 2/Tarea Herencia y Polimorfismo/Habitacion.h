#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
#include <cstdio>
using namespace std;

class Habitacion
{
    protected:
     int numero;
     string nombre;
     int adultos;
     int infantes;
     double credito;
     double cargo;
     bool disponible;

    public:
     Habitacion();
     Habitacion(int numero);
     int getNumero();
     string getNombre();
     int getAdultos();
     int getInfantes();
     double getCredito();
     double getCargo();
     bool getDisponible();
     void setGlobal(int nuevoNumero,string nuevoNombre,int nuevoAdultos,int nuevoInfantes,double nuevoCredito,double nuevoCargo,bool nuevoDisponible);
     virtual bool checkIn(string nuevoNombre,int nuevoAdultos,int nuevoInfantes,double nuevoCredito)=0;
     bool checkOut();
     virtual double getTarifaBase()=0;
     bool realizarCargo(double nuevoCargo);
     virtual string toString()=0;
};

#endif
