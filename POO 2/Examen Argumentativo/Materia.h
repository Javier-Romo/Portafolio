//Francisco Javier Romo Juárez - A01643189
#ifndef MATERIA_H
#define MATERIA_H
#include <string.h>
#include <iostream>

using namespace std;

class Materia
{
    protected:
        string clave;
        string nombre;
        string dia;
        int hora;
        int calif;
    public:
        Materia();
        Materia(string clave, string nombre, string dia, int hora, int calif);
        Materia(string clave, string nombre, int calif);
        string getClave();
        string getNombre();
        string getDia();
        int getHora();
        int getCalif();
        double getCosto();
        string toString();
        int getGetUnidadesAcademicas();
};

#endif