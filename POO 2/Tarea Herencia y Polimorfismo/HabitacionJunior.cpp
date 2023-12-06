#include "HabitacionJunior.h"
#include <string.h>
#include <sstream>

using namespace std;

HabitacionJunior::HabitacionJunior()
{
        numero = 0;
        nombre = "";
        adultos = 0;
        infantes = 0;
        credito = 0;
        cargo = 0;
        disponible = true;
}

HabitacionJunior::HabitacionJunior(int numero)
{
    this->numero = numero+100;
    disponible = true;
}

bool HabitacionJunior::checkIn(string nombre, int adultos, int infantes, double credito)
{
    if (disponible == true && adultos+infantes < 5)
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

double HabitacionJunior::getTarifaBase()
{

    return ((450*adultos) + (150*infantes))*0.20;
}


string HabitacionJunior::toString()
{
    ostringstream oracion;
    oracion <<numero<<",Huesped:"<<nombre<<",Tarifa Base:"<<getTarifaBase()<<",Credito:"<<credito<<",Cargos:"<<cargo<<",Habitacion Junior"<<endl;
    return oracion.str();
}

