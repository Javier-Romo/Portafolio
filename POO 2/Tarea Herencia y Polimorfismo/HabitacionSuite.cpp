#include "HabitacionSuite.h"
#include <string.h>
#include <sstream>

using namespace std;

HabitacionSuite::HabitacionSuite()
{
        numero = 0;
        nombre = "";
        adultos = 0;
        infantes = 0;
        credito = 0;
        cargo = 0;
        disponible = true;
}

HabitacionSuite::HabitacionSuite(int numero)
{
    this->numero = numero+100;
    disponible = true;
}

bool HabitacionSuite::checkIn(string nombre, int adultos, int infantes, double credito)
{
    if (disponible == true && adultos+infantes < 7)
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

double HabitacionSuite::getTarifaBase()
{

    return ((450*adultos) + (150*infantes))*0.30;
}


string HabitacionSuite::toString()
{
    ostringstream oracion;
    oracion <<numero<<",Huesped:"<<nombre<<",Tarifa Base:"<<getTarifaBase()<<",Credito:"<<credito<<",Cargos:"<<cargo<<",Habitacion Suite"<<endl;
    return oracion.str();
}