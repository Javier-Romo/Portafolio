#ifndef HABITACIONDELUXE_H
#define HABITACIONDELUXE_H
#include "Habitacion.h"
#include <string.h>

class HabitacionDeluxe:public Habitacion
{
    public:
        HabitacionDeluxe();
        HabitacionDeluxe(int numero); 
        bool checkIn(string nombre, int adultos, int infantes, double credito);
        double getTarifaBase();
        string toString();
};

#endif