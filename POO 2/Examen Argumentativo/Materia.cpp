//Francisco Javier Romo Juárez - A01643189
#include "Materia.h"

Materia::Materia(string clave, string nombre, string dia, int hora, int calif)
{
    this -> clave = clave;
    this -> nombre = nombre;
    this -> dia = dia;
    this -> hora = hora;
    this -> calif = calif;
    if (this -> hora >6 && this -> hora < 20)
    {
        this -> hora = 7;
    }
    if (this -> hora >0 && this -> hora < 101)
    {
        this -> calif = 1;
    }
}

Materia::Materia(string clave, string nombre, int calif)
{
    this -> clave = clave;
    this -> nombre = nombre;
    this -> dia = "lunes";
    this -> hora = 7;
    this -> calif = calif;
}

string Materia::getClave()
{
    return clave;
}

string Materia::getNombre()
{
    return nombre;
}

string Materia::getDia()
{
    return dia;
}

int Materia::getHora()
{
    return hora;
}

int Materia::getCalif()
{
    return calif;
}

double Materia::getCosto()
{
    return 0;
}

string Materia::toString()
{
    return clave+","+nombre+","+dia+","+to_string(hora)+":00,"+to_string(calif);
}

int Materia::getGetUnidadesAcademicas(Materia *a)
{
    return  ;
}