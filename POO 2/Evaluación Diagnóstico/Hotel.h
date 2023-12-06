#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cstdio>
#include "Habitacion.h"
#include <string.h>
using namespace std;

class Hotel
{
    private:
     Habitacion habitacion[50];
     int numHabitaciones;
     string nombreHotel;

    public:
     Hotel(string nuevoNombreHotel);
     int getNumHabitaciones();
     string getNombreHotel();
     void setGlobal(int nuevoNumHabitaciones,string nuevoNombreHotel);
     int checkin(string nuevoNombreHuesped,int nuevoAdultos,int nuevoInfantes,double nuevoCredito);
     bool checkOut(int nuevoNumeroHabitacion);
     bool realizarCargosHabitacion(int nuevoNumeroHabitacion,double nuevoCargo);
     double getTotalXTarifaBase();
     void imprimeOcupacion();


};

#endif
