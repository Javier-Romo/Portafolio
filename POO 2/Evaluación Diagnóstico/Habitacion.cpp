#include "Habitacion.h"
#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

Habitacion::Habitacion()
    {
        //CONSTRUCTOR DEFAULT
        numero = 0;
        nombre= "";
        adultos = 0;
        infantes = 0;
        credito = 0;
        cargo = 0;
        disponible = true;
    }

Habitacion::Habitacion(int nuevoNumero)
{
     //CONSTRUCTOR NUM HABITACION
    numero = nuevoNumero;
    disponible = true;
}

int Habitacion::getNumero()
{
    return numero;
}

string Habitacion::getNombre()
{
    return nombre;
}

int Habitacion::getAdultos()
{
    return adultos;
}

int Habitacion::getInfantes()
{
    return infantes;
}

double Habitacion::getCredito()
{
    return credito;
}

double Habitacion::getCargo()
{
    return cargo;
}

bool Habitacion::getDisponible()
{
    return disponible;
}

void Habitacion::setGlobal(int nuevoNumero,string nuevoNombre,int nuevoAdultos,int nuevoInfantes,double nuevoCredito,double nuevoCargo,bool nuevoDisponible)
{
    numero = nuevoNumero;
    nombre = nuevoNombre;
    adultos = nuevoAdultos;
    infantes = nuevoInfantes;
    credito = nuevoCredito;
    cargo = nuevoCargo;
    disponible = nuevoDisponible;
}

bool Habitacion::checkIn(string nuevoNombre,int nuevoAdultos,int nuevoInfantes,double nuevoCredito)
{
    if (disponible == true)
    {
        nombre = nuevoNombre;
        adultos = nuevoAdultos;
        infantes = nuevoInfantes;
        credito = nuevoCredito;
        cargo = 0;
        disponible = false;
        return true;
    }
    else
    {
        return false;
    }
}

bool Habitacion::checkOut()
{
    if (disponible == false)
    {
        nombre = "";
        adultos = 0;
        infantes = 0;
        cargo = 0;
        credito = 0;
        disponible = true;
        return true;
    }
    else
    {
        return false;
    }
}

double Habitacion::getTarifaBase()
{
    int tarifaBase;
    tarifaBase = (450*adultos) + (150*infantes);
    return tarifaBase;
}

bool Habitacion::realizarCargo(double nuevoCargo)
{
    if (nuevoCargo > 0 && (nuevoCargo + cargo) <= credito)
    {
        cargo = nuevoCargo + cargo;
        return true;
    }
    else
    {
        return false;
    }
}

string Habitacion::toString()
{
    ostringstream oracion;
    oracion <<numero<<",Huesped:"<<nombre<<",Tarifa Base:"<<getTarifaBase()<<",Credito:"<<credito<<",Cargos:"<<cargo<<",Habitacion Deluxe"<<endl;
    return oracion.str();
}