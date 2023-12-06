//Evidencia 2: Proyecto integrador - Plataforma.h
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Declaracion de clase Plataforma"

#ifndef PLATAFORMA_H
#define PLATAFORMA_H

// Inclusión de clases que usa en sus métodos

#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

class Plataforma // Clase de constitución
{
    private:
        vector<Video*> video; // Vector que almacena videos, pueden ser películas o capítulos

    public:
        Plataforma(); // Constructor default que permite instanciar videos y meterlos en el vector video, por medio de lectura de archivo
        void leerCatalogo(); // Imprime en pantalla el catálogo de videos con sus atributos
        string calificarVideo(string ID); // Califica el video cuyo ID sea correspondiente
        void mostrarCalificacionMinima (); // Muestra aquellos videos que tengan la misma o mayor calificación minima
        void mostrarGenero (); // Muestra aquellos video con el mismo género
};

#endif