#ifndef HABITACIONSUITE_H
#define HABITACIONSUITE_H
#include "Habitacion.h"
#include <string.h>

class HabitacionSuite:public Habitacion
{
    public:
        HabitacionSuite();
        HabitacionSuite(int numero); 
        bool checkIn(string nombre, int adultos, int infantes, double credito);
        double getTarifaBase();
        string toString();
};

#endif