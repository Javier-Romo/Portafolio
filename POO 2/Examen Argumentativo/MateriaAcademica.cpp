//Francisco Javier Romo Juárez - A01643189
#include "MateriaAcademica.h"


MateriaAcademica::MateriaAcademica(string clave, string nombre, string dia, int hora, int calif, int unidadesAcademicas)
{
    this -> clave = clave;
    this -> nombre = nombre;
    this -> dia = dia;
    this -> hora = hora;
    this -> calif = calif;
    this -> unidadesAcademicas = unidadesAcademicas;
    if (this -> hora >6 && this -> hora < 20)
    {
        this -> hora = 7;
    }
    if (this -> hora >0 && this -> hora < 101)
    {
        this -> calif = 1;
    }
}

MateriaAcademica::MateriaAcademica(string clave, string nombre, string dia, int hora, int calif, int unidadesAcademicas)
{
    this -> clave = clave;
    this -> nombre = nombre;
    this -> dia = "lunes";
    this -> hora = 7;
    this -> calif = calif;
    this -> unidadesAcademicas = unidadesAcademicas;
}

double MateriaAcademica::getCosto()
{
    return this -> unidadesAcademicas*costoUdAcademica;
}

int MateriaAcademica::getUnidadesAcademicas()
{
    return unidadesAcademicas;
}