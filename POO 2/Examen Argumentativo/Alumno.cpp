//Francisco Javier Romo Juárez - A01643189
#include "Alumno.h"

Alumno::Alumno(int matricula, string nombre)
{
    this -> matricula = matricula;
    this -> nombre =  nombre;
}

bool Alumno::agregarMateria(Materia *a)
{
    for(int i=0; i<horario.size();i++)
    {
        if (a->getDia() != horario[i]->getDia())
        {
            if (a->getHora() != horario[i]->getHora())
            {
                if (a->getCosto() > 0)
                {
                    horario.push_back(new MateriaAcademica(a->clave, a->clave,a->getDia(),a->getHora(),a->getCalif(),a->unidadesAcademicas)
                }
            }
        }
    }
        
        
}

double Alumno::pagoColegiatura()
{
    double suma = 0;
    for(int i=0; i<horario.size();i++)
    {
        suma = horario[i]->getCosto() + suma;
    }
    return suma;
}





