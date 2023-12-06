#include "Hotel.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include "Habitacion.h"
using namespace std;

Hotel::Hotel(string nuevoNombreHotel)
{
    nombreHotel = nuevoNombreHotel;
    numHabitaciones = 50;
    Habitacion habitacion[numHabitaciones];
    for (int i=0;i < 50;i++)
    {
        habitacion[i] = habitacion[100+i];
    }
}

int Hotel::getNumHabitaciones()
{
    return numHabitaciones;
}

string Hotel::getNombreHotel()
{
    return nombreHotel;
}


void Hotel::setGlobal(int nuevoNumHabitaciones,string nuevoNombreHotel)
{
    numHabitaciones = nuevoNumHabitaciones;
    nombreHotel = nuevoNombreHotel;
}

int Hotel::checkin(string nuevoNombreHuesped,int nuevoAdultos,int nuevoInfantes,double nuevoCredito)
{
    int numHabitacion;
    for (int i=0;i < 50;i++)
    {
        if (habitacion[i].getDisponible() == true)
        {
            habitacion[i].checkIn(nuevoNombreHuesped,nuevoAdultos,nuevoInfantes,nuevoCredito);
            numHabitacion = habitacion[i].getNumero();
            return numHabitacion;
        }
    }
    return -1;


}

bool Hotel::checkOut(int nuevoNumeroHabitacion)
{
    if (nuevoNumeroHabitacion < 99 && nuevoNumeroHabitacion < 150)
    {
        bool validacion;
        validacion = habitacion[nuevoNumeroHabitacion - 100].checkOut();
        if (validacion == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int nuevoNumeroHabitacion,double nuevoCargo)
{
    if (habitacion[nuevoNumeroHabitacion - 100].getDisponible() == true)
    {
        bool validacion;
        validacion = habitacion[nuevoNumeroHabitacion - 100].realizarCargo(nuevoCargo);
        return validacion;
    }
    else
    {
        return false;
    }
}

double Hotel::getTotalXTarifaBase()
{
    double totalTarifaBase;
    double tarifaBase;
    totalTarifaBase = 0;
    for (int i=0;i < 50;i++)
    {
        tarifaBase = habitacion[i].getTarifaBase();
        totalTarifaBase = totalTarifaBase + tarifaBase;
    }
    return totalTarifaBase;
}

void Hotel::imprimeOcupacion()
{
    int numeroHabitacion;
    string nombreHuesped;
    double tarifaBase;
    double credito;
    double cargos;
    bool disponible;
    cout<<"Ocupacion en Hotel Aston"<<endl;
    for (int i=0;i < 50;i++)
    {
        if (habitacion[i].getDisponible() == false)
        {
            cout<<habitacion[i].toString();
        }
    }
}