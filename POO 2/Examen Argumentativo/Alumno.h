//Francisco Javier Romo Juárez - A01643189
#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string.h>
#include <vector>
#include "Materia.h"
#include "MateriaAcademica.h"

using namespace std;

class Alumno
{
    protected:
        int matricula;
        string nombre;
        vector<Materia*> horario;

    private:
        Alumno(int matricula, string nombre);
        bool agregarMateria(Materia *a);
        double pagoColegiatura();
        double promedioAcademico();
        
};

#endif