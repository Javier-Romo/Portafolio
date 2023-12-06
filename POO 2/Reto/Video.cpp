//Evidencia 2: Proyecto integrador - Video.cpp
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Implementación de clase Video"

#include "Video.h" // Incluye la clase video
#include <sstream> // Permite hacer ciertas operaciones con strings
#include <iostream>
#include <cstdio> // Permite crear y manejar datos tipo char (carácteres individuales)

using namespace std;

// Getters de Video
string Video::getID()
{
    return ID;
}

string Video::getNombre()
{
    return nombre;
}

string Video::getDuracion()
{
    return duracion;
}

string Video::getGenero()
{
    return genero;
}

string Video::getSerie()
{
    return serie;
}

string Video::getEpisodio()
{
    return episodio;
}

string Video::getTipo()
{
    return tipo;
}

double Video::getCalificacion()
{
    return calificacion;
}

// Setters de Video
void Video::setCalificacion(double calificacion)
{
    this -> calificacion = calificacion;
}
// Otros métodos de video
void Video::calificarVideo(int calificacion) //Calcúla la calificación promedio del video teniendo en cuenta una calificación nueva como parámetro y las calificaciones anteriores dadas
{
    calificaciones.push_back(calificacion); // Introduce la calificación nueva al vector calificaciones
    double suma = 0.0; // Acumulador suma
    for (int i=0;i < calificaciones.size();i++)
    {
        suma = suma + calificaciones[i]; // Va sumando las calificaciones del vector respecto a su posición

    }
    this -> calificacion = suma / calificaciones.size(); // Introduce al atributo calificacion un valor que representa la suma de sus calificaciones entre el número de calificaciones en el vector
}

