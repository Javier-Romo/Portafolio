//Evidencia 2: Proyecto integrador - Plataforma.cpp
//Francisco Javier Romo Juárez - A01643189
//16/06/2023
// "Implementacion de clase Plataforma"


#include "Plataforma.h" // Incluye clase Plataforma
#include <sstream> // Permite hacer ciertas operaciones con strings
#include <iostream>
#include <cstdio> // Permite crear y manejar datos tipo char (carácteres individuales)


Plataforma::Plataforma() // Constructor default que permite instanciar videos y meterlos en el vector video, por medio de lectura de archivo
{
    string linea; // Linea del archivo
    string nombreArchivo = "videos.txt"; // Nombre del archivo en string
    string tipo, ID, nombre, duracion, genero, serie, episodio; // Declaración de variables de video en el método
    ifstream archivo(nombreArchivo.c_str()); // Se declara el archivo
    while (getline(archivo, linea)) // Lectura del arhivo
    {
        stringstream dato(linea); // Permite hacer operaciones de un stream con el string linea
        char separador = ','; // Delimitador de linea
        // Guarda el dato en la variable y lo hace por medio de guardar hasta que aparezca una ","
        getline(dato, tipo, separador); 
        getline(dato, ID, separador);
        getline(dato, nombre, separador);
        getline(dato, duracion, separador);
        getline(dato, genero, separador);
        int cantidadComas = 0; // Contador de ","
        for (int i=0;i < linea.length(); ++i)
        {
            cantidadComas += (linea[i] == ','); // Acumulador de ","
        }
        if (cantidadComas > 4) // Significa que es un capítulo
        {
            getline(dato, serie, separador);
            getline(dato, episodio, separador);
            video.push_back(new Capitulo(ID, nombre, duracion, genero, serie, episodio, tipo)); // Guarda un nuevo objeto Capítulo en el vector video
        }
        else // Significa que es una película
        {
            video.push_back(new Pelicula(ID, nombre, duracion, genero, tipo)); // Guarda un nuevo objeto Película en el vector video
        }

    }
}

void Plataforma::leerCatalogo() // Método que permite leer el catálogo de videos
{
    for (int i=0;i<video.size();i++)
    {
        string tipo = video[i]->getTipo(); //Recibe el atributo del tipo que hay en el objeto en esa posición del vector
        if (tipo == "p") // Tipo película
        {
            // Variables de película
            string ID, nombre, duracion, genero; 
            double calificacion; 
            // Se llama a los getters para obtener el atributo de la clase y pasarlo a las variables
            ID = video[i]->getID();
            nombre = video[i]->getNombre();
            duracion = video[i]->getDuracion();
            genero = video[i]->getGenero();
            calificacion = video[i]->getCalificacion();

            Pelicula pelicula(ID, nombre, duracion, genero, tipo); // Se crea un objeto Película con las variables
            pelicula.setCalificacion(calificacion); // Llama al método setCalificacion para ponerle la variable calificación al atributo calificacion en el objeto antes instanciado
            cout<<pelicula; // Usa la sobrecarga del operador << con Pelicula para imprimir la película en pantalla
        }

        else // Tipo capítulo
        {
            // Variables de capítulo
            string ID, nombre, duracion, genero, series, episodio;
            double calificacion;
            // Se llama a los getters para obtener el atributo de la clase y pasarlo a las variables
            ID = video[i]->getID();
            nombre = video[i]->getNombre();
            duracion = video[i]->getDuracion();
            genero = video[i]->getGenero();
            series = video[i]->getSerie();
            episodio = video[i]->getEpisodio();
            calificacion = video[i]->getCalificacion();

            Capitulo capitulo(ID, nombre, duracion, genero, series, episodio, tipo); // Se crea un objeto Capitulo con las variables
            capitulo.setCalificacion(calificacion); // Llama al método setCalificacion para ponerle la variable calificación al atributo calificacion en el objeto antes instanciado
            cout<<capitulo; // Usa la sobrecarga del operador << con Capitulo para imprimir la película en pantalla
        }
    }
}

string Plataforma::calificarVideo(string ID) // Calífica el video llamando un metodó de la clase video, recibe como parametro ID y compruebe que existe el video
{
    for (int i=0;i<video.size();i++)
    {
        if (video[i]->getID() == ID) // Comprueba que el video en esa posición tenga ese ID
        {
            cout<<"Ingrese la calificacion que desea poner al video (1 a 5): ";
            int calificacion; // Variable temporal de calificacion
            cin>>calificacion; 
            cout<<endl;
            while (calificacion < 1 || calificacion > 5) // Comprueba que la calificacion este entre 1 y 5 y no deja salir al usuario hasta que así sea
            {
                cout<<"Ingrese una calificacion valida"<<endl;
                cin>>calificacion; 
            }
            video[i]->calificarVideo(calificacion); // Manda la variable calificacion como parametro a el metódo calificarVideo
            return "Se ha calificado exitosamente";
        }
    }
    return "ID no existente"; // No existe un video con ese ID
}

