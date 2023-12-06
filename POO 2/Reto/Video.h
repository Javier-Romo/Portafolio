//Evidencia 2: Proyecto integrador - Video.h
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Declaracion de clase Video"

#ifndef VIDEOS_H
#define VIDEOS_H

// Incluye librerias que se usan en sus metodos y otras clases

#include <string.h>
#include <iostream>
#include <vector> // Permite crear y manejar daos tipo vector
#include <fstream> // Permite crear y manejar datos tipo fstream (archivo)
#include <cstdio> // Permite crear y manejar datos tipo char (carácteres individuales)

using namespace std;

class Video
{
    protected:
        string ID; // Numero Identificador del video
        string nombre; // Nombre con el que se titula el video
        string duracion; // Longitud en minutos del video
        string genero; // Categoría del video
        string serie; // Nombre de la serie con su temporada del Capítulo
        string episodio; // Número del capítulo
        double calificacion; // Rating del capítulo
        vector <double> calificaciones; // Vector que almacena todas las calificaciones que se le han dado al video
        string tipo; // Tipo de video (Película o video)

    public:
        // Getters y setters de video
        string getID(); 
        string getNombre();
        string getDuracion();
        string getGenero();
        string getSerie();
        string getEpisodio();
        string getTipo();
        double getCalificacion();
        void setCalificacion(double calificacion);
        // Otros métodos de video
        void calificarVideo(int calificacion); // Recibe una calificación del usuario y saca la calificación promedio del video.
};

#endif