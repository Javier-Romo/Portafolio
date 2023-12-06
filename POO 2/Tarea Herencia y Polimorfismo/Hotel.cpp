#include "Hotel.h"
#include <iostream>
#include "Habitacion.h"
using namespace std;

Hotel::Hotel(string nombreHotel, int numHabitacionesJunior, int numHabitacionesSuite, int numHabitacionesDeluxe)
{
    this->nombreHotel = nombreHotel;
    this->numHabitacionesJunior = numHabitacionesJunior;
    this->numHabitacionesSuite = numHabitacionesSuite;
    this->numHabitacionesDeluxe = numHabitacionesDeluxe;
    int contador;
    for (int i=0;i < this->numHabitacionesJunior;i++)
    {
        habitaciones.push_back(new HabitacionJunior(i));
    }
    contador = this->numHabitacionesJunior;
    for (int i=contador;i < this->numHabitacionesSuite+contador;i++)
    {
        habitaciones.push_back(new HabitacionSuite(i));
        
    }
    contador = this->numHabitacionesJunior+this->numHabitacionesSuite;
    for (int i=contador;i < this->numHabitacionesDeluxe+contador;i++)
    {
        habitaciones.push_back(new HabitacionDeluxe(i));
        
    }

}

int Hotel::getNumHabitacionesJunior()
{
    return numHabitacionesJunior;
}

int Hotel::getNumHabitacionesSuite()
{
    return numHabitacionesSuite;
}
int Hotel::getNumHabitacionesDeluxe()
{
    return numHabitacionesDeluxe;
}

string Hotel::getNombreHotel()
{
    return nombreHotel;
}

int Hotel::checkin(string nuevoNombreHuesped,int nuevoAdultos,int nuevoInfantes,double nuevoCredito)
{
    int numHabitacion;
    int contador;
    int opcion;
    cout<<"Que tipo de habitacion desea? Junior(1) Suite(2) Deluxe(3)"<<endl;
    cin>>opcion;
    if (opcion == 1)
    {
        for (int i=0;i < numHabitacionesJunior;i++)
        {
            if (habitaciones[i]->getDisponible() == true)
            {
                if (habitaciones[i]->checkIn(nuevoNombreHuesped,nuevoAdultos,nuevoInfantes,nuevoCredito) == true)
                {
                    numHabitacion = habitaciones[i]->getNumero();
                    return numHabitacion;
                }
            }
        }
        if (nuevoAdultos+nuevoInfantes > 4)
        {
            cout<<"Intente con otro tipo de habitacion"<<endl;
        }
    }
    if (opcion == 2)
    {   
        contador = numHabitacionesJunior-1;
        for (int i=contador;i < numHabitacionesSuite+contador;i++)
        {
            if (habitaciones[i]->getDisponible() == true)
            {
                if (habitaciones[i]->checkIn(nuevoNombreHuesped,nuevoAdultos,nuevoInfantes,nuevoCredito) == true)
                {
                    numHabitacion = habitaciones[i]->getNumero();
                    return numHabitacion;
                }
            }
        }
        if (nuevoAdultos+nuevoInfantes > 6)
        {
            cout<<"Intente con otro tipo de habitacion"<<endl;
        }
    }
    if (opcion == 3)
    {
        contador = numHabitacionesJunior+numHabitacionesSuite-1;
        for (int i=contador;i < numHabitacionesSuite+contador;i++)
        {
            if (habitaciones[i]->getDisponible() == true)
            {
                if (habitaciones[i]->checkIn(nuevoNombreHuesped,nuevoAdultos,nuevoInfantes,nuevoCredito) == true)
                {
                    numHabitacion = habitaciones[i]->getNumero();
                    return numHabitacion;
                }
            }
        }
        if (nuevoAdultos+nuevoInfantes > 8)
        {
            cout<<"Haga reservaciones separadas"<<endl;
        }
    }


    return -1;


}

bool Hotel::checkOut(int nuevoNumeroHabitacion)
{
    if (nuevoNumeroHabitacion > 99 && nuevoNumeroHabitacion < 99+habitaciones.size())
    {
        bool validacion;
        validacion = habitaciones[nuevoNumeroHabitacion - 100]->checkOut();
        if (validacion == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Hotel::realizarCargosHabitacion(int nuevoNumeroHabitacion,double nuevoCargo)
{
    if (habitaciones[nuevoNumeroHabitacion - 100]->getDisponible() == false)
    {
        bool validacion;
        validacion = habitaciones[nuevoNumeroHabitacion - 100]->realizarCargo(nuevoCargo);
        if (validacion == true)
        {
            cout<<"Se ha realizado el cargo exitosamente"<<endl;
        }
        else
        {
            cout<<"No se ha podido realizar el cargo"<<endl;
        }
        return true;
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
    int contador;
    for (int i=0;i < numHabitacionesJunior;i++)
    {
        tarifaBase = habitaciones[i]->getTarifaBase();
        totalTarifaBase = totalTarifaBase + tarifaBase;
    }
    contador = this->numHabitacionesJunior;
    for (int i=contador;i < numHabitacionesSuite+contador;i++)
    {
        tarifaBase = habitaciones[i]->getTarifaBase();
        totalTarifaBase = totalTarifaBase + tarifaBase;
    }
    contador = this->numHabitacionesJunior+this->numHabitacionesSuite;
    for (int i=contador;i < numHabitacionesDeluxe+contador;i++)
    {
        tarifaBase = habitaciones[i]->getTarifaBase();
        totalTarifaBase = totalTarifaBase + tarifaBase;
    }
    return totalTarifaBase;
}

void Hotel::imprimeOcupacion()
{
    cout<<"Ocupacion en Hotel Aston"<<endl<<endl;
    int contador;
    for (int i=0;i < numHabitacionesJunior;i++)
    {
        if (habitaciones[i]->getDisponible() == false)
        {
            cout<<habitaciones[i]->toString();
        }
        
    }
    contador = this->numHabitacionesJunior;
    for (int i=contador;i < numHabitacionesSuite+contador;i++)
    {
        if (habitaciones[i]->getDisponible() == false)
        {
            cout<<habitaciones[i]->toString();
        }
        
    }
    contador = this->numHabitacionesSuite+this->numHabitacionesJunior;
    for (int i=contador;i < numHabitacionesDeluxe+contador;i++)
    {
        if (habitaciones[i]->getDisponible() == false)
        {
            cout<<habitaciones[i]->toString();
        }
    }
}



