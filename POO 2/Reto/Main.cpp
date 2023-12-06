// Evidencia 2: Proyecto integrador - Main.cpp
// Francisco Javier Romo Juárez - A01643189
// 16/06/2023
// "Implementacion de las distintas clases en un main"

//LIBRERÍAS

#include "Plataforma.h" // Clase de constitución llama a video
#include "Video.h" // Clase Padre
#include "Pelicula.h" // Clase hija de video
#include "Capitulo.h" // Clase hija de video
#include <iostream>

using namespace std;

int main() 
{
    Plataforma plataforma; //Se crea un objeto plataforma

    //Menú

    int opcion = 0; //Opción de menú
    while (opcion != 5) //opción 5 = Salir
    {   
        // Lógo de la plataforma
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl<<endl;

        cout<<"---------- --------- ----------- ----------  -----      ----    ----    ----------        ------    "<<endl;
        cout<<"---------- --------- ----------- ----   ---- -----      ----    ----   ----------         ------    "<<endl;
        cout<<"   ----    ----      ----        ----   ---- -----      ----    ----  ----------      --------------"<<endl;
        cout<<"   ----    --------- ----        ----------  -----      ----    ---- ----------       --------------"<<endl;
        cout<<"   ----    ----      ----        ------      -----      ----    ----  ----------          ------    "<<endl;
        cout<<"   ----    --------- ----------- ------      ---------- ------------   ----------         ------    "<<endl;
        cout<<"   ----    --------- ----------- ------      ---------- ------------    ----------                  "<<endl<<endl;

        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        
        
        cout<<endl;
        cout<<"1. Mostrar todo el catalogo con calificaciones."<<endl<<"2. Calificar un video"<<endl<<"3. Mostrar peliculas o capitulos con una calificacion minima determinada"<<endl<<"4. Mostrar peliculas o capitulos de un cierto genero."<<endl<<"5. Salir"<<endl;
        cin>>opcion; 
        cout<<endl;

        if (opcion == 1) //Mostrar cátalogo
        {
            plataforma.leerCatalogo(); //Se llama a el método leerCatalogo 
            cout<<endl;
        }

        if (opcion == 2) //Calificar video
        {
            string ID; // ID proporcionado por el usuario
            cout<<"Ingrese el ID del video que desea calificar:";
            cin>>ID;
            cout<<plataforma.calificarVideo(ID)<<endl; // Se llama al método calificarVideo
        }
        
        if (opcion == 3) // Mostrar minima calificacion
        {
            plataforma.mostrarCalificacionMinima(); // Se llama al método mostrarCalficacionMinima
        }

        if (opcion == 4) // Mostrar genero
        {
            plataforma.mostrarGenero(); // Se llama al método mostrarGenero
        }
    }
    return 0; //Fin del main
}