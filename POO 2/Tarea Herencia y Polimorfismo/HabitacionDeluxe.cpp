#include "HabitacionDeluxe.h"
#include <string.h>
#include <sstream>

using namespace std;

HabitacionDeluxe::HabitacionDeluxe()
{
        numero = 0;
        nombre = "";
        adultos = 0;
        infantes = 0;
        credito = 0;
        cargo = 0;
        disponible = true;
}

HabitacionDeluxe::HabitacionDeluxe(int numero)
{
    this->numero = numero+100;
    disponible = true;
}

bool HabitacionDeluxe::checkIn(string nombre, int adultos, int infantes, double credito)
{
    if (disponible == true && adultos+infantes < 9)
    {
        this-> nombre = nombre;
        this-> adultos = adultos;
        this-> infantes = infantes;
        this-> credito = credito;
        cargo = 0;
        disponible = false;
        return true;
    }
    else
    {
        return false;
    }
}

double HabitacionDeluxe::getTarifaBase()
{

    return ((450*adultos) + (150*infantes))*0.50;
}


string HabitacionDeluxe::toString()
{
    ostringstream oracion;
    oracion <<numero<<",Huesped:"<<nombre<<",Tarifa Base:"<<getTarifaBase()<<",Credito:"<<credito<<",Cargos:"<<cargo<<",Habitacion Deluxe"<<endl;
    return oracion.str();
}