void Plataforma::mostrarCalificacionMinima() //Muestra los videos a partir que tengan una calificación mayor o igual a la calificación minima
{
    int opcion; // Opción de tipo de video a desplegar
    double calificacion; // Calificación minima
    cout<<"Ingrese el tipo de video: (Pelicula = 1, Serie = 2, Ambos = 3)"<<endl;
    cin>>opcion;
    while (opcion < 1 || opcion > 3) // Valida que la opción este entre las opciones consideradas y no deja seguir al usuario hasta que así sea
    {
        cout<<"La opcion esta fuera del rango, favor de ingresar una opcion correcta: "<<endl;
        cin>>opcion;
    }

    cout<<"Calificacion minima para el video: "<<endl;
    cin>>calificacion;

    for (int i=0;i < video.size();i++)
    {
        if (opcion == 1) // Mostrar solo Películas
        {
            if (video[i]->getTipo() == "p") // Valida que el tipo de video en esa posición del vector sea de tipo Pelicula
            {
                if (video[i]->getCalificacion() >= calificacion && video[i]->getCalificacion() != 0) /* Valida que exista alguna calificación previa y que la película tenga
                una calificación mayor o igual a la introducida por el usuario*/
                {
                    cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getCalificacion()<<endl; // Imprime con cierto formato datos de la película
                }
            }
        }

        if (opcion == 2) // Mostrar solo Capítulos
        {
            if (video[i]->getTipo() == "c") // Valida que el tipo de video en esa posición del vector sea de tipo Capitulo
            {
                if (video[i]->getCalificacion() >= calificacion && video[i]->getCalificacion() != 0) /* Valida que exista alguna calificación previa y que el capítulo tenga
                una calificación mayor o igual a la introducida por el usuario*/
                {
                    cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getCalificacion()<<endl; // Imprime con cierto formato datos del capítulo
                }
            }
        }

        if (opcion == 3) // Mostrar Películas y Capítulos
        {
            if (video[i]->getCalificacion() >= calificacion && video[i]->getCalificacion() != 0) /* Valida que exista alguna calificación previa y que la película o caítulo tenga
                una calificación mayor o igual a la introducida por el usuario*/
            {
                cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getCalificacion()<<endl; // Imprime con cierto formato datos de la película o capítulo
            }
        }
    }
}

void Plataforma::mostrarGenero() //Muestra los videos que tengan un cierto género
{
    int opcion; // Opción de tipo de video a desplegar
    string genero; // Género a mostrar
    cout<<"Ingrese el tipo de video: (Pelicula = 1, Serie = 2, Ambos = 3)"<<endl;
    cin>>opcion;
    while (opcion < 1 || opcion > 3) // Valida que la opción este entre las opciones consideradas y no deja seguir al usuario hasta que así sea
    {
        cout<<"La opcion esta fuera del rango, favor de ingresar una opcion correcta: "<<endl;
        cin>>opcion;
    }

    cout<<"Genero que desea: "<<endl;
    cin>>genero;
    cout<<endl;

    for (int i=0;i < video.size();i++)
    {
        if (opcion == 1) // Mostrar solo Películas
        {
            if (video[i]->getTipo() == "p") // Valida que el tipo de video en esa posición del vector sea de tipo Pelicula
            {
                if (video[i]->getGenero() == genero) // Valida que el generó de la película sea el mismo que introdujo el usuario
                {
                    if (video[i]->getCalificacion() == 0) // No sea calificado el video por lo que su calificación es "SC"
                    {
                        cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getGenero()<<","<<"SC"<<endl; // Imprime con cierto formato datos de la película
                    }
                    else // Si tiene una calificación
                    {
                        cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getGenero()<<","<<video[i]->getCalificacion()<<endl; /* Imprime con cierto formato datos
                        de la película*/ 
                    }
                }
            }
        }

        if (opcion == 2) // Mostrar solo Capítulos
        {
            if (video[i]->getTipo() == "c") // Valida que el tipo de video en esa posición del vector sea de tipo Capitulo
            {
                if (video[i]->getGenero() == genero) // Valida que el generó del capítulo sea el mismo que introdujo el usuario
                {
                    if (video[i]->getCalificacion() == 0) // No sea calificado el video por lo que su calificación es "SC"
                    {
                        cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getGenero()<<","<<"SC"<<endl; // Imprime con cierto formato datos de la película
                    }
                    else
                    {
                        cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getGenero()<<","<<video[i]->getCalificacion()<<endl; /* Imprime con cierto formato datos
                        de la película*/ 
                    }
                }
            }
        }

        if (opcion == 3) // Mostrar Películas y Capítulos
        {
            if (video[i]->getGenero() == genero) // Valida que el generó de la película o el capítulo sea el mismo que introdujo el usuario
                {
                    if (video[i]->getCalificacion() == 0) // No sea calificado el video por lo que su calificación es "SC"
                    {
                        cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getGenero()<<","<<"SC"<<endl; // Imprime con cierto formato datos de la película o capítulo
                    }
                    else
                    {
                        cout<<video[i]->getID()<<","<<video[i]->getNombre()<<","<<video[i]->getGenero()<<","<<video[i]->getCalificacion()<<endl; /* Imprime con cierto formato datos
                        de la película o capítulo*/ 
                    }
                }
        }
    }
}


