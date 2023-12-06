//Evidencia 2: Proyecto integrador - Capitulo.cpp
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Implementación de clase Capitulo"

#include "Capitulo.h" // Incluye la clase Capitulo

Capitulo::Capitulo(string ID, string nombre, string duracion, string genero, string serie, string episodio, string tipo) // Constructor de Capitulo
{
    this -> ID = ID;
    this -> nombre = nombre;
    this -> duracion = duracion;
    this -> genero = genero;
    this -> serie = serie;
    this -> episodio = episodio;
    this -> calificacion = 0.0; // Calificación default
    this -> tipo = tipo;
}
