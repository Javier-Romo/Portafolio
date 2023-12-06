#ifndef HABITACIONJUNIOR_H
#define HABITACIONJUNIOR_H
#include "Habitacion.h"
#include <string.h>

class HabitacionJunior:public Habitacion
{
    public:
        HabitacionJunior();
        HabitacionJunior(int numero); 
        bool checkIn(string nombre, int adultos, int infantes, double credito);
        double getTarifaBase();
        string toString();
};

#endif