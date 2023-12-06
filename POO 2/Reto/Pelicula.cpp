//Evidencia 2: Proyecto integrador - Pelicula.cpp
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Implementación de clase Pelicula"

#include "Pelicula.h" // Incluye la clase Pelicula

Pelicula::Pelicula(string ID, string nombre, string duracion, string genero, string tipo) // Constructor de Película
{
    this -> ID = ID;
    this -> nombre = nombre;
    this -> duracion = duracion;
    this -> genero = genero;
    this -> calificacion = 0.0; // Calificación default
    this -> tipo = tipo;
}



