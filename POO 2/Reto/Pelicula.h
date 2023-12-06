//Evidencia 2: Proyecto integrador - Pelicul.h
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Declaracion de clase Pelicula"

#ifndef PELICULA_H
#define PELICULA_H
#include "video.h" //Incluye clase Padre

class Pelicula:public Video // Hereda de Video
{
    public:
        Pelicula(string ID, string nombre, string duracion, string genero, string tipo); // Constructor que recibe parametros para crear un opbjeto tipo Película

        friend ostream& operator<<(ostream& os,const Pelicula& p) // Sobrecarga operador << con objeto tipo Pelicula
        {
            if (p.calificacion > 0) //Verifica si la calificación es mayor a 0, si lo es imprime un string que incluye el atributo calificación
            {
                os<<p.ID<<","<<p.nombre<<","<<p.duracion<<","<<p.genero<<","<<p.calificacion<<endl; //Se incluye calificación
                return os;
            }
            else // si la calificación es menor a 0, imprime un string sin el atributo calificación
            {
                os<<p.ID<<","<<p.nombre<<","<<p.duracion<<","<<p.genero<<",SC"<<endl; // Se cambia Calificación por "SC"
                return os;
            }
        }

};

#endif