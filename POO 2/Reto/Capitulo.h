//Evidencia 2: Proyecto integrador - Capitulo.h
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Declaracion de clase Capitulo"

#ifndef CAPITULO_H
#define CAPITULO_H
#include "Video.h" //Incluye clase Padre

class Capitulo:public Video // Hereda de Video
{
    public:
        Capitulo(string ID, string nombre, string duracion, string genero, string serie, string episodio, string tipo); // Constructor que recibe parametros para crear un opbjeto tipo Capitulo

        friend ostream& operator<<(ostream& os,const Capitulo& c) // Sobrecarga operador << con objeto tipo Capitulo
        {
            if (c.calificacion > 0) //Verifica si la calificación es mayor a 0, si lo es imprime un string que incluye el atributo calificación
            {
                os<<c.ID<<","<<c.nombre<<","<<c.duracion<<","<<c.genero<<","<<c.serie<<","<<c.episodio<<","<<c.calificacion<<endl; //Se incluye calificación
                return os;
            }
            else // si la calificación es menor a 0, imprime un string sin el atributo calificación
            {
                os<<c.ID<<","<<c.nombre<<","<<c.duracion<<","<<c.genero<<","<<c.serie<<","<<c.episodio<<",SC"<<endl; // Se cambia Calificación por "SC"
                return os;
            }

        }
};

#endif