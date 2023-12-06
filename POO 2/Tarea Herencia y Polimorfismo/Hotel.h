#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cstdio>
#include "Habitacion.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"
#include <vector>
using namespace std;

class Hotel
{
    private:
     vector<Habitacion*> habitaciones;
     int numHabitacionesJunior;
     int numHabitacionesSuite;
     int numHabitacionesDeluxe;
     string nombreHotel;

    public:
     Hotel(string nuevoNombreHotel, int numHabitacionesJunior, int numHabitacionesSuite, int numHabitacionesDeluxe);
     int getNumHabitacionesJunior();
     int getNumHabitacionesSuite();
     int getNumHabitacionesDeluxe();
     string getNombreHotel();
     int checkin(string nuevoNombreHuesped,int nuevoAdultos,int nuevoInfantes,double nuevoCredito);
     bool checkOut(int nuevoNumeroHabitacion);
     bool realizarCargosHabitacion(int nuevoNumeroHabitacion,double nuevoCargo);
     double getTotalXTarifaBase();
     void imprimeOcupacion();


};

#endif
