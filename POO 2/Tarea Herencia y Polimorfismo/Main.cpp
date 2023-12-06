#include <iostream>
#include "Habitacion.h"
#include "Hotel.h"
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    //Atributos 
    cout<<"Programa de actividad diagnostica: Hotel"<<endl;

    int numero;
    string nomHuesped;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    vector<Hotel*> hotel;
    

    //Empieza MENU
    int opcion;
    opcion = 0;
    while (opcion != 7)
    {
        cout<<"Bienvenido a Hotel Aston"<<endl<<endl<<"1. Crear Hotel"<<endl<<"2. Hacer CheckIn"<<endl<<"3. Hacer CheckOut"<<endl<<"4. Realizar cargos a habitacion"<<endl<<"5. Ingresos por tarifas"<<endl<<"6. Generar reporte de ocupacion"<<endl<<"7. Salir"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            if (hotel.size() == 1)
            {
                cout<<"Ya existe un hotel"<<endl;
            }
            else
            {
            bool validacion;
            int numeroJunior;
            int numeroSuite;
            int numeroDeluxe;
            cout<<"Cuantas habitaciones Junior desea crear? "<<endl;
            cin>>numeroJunior;
            cout<<"Cuantas habitaciones Suite desea crear? "<<endl;
            cin>>numeroSuite;
            cout<<"Cuantas habitaciones Deluxe desea crear? "<<endl;
            cin>>numeroDeluxe;
            hotel.push_back(new Hotel("Aston", numeroJunior, numeroSuite, numeroDeluxe));
            }
        }

        if (opcion == 2)
        {
            int validacion;
            cout<<"Nombre del huesped: "<<endl;
            cin>>nomHuesped;
            cout<<"Numero de adultos: "<<endl;
            cin>>adultos;
            cout<<"Nombre de ninos: "<<endl;
            cin>>infantes;
            cout<<"Credito: "<<endl;
            cin>>credito;
            validacion = hotel[0]->checkin(nomHuesped,adultos,infantes,credito);
            if (validacion == -1)
            {
                cout<<"No disponible"<<endl;
            }
            else
            {
                cout<<validacion<<endl;
            }
        }

        if (opcion == 3)
        {
            cout<<"Numero de habitacion: "<<endl;
            cin>>numero;
            if (numero > 99 && numero < hotel[0]->getNumHabitacionesJunior()+hotel[0]->getNumHabitacionesSuite()+hotel[0]->getNumHabitacionesDeluxe()+100)
            {
                bool validacion;
                validacion = hotel[0]->checkOut(numero);
                if (validacion == true)
                {
                    cout<<"Se ha realizado el CheckOut de manera exitosa"<<endl;
                }
                else
                {
                    cout<<"No se ha podido realizar el CheckOut"<<endl;
                }
            }
            else
            {
                cout<<"Numero de Habitacion invalida"<<endl;
            }
        }

        if (opcion == 4)
        {
            cout<<"Numero de habitacion: "<<endl;
            cin>>numero;
            if (numero > 99 && numero < hotel[0]->getNumHabitacionesJunior()+hotel[0]->getNumHabitacionesSuite()+hotel[0]->getNumHabitacionesDeluxe()+100)
            {
                cout<<"Cargo: "<<endl;
                cin>>cargo;
                bool validacion;
                validacion = hotel[0]->realizarCargosHabitacion(numero,cargo);
                if (validacion == false)
                {
                    cout<<"Habitacion no ocupada"<<endl;
                }
            }
            else
            {
                cout<<"Numero de Habitacion invalida"<<endl;
            }
        }

        if (opcion == 5)
        {
            double totalTarifaBase;
            totalTarifaBase = hotel[0]->getTotalXTarifaBase();
            cout<<"Tarifa total: "<<totalTarifaBase<<endl;
        }

        if (opcion == 6)
        {
            hotel[0]->imprimeOcupacion();
            cout<<endl;
        }
    }
    return 0;



}
