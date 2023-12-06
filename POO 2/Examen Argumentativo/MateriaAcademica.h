//Francisco Javier Romo Juárez - A01643189
#ifndef MATERIACADEMICA_H
#define MATERIACADEMICA_H
#include "Materia.h"

class MateriaAcademica:public Materia
{
    private:
        int unidadesAcademicas;
        const double costoUdAcademica=6500.0;
    public:
        MateriaAcademica(string clave, string nombre, string dia, int hora, int calif, int unidadesAcademicas);
        double getCosto();
        int getUnidadesAcademicas(Materia*a);
        

};

#endif